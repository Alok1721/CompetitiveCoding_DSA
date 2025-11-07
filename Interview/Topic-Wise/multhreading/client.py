import threading
import cv2
import socket
import struct
import pickle
import time
import zlib
import numpy as np

class Client:
    def __init__(self, server_address='localhost', server_port=12345, multicast_group='224.1.1.1', multicast_port=5007):
        # TCP socket for messaging
        self.client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.client_socket.connect((server_address, server_port))
        self.running = True

        # Multicast socket for video streaming
        self.multicast_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
        self.multicast_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        # Increase receive buffer size
        self.multicast_socket.setsockopt(socket.SOL_SOCKET, socket.SO_RCVBUF, 1024 * 1024)  # 1MB buffer
        self.multicast_socket.bind(('', multicast_port))
        # Join multicast group
        mreq = struct.pack("4sL", socket.inet_aton(multicast_group), socket.INADDR_ANY)
        self.multicast_socket.setsockopt(socket.IPPROTO_IP, socket.IP_ADD_MEMBERSHIP, mreq)

    def receive_video(self):
        """Receive and display video stream from multicast group."""
        print("Starting video stream receiver...")
        cv2.namedWindow("Video Stream", cv2.WINDOW_AUTOSIZE)
        while self.running:
            try:
                # Receive frame size
                data, _ = self.multicast_socket.recvfrom(4)
                if not data:
                    continue
                size = struct.unpack("!L", data)[0]
                # Receive compressed frame data
                data, _ = self.multicast_socket.recvfrom(size)
                # Decompress and deserialize
                decompressed_data = zlib.decompress(data)
                encoded_frame = pickle.loads(decompressed_data)
                # Decode JPEG frame
                frame = cv2.imdecode(np.frombuffer(encoded_frame, dtype=np.uint8), cv2.IMREAD_COLOR)
                if frame is None:
                    print("Failed to decode frame")
                    continue
                # Display frame
                cv2.imshow("Video Stream", frame)
                if cv2.waitKey(1) & 0xFF == ord('q'):
                    break
            except Exception as e:
                print(f"Error receiving video: {e}")
                break
        cv2.destroyAllWindows()

    def handle_messaging(self):
        """Handle sending and receiving messages with the server."""
        print(self.client_socket.recv(1024).decode())
        while self.running:
            try:
                message = input("Enter message (or 'quit' to exit): ")
                if message.lower() == 'quit':
                    break
                self.client_socket.send(message.encode())
                response = self.client_socket.recv(1024).decode()
                print(f"Server response: {response}")
            except Exception as e:
                print(f"Error in messaging: {e}")
                break

    def start(self):
        """Start the client: video streaming and messaging."""
        video_thread = threading.Thread(target=self.receive_video)
        video_thread.start()
        self.handle_messaging()
        self.running = False
        self.client_socket.close()
        self.multicast_socket.close()
        cv2.destroyAllWindows()

if __name__ == "__main__":
    client = Client()
    try:
        client.start()
    except KeyboardInterrupt:
        print("Shutting down client...")
        client.running = False
        client.client_socket.close()
        client.multicast_socket.close()
        cv2.destroyAllWindows()