# ⚡ A X I O M

### A High-Performance Stack-Based Compiler

![C++](https://img.shields.io/badge/Language-C++-00599C)
![Python](https://img.shields.io/badge/IDE-Python-3776AB)
![Status](https://img.shields.io/badge/Status-Active-success)

------------------------------------------------------------------------

## 1. What is Axiom?

Axiom is a simple but powerful programming language built from scratch.\
It allows you to write math-heavy code, compile it into low-level
instructions,\
and execute it on a custom Virtual Machine.

It is designed to demonstrate how compilers work **under the hood**
without being overly complex.

------------------------------------------------------------------------

## 2. Project File Structure

Here is a guide to the files in this repository:

### **`main.cpp`** --- The Engine

-   Contains the **Lexer**, **Parser**, and **Virtual Machine**
-   You must compile this to run the language

### **`axiom_ide.py`** --- The Interface

-   A Python GUI for writing and executing Axiom code

### **`code.txt`** --- Example Code

-   A sample script to test your setup

------------------------------------------------------------------------

## 3. How to Install & Run

### **Step 1 --- Build the C++ Engine**

Compile the core engine:

``` bash
g++ main.cpp -o axiom
```

------------------------------------------------------------------------

### **Step 2 --- Run the Graphical IDE (Recommended)**

Launch the Python GUI:

``` bash
python3 axiom_ide.py
```

This opens a simple editor where you can type and run Axiom code.

------------------------------------------------------------------------

### **Step 3 --- Run via Command Line (Optional)**

``` bash
./axiom code.txt
```

------------------------------------------------------------------------

## 4. The Axiom Language Syntax

Axiom resembles a simplified mix of C and JavaScript.

------------------------------------------------------------------------

### **Variable Assignment**

``` axiom
set width = 10;
set height = 20;
```

------------------------------------------------------------------------

### **Math & Precedence**

``` axiom
// (10 + 20) * 2 = 60
set area = (width + height) * 2;
```

------------------------------------------------------------------------

### **Output**

``` axiom
print area;
```

------------------------------------------------------------------------

### **Comments**

``` axiom
// This is a comment
set x = 5; // Inline comment
```

------------------------------------------------------------------------

## 5. Technical Internals (How It Works)

Axiom converts your code into **Bytecode**\
and executes it using a **stack-based Virtual Machine**.

### The Compilation Flow

1.  **Source:**\
    `10 + 5`
2.  **Compiler Output:**\
    `PUSH 10`, `PUSH 5`, `ADD`
3.  **Virtual Machine:**\
    Executes stack instructions left-to-right

------------------------------------------------------------------------

## Instruction Set (OpCodes)

  Command     Description                      Example
  ----------- -------------------------------- ----------------
  **PUSH**    Pushes a number onto the stack   Stack → `[10]`
  **ADD**     Adds the two top values          `10 + 5 = 15`
  **SUB**     Subtracts top values             `10 - 5 = 5`
  **MUL**     Multiplies top values            `10 * 5 = 50`
  **DIV**     Divides top values               `10 / 5 = 2`
  **STORE**   Saves value to memory            `set x = 10`
  **LOAD**    Loads from memory                `print x`

------------------------------------------------------------------------

::: {align="center"}
`<b>`{=html}Developed with ❤️ using C++ and Python`</b>`{=html}
:::
