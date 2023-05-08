from socket import *

server_port = 12000
server_IP = 'localhost'   #127.0.0.1

# create a socket object
client_sock = socket(AF_INET, SOCK_DGRAM)

# send a message to the server
message =  input('Input lowercase sentence:')
client_sock.sendto(message.encode(), (server_IP, server_port))

# receive the server's response
modified_message, address = client_sock.recvfrom(1024)   # buffer size is 1024 bytes
print(f"Received message: {modified_message.decode()}")

# close the socket
client_sock.close()