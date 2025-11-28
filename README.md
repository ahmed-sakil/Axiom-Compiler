# ⚡ A X I O M

### A High-Performance Stack-Based Compiler

![C++](https://img.shields.io/badge/Language-C++-00599C)
![Python](https://img.shields.io/badge/IDE-Python-3776AB)
![Status](https://img.shields.io/badge/Status-Active-success)

------------------------------------------------------------------------

## 1. What is Axiom?

Axiom is a simple but powerful programming language built from scratch.
It allows you to write math-heavy code, compile it into low-level
instructions, and execute it on a custom Virtual Machine.

It is designed to show how compilers work "under the hood" without being
overly complex.

------------------------------------------------------------------------

## 2. Project File Structure

Here is a guide to the files in this repository so you know what is
what:

-   **`main.cpp`** (The Engine)
    -   This is the core C++ code. It contains the **Lexer**,
        **Parser**, and **Virtual Machine**.
    -   *You must compile this file to make the language work.*
-   **`axiom_ide.py`** (The Interface)
    -   Provides a graphical window (GUI).
    -   It saves your code and executes it using the C++ engine.
-   **`code.txt`** (Example Code)
    -   A sample script to test the language.

------------------------------------------------------------------------

## 3. How to Install & Run

### Step 1: Build the C++ Engine

Compile the engine:

``` bash
g++ main.cpp -o axiom
```

### Step 2: Run the Graphical IDE (Recommended)

Start the Python GUI:

``` bash
python3 axiom_ide.py
```

### Step 3: Run via Command Line (Optional)

Directly execute a script:

``` bash
./axiom code.txt
```

------------------------------------------------------------------------

## 4. The Axiom Language Syntax

Axiom looks like a simplified version of C or JavaScript.

### Variable Assignment

``` axiom
set width = 10;
set height = 20;
```

### Math & Precedence

``` axiom
// (10 + 20) * 2 = 60
set area = (width + height) * 2;
```

### Output

``` axiom
print area;
```

### Comments

``` axiom
// This is a comment
set x = 5; // This is also a comment
```

------------------------------------------------------------------------

## 5. Technical Internals (How It Works)

The C++ engine converts your code into **Bytecode** and executes it on a
**Stack-based Virtual Machine**.

### The Flow

-   **Source:** `10 + 5`
-   **Compiler Output:** `PUSH 10`, `PUSH 5`, `ADD`
-   **VM:** Executes stack operations

------------------------------------------------------------------------

## Instruction Set (OpCodes)

  Command     Description              Example
  ----------- ------------------------ ----------------
  **PUSH**    Pushes number to stack   Stack → `[10]`
  **ADD**     Adds top numbers         `10 + 5 = 15`
  **SUB**     Subtracts top numbers    `10 - 5 = 5`
  **MUL**     Multiplies               `10 * 5 = 50`
  **DIV**     Divides                  `10 / 5 = 2`
  **STORE**   Saves to memory          `set x = 10`
  **LOAD**    Loads from memory        `print x`

------------------------------------------------------------------------

::: {align="center"}
`<b>`{=html}Developed with ❤️ using C++ and Python`</b>`{=html}
:::
