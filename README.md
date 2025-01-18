---

# 🧩 **Push_Swap - Sorting with Stacks in C** 🧩

![Push_Swap](https://img.shields.io/badge/Push_Swap-Project-blue?style=flat-square) ![C Programming](https://img.shields.io/badge/Language-C-green?style=flat-square) ![Makefile](https://img.shields.io/badge/Build-Makefile-yellow?style=flat-square) ![42 Network](https://img.shields.io/badge/42Network-Push_Swap-lightblue?style=flat-square)

Welcome to **Push_Swap**, a modular and efficient sorting program designed to solve a fundamental algorithmic challenge: sorting integers using two stacks (`a` and `b`) with a limited set of operations. This project is part of the **42 Network** curriculum and is designed to test your understanding of algorithms, data structures, and optimization.

---

## 📑 **Table of Contents**
1. [Introduction](#introduction)
2. [Project Structure](#project-structure)
3. [Features](#features)
4. [Error Handling and Validation](#error-handling-and-validation)
5. [Bonus Functionality](#bonus-functionality)
6. [Installation](#installation)
7. [Usage](#usage)
8. [Makefile Specifics](#makefile-specifics)
9. [Acknowledgements](#acknowledgements)
10. [Author](#author)

---

## 📖 **Introduction**

The **Push_Swap** project aims to implement efficient sorting algorithms with minimal operations. Using stacks (`a` and `b`), you must sort a list of integers by performing operations such as:
- **`sa`**: Swap the first two elements of a stack.
- **`ra`**: Rotate a stack (top element moves to the bottom).
- **`pb`**: Push the top element from one stack to the other.

The **bonus part** introduces a **checker** program that validates the correctness of sorting operations.

---

## 📂 **Project Structure**

```bash
.
├── include/             # Header files
│   ├── push_swap.h      # Core declarations
│   ├── stack.h          # Stack-specific structures and operations
├── src/                 # Main source code
│   ├── core/            # Core logic for Push_Swap
│   ├── commands/        # Stack manipulation functions
│   ├── sorting/         # Sorting algorithms
│   ├── validation/      # Input parsing and validation
│   ├── utils/           # Utility functions
│   └── checker/         # Bonus checker implementation
├── libft/               # Custom library (libft) for common operations
├── tests/               # Test scripts and sample test cases
├── Makefile             # Build automation
└── README.md            # Project documentation
```

---

## 🌟 **Features**

### Modular Design
- Clear separation of core logic, commands, sorting algorithms, validation, and utility functions.
- Reusable codebase for both mandatory and bonus parts.

### Dynamic Input Handling
- Supports both array-based and linked-list-based stacks for flexibility and performance.

### Optimized Sorting Algorithms
- **Small Inputs**: Handles 3–5 numbers with hardcoded sorting.
- **Large Inputs**: Uses chunk-based or radix sorting to optimize moves.

---

## 🛡️ **Error Handling and Validation**

### Comprehensive Input Validation
The program ensures that inputs meet the following criteria:
- No duplicates.
- Valid integer representation (e.g., `004` is interpreted as `4`).
- Handles invalid input such as `--` or `++`.

### Resource Cleanup
- Frees all allocated memory, including stacks and auxiliary data structures, in case of errors.

### Bonus Validation
- The bonus **checker** program reads operations from standard input and ensures:
  - The stack is sorted.
  - All operations are valid.

---

## ➕ **Bonus Functionality**

### Checker Program
- Verifies the correctness of sorting operations.
- Reads operations like `sa`, `pb`, etc., from standard input and applies them to the stacks.

### Key Features
- Uses **`get_next_line`** to handle multi-line input.
- Outputs:
  - `OK` if the operations result in a sorted stack.
  - `KO` if the stack is not sorted or operations are invalid.

---

## ⚙️ **Installation**

### Prerequisites
- **GCC**: The GNU Compiler Collection.
- **Make**: Build automation tool.

### Steps
1. Clone the repository:
   ```bash
   git clone https://github.com/kitearuba/push_swap.git
   ```
2. Navigate to the project directory:
   ```bash
   cd push_swap
   ```
3. Compile the project:
   ```bash
   make
   ```

---

## 🚀 **Usage**

### Sorting with Push_Swap
To sort a sequence of integers, run:
```bash
./push_swap <list_of_numbers>
```
Example:
```bash
./push_swap 4 3 2 1
```
Output:
```bash
pb
pb
ra
pa
pa
```

### Validating with Checker (Bonus)
Pipe the output of **Push_Swap** to the **Checker**:
```bash
./push_swap 4 3 2 1 | ./checker 4 3 2 1
```
Expected Output:
- **OK**: Stack is sorted.
- **KO**: Stack is not sorted or invalid operations.

---

## 🛠️ **Makefile Specifics**

### Relinking Prevention
The Makefile:
- Avoids unnecessary relinking by checking timestamps of all dependencies.
- Rebuilds the project only when necessary, ensuring faster builds.

### Targets
- `make`: Builds the Push_Swap program and the Checker.
- `make clean`: Removes object files.
- `make fclean`: Removes object files and executables.
- `make re`: Rebuilds the entire project.

---

## 🙌 **Acknowledgements**

- **42 Network**: For designing this challenging and rewarding project.
- Open-source contributors and the community for sharing insights and tips.

---

## 👨‍💻 **Author**

- **chrrodri**  
  [GitHub Profile](https://github.com/kitearuba)

---
