#!/usr/bin/env python3

import socket
import threading

HOST = "127.0.0.1" #localhost
#HOST = "" #localhost
PORT = 65432

#SOCK_STREAM uses TCP by default
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))
server.listen()

#setting up lists
clients = []
usernames = []

#message function
def broadcast(message):
    for client in clients:
        client.send(message)

#handling client connections
def handle(client):
    while True:
        try:
            message = client.recv(1024)
            broadcast(message)
        except:
            index = clients.index(client)
            clients.remove(client)
            client.close()
            username = usernames[index]
            usernames.remove(username)
            broadcast(f"{username} left the chat".encode("ascii"))
            break

def receive():
    while True:
        client, address = server.accept()
        print(f"Connected with {str(address)}")
        
        client.send("USERNAME".encode("ascii"))
        username = client.recv(1024).decode("ascii")
        usernames.append(username)
        clients.append(client)
        
        print(f"Username of the client is {username}")
        broadcast(f"{username} joined the chat".encode("ascii"))
        client.send("Connected to the server".encode("ascii"))
        
        thread = threading.Thread(target=handle, args=(client,))
        thread.start()

print("Server is listening...")
receive()
