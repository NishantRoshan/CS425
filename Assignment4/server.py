from socket import *

server_port = 12000
server_IP = 'localhost'   #127.0.0.1

# create a socket object
server_sock = socket(AF_INET,SOCK_DGRAM)

# bind the socket to a specific address and port
server_sock.bind(server_IP,server_port)

print(f"Server listening on {server_IP}:{server_port}")

while True:
    #receive data from client
    message, address = server_sock.recvfrom(1024)   # buffer size is 1024 bytes
    print(f"Connection from {address} is established")
    print(f"Received message:{message.decode()}")
    
    modified_message = message.decode().upper()
    
    # send a response back to the client
    server_sock.sendto(modified_message.encode(),address)
