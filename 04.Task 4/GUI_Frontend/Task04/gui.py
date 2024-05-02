import tkinter as tk
from tkinter import messagebox
import subprocess
import time


# Function to move a disk on the canvas
def move_disk(canvas, disk_id, source_peg, dest_peg):
    source_x, source_y = peg_coordinates[source_peg]
    dest_x, dest_y = peg_coordinates[dest_peg]
    canvas.move(disk_id, dest_x - source_x, dest_y - source_y)


# Function to solve Tower of Hanoi and visualize the solution
def solve_hanoi(canvas, num_disks):
    # Call the C++ program
    try:
        output = subprocess.check_output(["./a.out", str(num_disks)], universal_newlines=True)
        # Parse the output and visualize the solution here
        moves = output.strip().split('\n')

        for move in moves:
            move_parts = move.split()
            if len(move_parts) < 5:
                continue  # Skip lines with fewer than 5 values
            disk_no = move_parts[2]
            source_peg = move_parts[5]
            dest_peg = move_parts[8]
            move_disk(canvas, disks[int(disk_no) - 1], source_peg, dest_peg)
            canvas.update()
            time.sleep(1)  # Adjust the delay as needed for visualization
    except subprocess.CalledProcessError:
        messagebox.showerror("Error", "Failed to execute the C++ program.")


# Create the main window
root = tk.Tk()
root.title("Tower of Hanoi Visualizer")
root.geometry("700x500")  # Fixed window size

# Disable window resizing
root.resizable(False, False)

# Define the coordinates of the pegs and their bases
peg_coordinates = {'A': (150, 350), 'B': (300, 350), 'C': (450, 350), 'D': (600, 350)}
peg_base_size = 20  # Adjust base size as needed

# Draw the base for all pegs
base_x = 90
base_y = 350
base_width = 570

# Canvas to visualize the pegs and disks
canvas = tk.Canvas(root, width=700, height=400, bg="#e5e5e5")
canvas.grid(row=0, column=0, columnspan=3)

# Draw the base for all pegs
canvas.create_rectangle(base_x, base_y, base_x + base_width, base_y + peg_base_size, fill="#2b2d42")

# Draw the pegs
for peg, (x, y) in peg_coordinates.items():
    # Draw peg
    canvas.create_rectangle(x - 10, y, x + 10, y - 200, fill="#8d99ae")


def draw_disks(num_disks):
    global disks
    disks = []
    for i in range(num_disks):
        peg_x, peg_y = peg_coordinates['A']  # Starting position on peg A
        disk_width = 100 - i * 10  # Adjust disk width as needed
        disk_id = canvas.create_rectangle(peg_x - disk_width // 2, peg_y - 20 - i * 20,
                                          peg_x + disk_width // 2, peg_y - i * 20, fill="#d90429")
        disks.insert(0, disk_id)  # Insert the disk ID at the beginning of the list
    return disks


# Frame to hold the label and entry field
input_frame = tk.Frame(root)
input_frame.place(relx=0.5, rely=0.9, anchor=tk.CENTER)  # Centering the frame

label = tk.Label(input_frame, text="Enter the number of disks:")
label.grid(row=0, column=0, sticky=tk.W)

entry = tk.Entry(input_frame)
entry.grid(row=0, column=1, padx=(0, 10), sticky=tk.W)  # Adjusted the padding


# Function to validate input and execute draw disks
def draw_disks_handler():
    num_disks = validate_input(entry.get())
    if num_disks is not None:
        draw_disks(num_disks)


# Button to draw disks based on user input
draw_button = tk.Button(input_frame, text="Draw Disks", command=draw_disks_handler)
draw_button.grid(row=0, column=2, sticky=tk.W, padx=(0, 10))  # Adjusted the padding


# Function to validate input and execute solve Hanoi
def solve_hanoi_handler():
    num_disks = validate_input(entry.get())
    if num_disks is not None:
        if 'disks' not in globals():
            messagebox.showerror("Error", "Please draw disks first.")
        else:
            solve_hanoi(canvas, num_disks)


# Button to trigger solving Tower of Hanoi
solve_button = tk.Button(input_frame, text="Solve Tower of Hanoi", command=solve_hanoi_handler)
solve_button.grid(row=1, column=0, columnspan=3, pady=(10, 0))  # Moved to the second row and adjusted columnspan


# Function to validate the input
def validate_input(entry_value):
    try:
        num_disks = int(entry_value)
        if num_disks < 1:
            raise ValueError("Number of disks should be greater than or equal to 1")
        elif num_disks > 8:
            messagebox.showerror("Error", "The available range for visualization is from 1 to 8 disks.")
            return None
        return num_disks
    except ValueError:
        messagebox.showerror("Error", "Please enter a valid positive integer for the number of disks.")
        return None


root.mainloop()
