# ⚡ A X I O M
### A High-Performance Stack-Based Compiler

![C++](https://img.shields.io/badge/Language-C++-00599C)
![Python](https://img.shields.io/badge/IDE-Python-3776AB)
![Status](https://img.shields.io/badge/Status-Active-success)

---

## 1. What is Axiom?
Axiom is a simple but powerful programming language built from scratch. It allows you to write math-heavy code, compile it into low-level instructions, and execute it on a custom Virtual Machine.

It is designed to show how compilers work "under the hood" without being overly complex.

---

## 2. Project File Structure
Here is a guide to the files in this repository so you know what is what:

* **`main.cpp`** (The Engine)
    * This is the core C++ code. It contains the **Lexer** (reads text), **Parser** (understands logic), and **Virtual Machine** (runs code).
    * *You must compile this file to make the language work.*

* **`axiom_ide.py`** (The Interface)
    * This is a Python script that provides a graphical window (GUI).
    * It acts as a wrapper: it takes your text, saves it, and tells the C++ engine to run it.

* **`code.txt`** (Example Code)
    * A sample script written in the Axiom language to test if everything is working.

---

## 3. How to Install & Run

### Step 1: Build the C++ Engine
You need to turn the C++ code into an executable program. Open your terminal in this folder and run:

```bash
g++ main.cpp -o axiom
Step 2: Run the Graphical IDE (Recommended)The easiest way to use Axiom is via the Python IDE.Bashpython3 axiom_ide.py
This will open a window where you can type code and click "Run".Step 3: Run via Command Line (Optional)If you prefer the terminal, you can run scripts directly:Bash./axiom code.txt
4. The Axiom Language SyntaxAxiom looks like a simplified version of C or JavaScript.Variable AssignmentUse the set keyword to create variables.JavaScriptset width = 10;
set height = 20;
Math & PrecedenceAxiom follows standard math rules (parentheses first, then multiplication, then addition).JavaScript// (10 + 20) * 2 = 60
set area = (width + height) * 2;
OutputUse print to show results.JavaScriptprint area;
CommentsUse // to write notes that the compiler will ignore.JavaScript// This is a comment
set x = 5; // This is also a comment
5. Technical Internals (How it Works)The C++ engine converts your code into Bytecode (a list of numbers) and then processes them using a Stack.The FlowSource: 10 + 5Compiler: Generates PUSH 10, PUSH 5, ADD.Virtual Machine: Executes the stack operations.Instruction Set (OpCodes)These are the commands the Virtual Machine understands:CommandDescriptionExample LogicPUSHPuts a number onto the stackStack: [ 10 ]ADDAdds the top two numbers10 + 5 = 15SUBSubtracts the top numbers10 - 5 = 5MULMultiplies the top numbers10 * 5 = 50DIVDivides the top numbers10 / 5 = 2STORESaves top number to memoryset x = 10LOADLoads a variable from memoryprint x<div align="center"><b>Developed with ❤️ using C++ and Python</b></div>