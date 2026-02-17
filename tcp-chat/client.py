#!/usr/bin/env python3

import socket
import curses
import sys
import time
import threading
import queue
import argparse

messages_recieved = queue.Queue()
exit_program = threading.Event()
listener_thread = sender_thread = None
users_online = []

def chat_input(stdscr, y, x, blink_rate=0.5):
    curses.curs_set(1)
    stdscr.nodelay(True)
    stdscr.timeout(100)
    input_buffer = ""
    show_prompt = True
    last_toggle = time.time()

    while True:
        now = time.time()
        #Blinks if empty
        if input_buffer == "":
            if now - last_toggle >= blink_rate:
                show_prompt = not show_prompt
                last_toggle = now
            prompt = "> " if show_prompt else "  "
        #will be kept solid
        else:
            prompt = "> "
            show_prompt = True

        # Draw input line
        stdscr.move(y, x)
        stdscr.clrtoeol()
        stdscr.addstr(y, x, prompt + input_buffer)
        stdscr.refresh()

        # Handle key press
        key = stdscr.getch()
        if key == -1:
            continue

        # returns text
        if key in (10, 13, curses.KEY_ENTER):
            # Clear input line after submission
            stdscr.move(y, x)
            stdscr.clrtoeol()
            stdscr.refresh()
            return input_buffer

        # BACKSPACE
        if key in (curses.KEY_BACKSPACE, 127, 8):
            input_buffer = input_buffer[:-1]
            continue

        # Printable characters
        if 32 <= key <= 126:
            input_buffer += chr(key)

def listener(s, exit_program):
    #list of users online
    global users_online

    while not exit_program.is_set():
        data = s.recv(1024)
        if not data:
            break
        message = data.decode('ascii').strip()
        if message == "":
            continue
        if message.startswith("!@#$"):  # special marker for user list
            users_online.clear()
            username = message.strip('!@#$')
            usernamestrip = username.strip('[]').replace("'", "")
            names = usernamestrip.split()
            for name in names:
                if name not in users_online:
                    users_online.append(name)
            continue

        messages_recieved.put(data.decode('ascii'))

def CleanExit(s,):
    global listener_thread, sender_thread
    exit_program.set()
    listener_thread.join(timeout=1)
    sender_thread.join(timeout=1)
    s.close()
    curses.endwin()
    sys.exit(0)


def sender(s, stdscr, input_area, UseName):
    while not exit_program.is_set():
        stdscr.move(input_area, 0)
        stdscr.clrtoeol()
        message = chat_input(stdscr, input_area, 0)

        # Checking to see if user wants to quit
        if message == "/quit":
            CleanExit(s)

        # Conacatentates username and message
        UNmessage = UseName + message

        # encodes and sends message to server

        encoded_message = UNmessage.encode('ascii')
        s.sendall(encoded_message)

def main(stdscr, IPhost, IPport):
    IPhost = IPhost
    IPport = IPport

    #sets curses and global var threads for clean exit
    curses.curs_set(1)
    global listener_thread, sender_thread, users_online

    #Screensize
    height, width = stdscr.getmaxyx()

    #Chat area
    chat_window = curses.newwin(height-1, width, 0,0 )
    chat_window.scrollok(True)

    #Input area
    input_area = height - 1

    #Gets Username
    stdscr.nodelay(False)
    curses.echo()
    #stdscr.move(input_area, 0)
    #stdscr.clrtoeol()
    #stdscr.addstr(input_area, 0, "Enter Username: ")

    s = None
    temp_listener = None
    
    # Username validation loop - reconnect each time
    while True:
        try:
            # Close previous socket if it exists
            if s:
                s.close()
            
            s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            s.connect((IPhost, IPport))
            
            users_online.clear()
            stdscr.move(input_area, 0)
            stdscr.clrtoeol()
            stdscr.addstr(input_area, 0, "Enter Username: ")
            stdscr.move(input_area, len("Enter Username: "))
            stdscr.refresh()
            Name_not_worked = stdscr.getstr(input_area, len("Enter Username: "),
                                            width - len("Enter Username: ") - 1).decode('ascii').strip()
            if Name_not_worked == "":
                stdscr.move(input_area, 0)
                stdscr.clrtoeol()
                stdscr.addstr(input_area, 0, "Username cannot be empty. Enter any key to try again.")
                stdscr.getch()
                continue
            
            users_online.clear()
            s.sendall(Name_not_worked.encode('ascii'))

            # Start a temporary listener to receive validation response
            temp_exit = threading.Event()
            temp_listener = threading.Thread(target=listener, args=(s, temp_exit,), daemon=True)
            temp_listener.start()

            # Wait for the listener to update users_online
            timeout = time.time() + 2
            while time.time() < timeout:
                if users_online:
                    break
                time.sleep(0.05)

            if users_online and "INVALID" in users_online:
                users_online.clear()
                stdscr.move(input_area, 0)
                stdscr.clrtoeol()
                stdscr.addstr(input_area, 0, "Username taken or invalid. Enter any key to try again.")
                stdscr.getch()
                continue
            
            # Username accepted - break out of loop
            UseName = Name_not_worked + ": "
            # Keep the listener thread running (don't stop temp_exit)
            listener_thread = temp_listener
            break
            
        except ConnectionRefusedError:
            print(f"Connection refused please make sure host is running on {IPhost} at {IPport}")
            return

    curses.noecho()
    stdscr.nodelay(True)

    # Now continue with the accepted connection
    sender_thread = threading.Thread(target=sender, args=(s, stdscr, input_area, UseName), daemon=True)
    sender_thread.start()

    #makes the chat window
    while not exit_program.is_set():
        while not messages_recieved.empty():
            msg = messages_recieved.get_nowait()
            try:
                chat_window.addstr(msg + "\n")
            except curses.error:
                pass
            except queue.Empty:
                break
            chat_window.refresh()

    s.close()


#arg parse for host ip, port, help
parser = argparse.ArgumentParser(description="TCP/IP Chat")
parser.add_argument('--host', default='10.41.10.141', help='Server IP address (default: 10.41.10.141)')
parser.add_argument('--port', type=int, default=65432, help='Server port (default: 65432)')
args = parser.parse_args()

#set host and port from args
IPhost = args.host
IPport = args.port

curses.wrapper(lambda stdscr: main(stdscr, IPhost, IPport))
