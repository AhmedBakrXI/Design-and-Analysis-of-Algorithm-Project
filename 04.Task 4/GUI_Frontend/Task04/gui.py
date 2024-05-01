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
    try:
        num_disks = int(num_disks)
        if num_disks <= 0:
            raise ValueError
    except ValueError:
        messagebox.showerror("Error", "Please enter a valid positive integer for the number of disks.")
        return

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

# Canvas to visualize the pegs and disks
canvas = tk.Canvas(root, width=700, height=400, bg="lightgray")
canvas.pack()

# Define the coordinates of the pegs and their bases
peg_coordinates = {'A': (150, 350), 'B': (300, 350), 'C': (450, 350), 'D': (600, 350)}
peg_base_size = 20  # Adjust base size as needed

# Draw the base for all pegs
base_x = 90
base_y = 350
base_width = 570
canvas.create_rectangle(base_x, base_y, base_x + base_width, base_y + peg_base_size, fill="black")

# Draw the pegs
for peg, (x, y) in peg_coordinates.items():
    # Draw peg
    canvas.create_rectangle(x - 10, y, x + 10, y - 200, fill="brown")

# Create the disks
disks = []
for i in range(8):  # Change the range to match the maximum number of disks
    peg_x, peg_y = peg_coordinates['A']  # Starting position on peg A
    disk_width = 100 - i * 10  # Adjust disk width as needed
    disk_id = canvas.create_rectangle(peg_x - disk_width // 2, peg_y - 20 - i * 20, peg_x + disk_width // 2,
                                      peg_y - i * 20, fill="blue")
    disks.append(disk_id)

# Add labels and entry field
label = tk.Label(root, text="Enter the number of disks:")
label.pack()

entry = tk.Entry(root)
entry.pack()

# Button to trigger solving Tower of Hanoi
solve_button = tk.Button(root, text="Solve Tower of Hanoi", command=lambda: solve_hanoi(canvas, entry.get()))
solve_button.pack()

root.mainloop()
