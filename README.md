<div align="center">

⚡ A X I O M

High-Performance Stack-Based Compiler & Virtual Machine

Axiom is a custom programming language implementation featuring a hand-written recursive descent compiler and a lightweight stack-based virtual machine. It demonstrates core compiler design concepts without external dependencies.

Features • Architecture • Syntax • Internals

</div>

🏗 System Architecture

Axiom follows a classic three-stage compiler pipeline. The diagram below represents the flow of data from source code to execution.

graph LR
    A[Source Code] -->|Lexer| B(Tokens)
    B -->|Parser| C{Abstract Syntax Tree}
    C -->|Code Gen| D[Bytecode Instructions]
    D -->|Virtual Machine| E[Stack Execution]
    E -->|Output| F[Console/IDE]
    
    style A fill:#f9f,stroke:#333,stroke-width:2px
    style D fill:#bbf,stroke:#333,stroke-width:2px
    style E fill:#bfb,stroke:#333,stroke-width:2px


🚀 Key Features

⚡ Stack-Based VM: A custom CPU simulation that uses a stack for arithmetic and logic, similar to the JVM or WebAssembly.

🧠 Recursive Descent Parser: A top-down parser that automatically handles operator precedence (PEMDAS) and nested parentheses.

💾 Symbol Table Memory: Dynamic memory management allowing for variable declaration, storage, and retrieval.

🛡️ Robust Error Handling: The compiler detects syntax errors (like missing semicolons) and runtime errors (like division by zero).

🖥️ Hybrid Tooling: Built with a high-performance C++ backend for execution and a Python frontend for the IDE.

📝 Axiom Syntax Guide

Axiom is designed to be C-like but simplified for educational clarity.

1. Variables & Math

// Define variables using 'set'
set width = 10;
set height = 25;

// Axiom handles complex math order-of-operations automatically
set area = (width + height) * 2; 

// Division and Subtraction support
set result = area / 5 - 2;


2. Output

// Print results to the console
print result;


3. Comments

// Lines starting with double-slashes are ignored by the Lexer
set x = 100; // Inline comments work too!


⚙ Under the Hood: Implementation

The core engine is built in C++ and consists of three distinct components.

1. The Lexer (Tokenizer)

The Lexer scans the raw text string and groups characters into Tokens. It handles whitespace elimination and comment stripping.

Input: set x = 10;

Output: [TOKEN_SET], [TOKEN_ID, "x"], [TOKEN_ASSIGN], [TOKEN_INT, 10], [TOKEN_SEMI]

2. The Parser (Code Generator)

The Parser uses a Recursive Descent strategy. It analyzes the tokens and converts them into numbers (Bytecode) that the Virtual Machine understands.

3. The Virtual Machine (The Processor)

The VM acts like a CPU. It doesn't have registers (like standard CPUs); instead, it uses a Stack to do math.

How the Stack Works (Visual Example)

When the VM executes 10 + 5, here is what happens step-by-step:

PUSH 10 → Stack: [ 10 ]

PUSH 5  → Stack: [ 10, 5 ]

ADD     → Pops 5 and 10, adds them, pushes 15. Stack: [ 15 ]

Instruction Set Reference

Math Operations
| Command | Action | Example |
| :--- | :--- | :--- |
| ADD | Adds the top two numbers | 10 + 5 |
| SUB | Subtracts the top number from the one below it | 10 - 5 |
| MUL | Multiplies the top two numbers | 10 * 5 |
| DIV | Divides the second number by the top number | 10 / 5 |

Memory & Data
| Command | Action | Example |
| :--- | :--- | :--- |
| PUSH | Puts a raw number onto the stack | 10 |
| STORE| Saves the top number into a variable (Memory) | set x = ... |
| LOAD | Finds a variable in Memory and puts it on the stack | ... = x |

<div align="center">

Star this Repo 🌟 if you find it interesting!

Developed with ❤️ using C++ and Python.

</div>