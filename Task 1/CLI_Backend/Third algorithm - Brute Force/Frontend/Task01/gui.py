import tkinter as tk
from tkinter import ttk, messagebox
import subprocess
import random


class ChessboardGUI:
    def __init__(self, master):
        self.display_window = None
        self.canvas = None
        self.hole_col_entry = None
        self.hole_row_entry = None
        self.size_dropdown = None
        self.master = master
        self.master.title("Defective Chessboard with L-trominoes")
        self.master.resizable(False, False)  # Disable resizing

        self.board_size = tk.IntVar()
        self.hole_row = tk.IntVar()
        self.hole_col = tk.IntVar()

        self.create_widgets()

        # Bind function to handle window closing event
        self.master.protocol("WM_DELETE_WINDOW", self.on_closing)

        # Center the window on the screen
        self.center_window()

    def create_widgets(self):
        # Label and dropdown for selecting board size
        size_label = ttk.Label(self.master, text="Select Board Size:")
        size_label.grid(row=0, column=0, padx=5, pady=5, sticky='w')

        size_options = [2 ** i for i in range(2, 8)]  # Sizes from 4x4 to 128x128.
        self.size_dropdown = ttk.Combobox(self.master, textvariable=self.board_size, values=size_options, state='readonly')
        self.size_dropdown.grid(row=0, column=1, padx=5, pady=5, sticky='w')
        self.size_dropdown.current(0)  # Set default size to the first option

        # Label and entry for specifying hole position
        hole_label = ttk.Label(self.master, text="Specify Hole Position (row, col):")
        hole_label.grid(row=1, column=0, padx=5, pady=5, sticky='w')

        # Entry for hole row
        self.hole_row_entry = ttk.Entry(self.master, textvariable=self.hole_row)
        self.hole_row_entry.grid(row=1, column=1, padx=(5, 2), pady=5, sticky='ew')
        self.hole_row.set(1)  # Set default hole row to 1

        # Entry for hole column
        self.hole_col_entry = ttk.Entry(self.master, textvariable=self.hole_col)
        self.hole_col_entry.grid(row=1, column=2, padx=(2, 5), pady=5, sticky='ew')
        self.hole_col.set(1)  # Set default hole column to 1

        # Button to fill the chessboard with L-trominoes
        fill_button = ttk.Button(self.master, text="Fill Chessboard", command=self.fill_chessboard)
        fill_button.grid(row=2, column=0, columnspan=3, padx=5, pady=10, sticky='ew')

        # Button to exit the program
        exit_button = ttk.Button(self.master, text="Exit", command=self.exit_program)
        exit_button.grid(row=3, column=2, padx=5, pady=10, sticky="se")

        # Set column weights and padding
        self.master.grid_columnconfigure(1, weight=1)  # Make column 1 (entry columns) expandable
        self.master.grid_columnconfigure(2, weight=1)  # Make column 2 (exit button column) expandable
        self.master.grid_columnconfigure(0, pad=10)  # Add padding to column 0

    def fill_chessboard(self):
        size = self.board_size.get()
        hole_row = self.hole_row.get()
        hole_col = self.hole_col.get()

        if hole_row == 0 or hole_col == 0:
            messagebox.showerror("Error", "Row and Column values cannot be 0.")
            return

        # Call the C++ backend to fill the chessboard with L-trominoes
        process = subprocess.Popen(["./a.out", str(size), str(hole_row), str(hole_col)], stdout=subprocess.PIPE,  stderr=subprocess.PIPE,
                                   text=True)
        output, error = process.communicate()
        print("Output:", output)

        if error:
            print("Error", error)
        # Display the filled chessboard in a new window
        self.display_chessboard(output)

        # Make the display window the current window
        self.display_window.lift()

        # Set focus to the display window
        self.display_window.focus_set()

        # Bind keyboard arrow events to the display window
        self.display_window.bind("<Left>", lambda event: self.canvas.xview_scroll(-1, "units"))
        self.display_window.bind("<Right>", lambda event: self.canvas.xview_scroll(1, "units"))
        self.display_window.bind("<Up>", lambda event: self.canvas.yview_scroll(-1, "units"))
        self.display_window.bind("<Down>", lambda event: self.canvas.yview_scroll(1, "units"))

    def display_chessboard(self, output):
        # Create a new window to display the chessboard
        self.display_window = tk.Toplevel(self.master)
        self.display_window.title("Filled Chessboard")

        # Create a canvas to draw the chessboard with scrollbars
        self.canvas = tk.Canvas(self.display_window, width=50 * self.board_size.get(), height=50 * self.board_size.get())
        self.canvas.pack(side="left", fill="both", expand=True)

        # Add vertical scrollbar
        y_scrollbar = ttk.Scrollbar(self.display_window, orient="vertical", command=self.canvas.yview)
        y_scrollbar.pack(side="right", fill="y")
        self.canvas.configure(yscrollcommand=y_scrollbar.set)

        # Add horizontal scrollbar
        x_scrollbar = ttk.Scrollbar(self.display_window, orient="horizontal", command=self.canvas.xview)
        x_scrollbar.pack(side="bottom", fill="x")
        self.canvas.configure(xscrollcommand=x_scrollbar.set)

        # Create a frame to contain the chessboard
        board_frame = ttk.Frame(self.canvas)
        self.canvas.create_window((0, 0), window=board_frame, anchor="nw")

        # Parse the output and fill the chessboard
        board = [[0 for _ in range(self.board_size.get())] for _ in range(self.board_size.get())]
        color_dict = {}  # Dictionary to map each number to a unique color
        for row_index, row in enumerate(output.strip().split('\n')):
            for col_index, cell in enumerate(row.split()):
                if cell.isdigit():
                    tromino_num = int(cell)
                    if tromino_num == -1:
                        color = '#000000'  # Hole color (black)
                    else:
                        if tromino_num not in color_dict:
                            color_dict[tromino_num] = self.generate_unique_color(color_dict)
                        color = color_dict[tromino_num]
                    board[row_index][col_index] = tromino_num

                    # Draw rectangle for the tromino
                    self.canvas.create_rectangle(col_index * 50, row_index * 50, (col_index + 1) * 50,
                                                 (row_index + 1) * 50, fill=color)

        # Draw hole
        hole_row = self.hole_row.get() - 1
        hole_col = self.hole_col.get() - 1
        self.canvas.create_rectangle(hole_col * 50, hole_row * 50, (hole_col + 1) * 50, (hole_row + 1) * 50,
                                     fill='#000000')

        # Bind canvas resizing event
        self.canvas.bind("<Configure>", self.update_scroll_region)

        # Configure canvas scroll region
        self.canvas.config(scrollregion=self.canvas.bbox("all"))

        # Bind mouse wheel event to canvas for scrolling
        self.canvas.bind("<MouseWheel>", self.on_mouse_wheel)
        # Bind left and right button events for touchpad gestures
        self.canvas.bind("<Button-4>", self.scroll_left)
        self.canvas.bind("<Button-5>", self.scroll_right)

    def update_scroll_region(self, event):
        """Update canvas scroll region when the canvas size changes."""
        self.canvas.configure(scrollregion=self.canvas.bbox("all"))

    def on_mouse_wheel(self, event):
        if event.delta > 0:
            self.canvas.yview_scroll(-1, "units")
        elif event.delta < 0:
            self.canvas.yview_scroll(1, "units")

    def scroll_left(self, event):
        self.canvas.xview_scroll(-1, "units")

    def scroll_right(self, event):
        self.canvas.xview_scroll(1, "units")

    @staticmethod
    def generate_unique_color(color_dict):
        # Generate a random color and ensure it is unique and not too close to black or white
        while True:
            # Generate random RGB values (excluding too dark or too light colors)
            r = random.randint(50, 205)
            g = random.randint(50, 205)
            b = random.randint(50, 205)

            # Convert RGB values to hexadecimal format
            color = "#{:02x}{:02x}{:02x}".format(r, g, b)

            # Check if the color is unique and not too close to black or white
            if color not in color_dict.values():
                return color

    def on_closing(self):
        if messagebox.askokcancel("Quit", "Do you want to quit?"):
            self.master.destroy()

    def exit_program(self):
        if messagebox.askokcancel("Exit", "Do you want to exit?"):
            self.master.destroy()

    def center_window(self):
        # Update the window size based on widget sizes
        self.master.update_idletasks()
        width = max(self.master.winfo_reqwidth(), 200)
        height = max(self.master.winfo_reqheight(), 100)

        # Get screen width and height
        screen_width = self.master.winfo_screenwidth()
        screen_height = self.master.winfo_screenheight()

        # Calculate x and y coordinates for the window to be centered
        x = (screen_width // 2) - (width // 2)
        y = (screen_height // 2) - (height // 2)

        # Set the position and size of the window
        self.master.geometry(f"{width}x{height}+{x}+{y}")


def main():
    root = tk.Tk()
    app = ChessboardGUI(root)
    root.mainloop()


if __name__ == "__main__":
    main()
