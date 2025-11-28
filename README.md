Axiom Compiler & Virtual Machine

Axiom is a lightweight, high-performance programming language implementation consisting of a recursive-descent compiler and a custom stack-based virtual machine (VM), built entirely in C++. It includes a modern Python-based IDE for writing and testing code.

⚡ Core Architecture

Axiom operates on a three-stage pipeline designed for efficiency and educational clarity:

Lexical Analysis: Converts raw source code into an optimized stream of tokens, handling whitespace and comments.

Semantic Parsing: Utilizes a Recursive Descent strategy to validate syntax, enforce Operator Precedence (PEMDAS), and generate bytecode.

Virtual Machine Runtime: A custom Stack-Based Architecture that executes bytecode instructions directly, managing memory and global scope.

🚀 Key Features

Stack-Based Execution: Efficient PUSH, POP, and arithmetic operations.

Memory Management: Symbol table implementation for variable storage (STORE/LOAD).

Expression Evaluation: Full support for complex arithmetic expressions with parentheses precedence.

Developer Friendly: Includes support for // comments and C-style statement termination (;).

Axiom IDE: A dedicated GUI for writing and executing Axiom scripts.

🛠️ Installation & Build

Prerequisites

G++ Compiler (GCC) or Clang

Python 3.x (for the IDE)

1. Build the Compiler Engine

To compile the Axiom engine from source, run:

g++ main.cpp -o axiom


(Windows users: This generates axiom.exe)

📖 Usage Guide

Option A: Using the Axiom IDE (Recommended)

We provide a graphical interface to write and run code easily.

python3 axiom_ide.py


Option B: Command Line Usage

Create a script file (e.g., script.ax) and pass it to the executable.

./axiom script.ax


Syntax Example

// Axiom Language Example
// ----------------------

// 1. Variable Assignment
set width = 10;
set height = 20;

// 2. Complex Arithmetic (Supports Precedence)
set area = (width + height) * 2; 

// 3. Output
print area;


🔍 Technical Instruction Set (Bytecode)

The Axiom VM understands the following OpCodes:

OpCode

Hex

Description

PUSH

0x01

Pushes a value onto the stack

ADD

0x02

Pops top two values, Adds, Pushes result

SUB

0x03

Pops top two values, Subtracts, Pushes result

MUL

0x04

Pops top two values, Multiplies, Pushes result

STORE

0x08

Pops value and stores in global memory

LOAD

0x09

Loads value from memory to stack

📝 License

This project is open-source and available under the MIT License.