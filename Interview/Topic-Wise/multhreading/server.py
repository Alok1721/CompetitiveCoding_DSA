import threading
import cv2
import socket
import struct
import pickle
import time
import zlib

class Server:
    def __init__(self, multicast_group='224.1.1.1', multicast_port=5007, server_port=12345):
        # Multicast setup for video streaming
        self.multicast_group = multicast_group
        self.multicast_port = multicast_port
        self.multicast_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
        self.multicast_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.multicast_socket.setsockopt(socket.IPPROTO_IP, socket.IP_MULTICAST_TTL, 32)
        # Increase send buffer size
        self.multicast_socket.setsockopt(socket.SOL_SOCKET, socket.SO_SNDBUF, 1024 * 1024)  # 1MB buffer

        # TCP server for client messaging
        self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.server_socket.bind(('0.0.0.0', server_port))
        self.server_socket.listen(5)
        self.clients = []
        self.addresses = []
        self.running = True

        # OpenCV video capture
        self.cap = cv2.VideoCapture(0)
        if not self.cap.isOpened():
            print("Error: Could not open camera.")
            exit()

    def start_video_stream(self):
        """Stream video frames to the multicast group."""
        print("Starting video stream to multicast group", self.multicast_group)
        while self.running:
            ret, frame = self.cap.read()
            if not ret:
                print("Failed to capture frame")
                break

            # Resize frame to reduce size
            frame = cv2.resize(frame, (320, 240))  # Smaller resolution
            # Encode frame as JPEG to reduce size
            encode_param = [int(cv2.IMWRITE_JPEG_QUALITY), 70]  # Quality 70 (0-100)
            result, encoded_frame = cv2.imencode('.jpg', frame, encode_param)
            if not result:
                print("Failed to encode frame")
                continue

            # Compress serialized data
            data = pickle.dumps(encoded_frame)
            compressed_data = zlib.compress(data)
            # Check if data size is reasonable
            if len(compressed_data) > 65000:
                print(f"Warning: Compressed frame size {len(compressed_data)} bytes is too large, skipping")
                continue

            # Send frame size first
            message_size = struct.pack("!L", len(compressed_data))
            try:
                self.multicast_socket.sendto(message_size, (self.multicast_group, self.multicast_port))
                self.multicast_socket.sendto(compressed_data, (self.multicast_group, self.multicast_port))
            except Exception as e:
                print(f"Error sending frame: {e}")
            time.sleep(0.03)  # ~30 FPS

        self.cap.release()

    def handle_client(self, client_socket, address):
        """Handle client messages in a separate thread."""
        print(f"Handling client {address}")
        try:
            while self.running:
                data = client_socket.recv(1024).decode()
                if not data:
                    break
                print(f"Message from {address}: {data}")
                client_socket.send(f"Server received: {data}".encode())
        except Exception as e:
            print(f"Error with client {address}: {e}")
        finally:
            print(f"Client {address} disconnected")
            self.clients.remove(client_socket)
            self.addresses.remove(address)
            client_socket.close()

    def accept_clients(self):
        """Accept incoming client connections and start a thread for each."""
        print("Server started, waiting for connections...")
        while self.running:
            try:
                self.server_socket.settimeout(1.0)
                client_socket, address = self.server_socket.accept()
                self.clients.append(client_socket)
                self.addresses.append(address)
                print(f"Connection from {address}")
                client_socket.send("Welcome to the server".encode())
                client_thread = threading.Thread(target=self.handle_client, args=(client_socket, address))
                client_thread.start()
            except socket.timeout:
                continue
            except Exception as e:
                print(f"Error accepting client: {e}")

    def start(self):
        """Start the server: video streaming and client handling."""
        video_thread = threading.Thread(target=self.start_video_stream)
        video_thread.start()
        self.accept_clients()

    def stop(self):
        """Stop the server and clean up."""
        self.running = False
        self.multicast_socket.close()
        self.server_socket.close()
        self.cap.release()

if __name__ == "__main__":
    server = Server()
    try:
        server.start()
    except KeyboardInterrupt:
        print("Shutting down server...")
        server.stop()