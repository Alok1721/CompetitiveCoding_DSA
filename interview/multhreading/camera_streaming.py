# #stream the opencv camera using multicast ,and receive the stream on user , each user will have own thread to talk with server and recieve the video and send message to server also
# #server code
# import threading
# import cv2
# import socket
# import struct
# import pickle
# import time

# class Server():
#     def __init__(self):
#         self.server_socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
#         self.server_socket.bind(("0.0.0.0",12345))
#         self.server_socket.listen(5)
#         self.clients=[]
#         self.address=[]
#         self.server_address="0.0.0.0"
#         self.server_port=12345
#     def start(self):
#         print("Server started")
#         while True:
#             client, address=self.server_socket.accept()
#             self.clients.append(client)
#             self.address.append(address)
#             print(f"Connection from {address}")
#             client.send("Welcome to the server".encode())
#             client.close()
#     def receive(self):
#         while True:
#             client, address=self.server_socket.accept()
#             self.clients.append(client)
#             self.address.append(address)
#             print(f"Connection from {address}")
#             client.send("Welcome to the server".encode())
#             client.close()
#     def __main__():
#         server=Server()
#         server.start()
#         server.receive()
# if __name__=="__main__":
#     __main__()

#client code
