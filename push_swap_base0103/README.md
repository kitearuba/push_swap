---

# 🧩 **Push_Swap - Sorting with Stacks in C** 🧩

![Push_Swap](https://img.shields.io/badge/Push_Swap-Project-blue?style=flat-square) ![C Programming](https://img.shields.io/badge/Language-C-green?style=flat-square) ![Makefile](https://img.shields.io/badge/Build-Makefile-yellow?style=flat-square) ![42 Network](https://img.shields.io/badge/42Network-Push_Swap-lightblue?style=flat-square)

Welcome to **Push_Swap**, a project that challenges you to sort a stack of integers using a restricted set of operations and in the fewest moves possible. This project is part of the **42 Network** curriculum, focusing on algorithms, data structures, and performance optimization in **C programming**.

This version includes a **modular structure**, designed to make the codebase reusable and maintainable for future projects, with considerations for both **array-based stacks** and **linked lists**.

---

## 📑 **Table of Contents**

1. [Introduction](#introduction)
2. [Project Structure](#project-structure)
3. [Changes in This Version](#changes-in-this-version)
4. [Technologies Used](#technologies-used)
5. [Installation](#installation)
6. [Usage](#usage)
7. [Push_Swap Functionality](#push_swap-functionality)
8. [Bonus Checker Functionality](#bonus-checker-functionality)
9. [Contributing](#contributing)
10. [Acknowledgements](#acknowledgements)
11. [Author](#author)

---

## 📖 **Introduction**

**Push_Swap** is a project designed to sort a stack of integers using two stacks (`a` and `b`) and a set of predefined operations, such as `sa` (swap the top two elements), `ra` (rotate the stack), and `pb` (push an element from one stack to another). 

The goal is to implement efficient sorting algorithms that minimize the number of operations required to sort the stack.

### **Learning Objectives**
- Understand and implement sorting algorithms with performance constraints.
- Use stacks (implemented as arrays or linked lists) and operations effectively.
- Optimize code for time and space complexity.

---

## 📂 **Project Structure**

```bash
.
├── include/             # Header files
│   ├── push_swap.h      # Core declarations for sorting
│   ├── stack.h          # Stack-specific declarations
│   ├── utils.h          # Utility function declarations
│   └── checker_bonus.h  # Bonus-specific declarations
├── src/                 # Source files implementing the main functionality
│   ├── main.c           # Entry point of the program
│   ├── push_swap.c      # Main logic for sorting
│   ├── stack_operations.c # Stack manipulation functions
│   ├── sort_small.c     # Sorting logic for small inputs (3-5 numbers)
│   ├── sort_medium.c    # Sorting logic for medium inputs (6-100 numbers)
│   ├── sort_large.c     # Sorting logic for large inputs (100+ numbers)
│   ├── input_validation.c # Input parsing and validation
│   ├── utils.c          # General-purpose helper functions
│   └── memory_management.c # Memory allocation and cleanup
├── src_bonus/           # Source files for bonus functionality
│   ├── checker_bonus.c  # Main logic for the checker program
│   ├── stack_operations_bonus.c # Bonus stack operations
│   ├── input_validation_bonus.c # Bonus input validation
├── tests/               # Test scripts and sample cases
│   ├── test_cases.txt   # List of input test cases
│   └── test.sh          # Automated test script
├── libft/               # Your libft implementation (e.g., ft_split, ft_printf)
├── Makefile             # Build system
└── README.md            # Documentation
```

---

## 🔄 **Changes in This Version**

### **Dynamic Data Structures**
- Introduced **linked lists** as an alternative to arrays for stack representation:
  - More efficient for dynamic operations like `push` and `rotate`.
  - Built using the `libft` list functions (`ft_lstnew`, `ft_lstadd_back`, etc.).

### **Bonus Support**
- Added a **bonus program** (`checker`) to validate sorting operations read from standard input.
- Utilized `get_next_line` from `libft` for handling multi-line input in the checker.

### **Improved Modular Design**
- Clear separation of concerns:
  - Mandatory logic in `src/`.
  - Bonus logic in `src_bonus/`.
  - Shared declarations in `include/`.

---

## 🛠️ **Technologies Used**

- **C Language**: The core language for implementing Push_Swap and integrating with **libft**.
- **Makefile**: Automates the build process for both **Push_Swap** and **libft**.
- **GCC Compiler**: Used to compile the source files into executables.

---

## 🚀 **Installation**

To install and compile the **Push_Swap** project, follow these steps:

1. **Clone the Repository**:
   ```bash
   git clone git@github.com:kitearuba/push_swap.git
   ```

2. **Navigate to the Project Directory**:
   ```bash
   cd push_swap
   ```

3. **Compile the Project**:
   Use the `make` command to compile the project and generate the executable:
   ```bash
   make
   ```

This will compile both the **Push_Swap** program and the **libft**, resulting in an executable for **Push_Swap**.

---

## 💡 **Usage**

Once compiled, you can use **Push_Swap** to sort a stack of integers.

### **Basic Example**:
To sort the numbers `4 3 2 1`, run:
```bash
./push_swap 4 3 2 1
```

The program will output the sequence of operations required to sort the stack, such as:
```bash
pb
sa
pa
```

### **Bonus Program (Checker)**:
To validate sorting operations:
```bash
./push_swap 4 3 2 1 | ./checker 4 3 2 1
```
The checker will output:
- `OK` if the operations sort the stack correctly.
- `KO` if the operations fail to sort the stack.

---

## 🔨 **Push_Swap Functionality**

### 🔄 **Workflow**
1. Parse the input integers and validate their format (e.g., no duplicates, valid numbers).
2. Push the numbers into Stack `a`.
3. Depending on the number of integers:
   - Use a hardcoded approach for small sets (3–5 numbers).
   - Use chunk-based or radix sorting for larger sets.
4. Output the sequence of operations to sort Stack `a` in ascending order.

### 🛑 **Error Handling**
The program detects and handles errors like:
- Invalid input (non-integers or duplicates).
- Memory allocation failures.
- Empty arguments.

---

## 🤝 **Contributing**

Contributions are welcome! Feel free to open issues or submit pull requests for bug fixes, improvements, or new features.

---

## 🙌 **Acknowledgements**

Thanks to the **42 Network** for providing this challenging and rewarding project, and to the community for sharing knowledge and resources.

---

## 👨‍💻 **Author**

- **chrrodri**  
  [GitHub Profile](https://github.com/kitearuba)

---
