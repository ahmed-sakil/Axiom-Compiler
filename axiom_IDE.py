import tkinter as tk
from tkinter import scrolledtext
import subprocess
import os

# Function to run the Axiom Compiler
def run_code():
    # 1. Get the code from the Input Text Area
    source_code = input_area.get("1.0", tk.END)

    # 2. Save it to temp file
    with open("temp_script.ax", "w") as f:
        f.write(source_code)

    # 3. Clear the Output Area
    output_area.config(state=tk.NORMAL)
    output_area.delete("1.0", tk.END)

    # 4. Run the C++ Executable (Renamed to 'axiom')
    executable = "./axiom" 
    if os.name == 'nt': # Windows support
        executable = "axiom.exe"

    try:
        # Run the compiler subprocess
        result = subprocess.run(
            [executable, "temp_script.ax"], 
            capture_output=True, 
            text=True
        )

        # 5. Display Output
        if result.returncode == 0:
            output_area.insert(tk.INSERT, result.stdout)
        else:
            output_area.insert(tk.INSERT, "Runtime Error:\n" + result.stderr)
            output_area.insert(tk.INSERT, "\n(Check for missing semicolons or typos)")

    except FileNotFoundError:
        output_area.insert(tk.INSERT, "System Error: Could not find 'axiom' executable.\nDid you run: g++ main.cpp -o axiom ?")

    output_area.config(state=tk.DISABLED)

# --- UI SETUP ---
root = tk.Tk()
root.title("Axiom Studio")
root.geometry("800x600")
root.configure(bg="#212121") # Modern Dark Grey

# Labels
tk.Label(root, text="Axiom Source Editor", fg="#00E5FF", bg="#212121", font=("Segoe UI", 12, "bold")).pack(pady=5)

# Input Area
input_area = scrolledtext.ScrolledText(root, height=15, font=("Consolas", 12), bg="#1E1E1E", fg="#E0E0E0", insertbackground="white", borderwidth=0)
input_area.pack(fill=tk.BOTH, padx=15)

# Default Code
default_code = """// Welcome to Axiom
// ----------------
set x = 10;
set y = 25;

// Axiom handles precedence automatically
set result = (x + y) * 2; 

print result;
"""
input_area.insert(tk.INSERT, default_code)

# Run Button
btn_run = tk.Button(root, text="▶ RUN AXIOM", command=run_code, bg="#00C853", fg="white", font=("Segoe UI", 11, "bold"), relief=tk.FLAT)
btn_run.pack(pady=10, ipadx=20)

# Output Area
tk.Label(root, text="Console Output", fg="#00E5FF", bg="#212121", font=("Segoe UI", 12, "bold")).pack(pady=5)
output_area = scrolledtext.ScrolledText(root, height=10, font=("Consolas", 12), bg="#000000", fg="#00FF00", borderwidth=0)
output_area.pack(fill=tk.BOTH, padx=15, pady=(0, 15))
output_area.config(state=tk.DISABLED)

root.mainloop()