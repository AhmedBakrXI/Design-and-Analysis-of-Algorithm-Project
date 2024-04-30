import tkinter as tk
from tkinter import messagebox


def add_names(event=None):
    names = add_entry.get().split(',')
    for name in names:
        unsorted_listbox.insert(tk.END, name.strip())
    add_entry.delete(0, tk.END)


def sort_names():
    names = [unsorted_listbox.get(idx) for idx in range(unsorted_listbox.size())]
    sorted_names = sorted(names)
    sorted_listbox.delete(0, tk.END)
    for name in sorted_names:
        sorted_listbox.insert(tk.END, name)


def clear_all():
    if unsorted_listbox.size() == 0 and sorted_listbox.size() == 0:
        messagebox.showinfo("Nothing to Clear", "Both lists are already empty. There is nothing to clear.")
    else:
        unsorted_listbox.delete(0, tk.END)
        sorted_listbox.delete(0, tk.END)
        add_entry.delete(0, tk.END)


def copy_sorted_names():
    if sorted_listbox.size() == 0:
        messagebox.showinfo("Empty Sorted List", "The sorted list is empty. There is nothing to copy.")
    else:
        sorted_names = sorted_listbox.get(0, tk.END)
        sorted_names_str = "\n".join(sorted_names)
        root.clipboard_clear()
        root.clipboard_append(sorted_names_str)


def exit_app():
    if messagebox.askokcancel("Exit", "Are you sure you want to exit?"):
        root.destroy()


def create_list_frame(parent, width=300, height=300):
    frame = tk.Frame(parent, width=width, height=height)
    frame.pack(side=tk.LEFT, padx=5, pady=5)
    frame.grid_propagate(False)
    return frame


root = tk.Tk()
root.title("Name Sorter")
root.resizable(False, False)

control_frame = tk.Frame(root)
control_frame.pack(side=tk.TOP, pady=10)

add_label = tk.Label(control_frame, text="Enter names to add (separated by comma):")
add_label.grid(row=0, column=0, sticky=tk.W, padx=5, pady=5)

add_entry = tk.Entry(control_frame)
add_entry.grid(row=0, column=1, padx=5, pady=5)
add_entry.bind('<Return>', add_names)

add_button = tk.Button(control_frame, text="Add", command=add_names, width=10)
add_button.grid(row=0, column=2, padx=5, pady=5)

modify_button = tk.Button(control_frame, text="Modify", command=clear_all, width=10)
modify_button.grid(row=0, column=3, padx=5, pady=5)

sort_button = tk.Button(root, text="Sort Names", command=sort_names)
sort_button.pack(pady=(10, 0))

lists_frame = tk.Frame(root)
lists_frame.pack(padx=5, pady=5)

unsorted_frame = create_list_frame(lists_frame)
unsorted_listbox = tk.Listbox(unsorted_frame, width=40, height=15)
unsorted_listbox.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
unsorted_scrollbar = tk.Scrollbar(unsorted_frame, orient=tk.VERTICAL, command=unsorted_listbox.yview)
unsorted_scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
unsorted_listbox.config(yscrollcommand=unsorted_scrollbar.set)

sorted_frame = create_list_frame(lists_frame)
sorted_listbox = tk.Listbox(sorted_frame, width=40, height=15)
sorted_listbox.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
sorted_scrollbar = tk.Scrollbar(sorted_frame, orient=tk.VERTICAL, command=sorted_listbox.yview)
sorted_scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
sorted_listbox.config(yscrollcommand=sorted_scrollbar.set)

exit_clear_frame = tk.Frame(root)
exit_clear_frame.pack(side=tk.BOTTOM, pady=10)

copy_button = tk.Button(exit_clear_frame, text="Copy Sorted Names", command=copy_sorted_names, width=15)
copy_button.pack(side=tk.LEFT, padx=5, pady=5)

clear_button = tk.Button(exit_clear_frame, text="Clear All", command=clear_all, width=10)
clear_button.pack(side=tk.LEFT, padx=5, pady=5)

exit_button = tk.Button(exit_clear_frame, text="Exit", command=exit_app, width=10)
exit_button.pack(side=tk.RIGHT, padx=5, pady=5)

# Pack the frame to the bottom right corner
exit_clear_frame.pack(side=tk.BOTTOM, padx=5, pady=5, anchor=tk.SE)

root.mainloop()
