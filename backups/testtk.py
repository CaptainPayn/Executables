#!/usr/bin/env python3
import tkinter as tk

def create_and_run_simple_window():
    """
    Creates a simple Tkinter window with a label and runs the main loop.
    """
    root = tk.Tk()  # Create the main window instance
    root.title("Tkinter Test Window")  # Set the window title
    root.geometry("300x200")  # Set the window size

    label = tk.Label(root, text="Hello, Tkinter!", font=("Courier", 16))
    label.pack(pady=50)  # Add a label to the window with padding

    root.mainloop()  # Start the Tkinter event loop

if __name__ == "__main__":
    create_and_run_simple_window()
