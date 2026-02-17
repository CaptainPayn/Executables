#!/usr/bin/env python3

import socket
import threading
import argparse
import signal
import sys

#arg parse for host ip, port, help
parser = argparse.ArgumentParser(description="TCP/IP Chat")
parser.add_argument('--host', default='127.0.0.1', help='Server IP address (default: 127.0.0.1)')
parser.add_argument('--port', type=int, default=65432, help='Server port (default: 65432)')
args = parser.parse_args()

#set host and port from args
HOST = args.host
PORT = args.port

#SOCK_STREAM uses TCP by default
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#avoiding OSError; reusing address
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server.bind((HOST, PORT))
server.listen()

#setting up lists
clients = []
usernames = []

#message function
def broadcast(message, sender_client=None):
    try:
        message_str = message.decode("ascii")
    except:
        return
    if ": " in message_str:
        username_part, actual_message = message_str.split(": " , 1)
    else:
        actual_message = message_str

    if actual_message.startswith("/list"):
        user_list = "Online users: " + ", ".join(usernames)
        if sender_client:
            sender_client.send(user_list.encode("ascii"))
    elif actual_message.startswith("/msg"):
        parts = actual_message.split(" ", 2)
        if len(parts) >= 3:
            target_user = parts[1]
            private_msg = parts[2]

            if target_user in usernames:
                target_index = usernames.index(target_user)
                target_client = clients[target_index]

                sender_index = clients.index(sender_client)
                sender_username = usernames[sender_index]

                target_client.send(f"Private Message from {sender_username}: {private_msg}".encode("ascii"))
                sender_client.send(f"Sent to {target_user}: {private_msg}".encode("ascii"))
            else:
                if sender_client:
                    sender_client.send(f"User {target_user} not found".encode("ascii"))
    else:
        for client in clients:
            client.send(message)

#handling client connections
def handle(client, username_strip):
    while True:
        try:
            message = client.recv(1024)
            if message: #check if message has txt
                broadcast(message, sender_client=client)
            else:
                raise Exception("Client disconnected")
        except:
            if client in clients:
                index = clients.index(client)
                username = usernames[index]
                print(f"{username} disconnected")
                clients.remove(client)
                usernames.remove(username)
                client.close()
                broadcast(f"{username_strip} left the chat".encode("ascii"))
            break

def shutdown(signum, frame):
    print("Shutting down server...")
    for client in clients:
        try:
            client.close
        except:
            pass
    server.close()
    sys.exit(0)

def receive():
    while True:
        try:
            client, address = server.accept()
            print(f"Connected with {str(address)}")

            username = client.recv(1024).decode("ascii")
            username_strip = username.replace(":","")

            if username_strip in usernames or username_strip == "":
                client.send("!@#$INVALID".encode("ascii"))
                client.close()
                continue

            usernames.append(username_strip)
            clients.append(client)

            print(f"Username of the client is {username_strip}")
            broadcast(f"{username_strip} joined the chat".encode("ascii"))
            broadcast(f"!@#${usernames}".encode("ascii"))

            thread = threading.Thread(target=handle, args=(client, username_strip))
            thread.start()
        except OSError:
            break


def main():
    signal.signal(signal.SIGINT, shutdown)
    signal.signal(signal.SIGTERM, shutdown)
    print(f"Server started on {HOST}:{PORT}. CTRL+C to stop")
    receive()

if __name__ == "__main__":
    main()
