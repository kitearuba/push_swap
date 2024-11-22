Here’s your **Push_Swap README file**, restructured based on the Pipex README format but tailored to the **Push_Swap project**:

---

# 🧩 **Push_Swap - Sorting with Stacks in C** 🧩

![Push_Swap](https://img.shields.io/badge/Push_Swap-Project-blue?style=flat-square) ![C Programming](https://img.shields.io/badge/Language-C-green?style=flat-square) ![Makefile](https://img.shields.io/badge/Build-Makefile-yellow?style=flat-square) ![42 Network](https://img.shields.io/badge/42Network-Push_Swap-lightblue?style=flat-square)

Welcome to **Push_Swap**, a project that challenges you to sort a stack of integers using a restricted set of operations and in the fewest moves possible. This project is part of the **42 Network** curriculum, focusing on algorithms, data structures, and performance optimization in **C programming**.

This version includes a **modular structure**, designed to make the codebase reusable and maintainable for future projects.

---

## 📑 **Table of Contents**

1. [Introduction](#introduction)
2. [Project Structure](#project-structure)
3. [Changes in This Version](#changes-in-this-version)
4. [Technologies Used](#technologies-used)
5. [Installation](#installation)
6. [Usage](#usage)
7. [Push_Swap Functionality](#push_swap-functionality)
8. [Contributing](#contributing)
9. [Acknowledgements](#acknowledgements)
10. [Author](#author)

---

## 📖 **Introduction**

**Push_Swap** is a project designed to sort a stack of integers using two stacks (`a` and `b`) and a set of predefined operations, such as `sa` (swap the top two elements), `ra` (rotate the stack), and `pb` (push an element from one stack to another). 

The goal is to implement efficient sorting algorithms that minimize the number of operations required to sort the stack.

### **Learning Objectives**
- Understand and implement sorting algorithms with performance constraints.
- Use stacks and operations effectively.
- Optimize code for time and space complexity.

---

## 📂 **Project Structure**

```bash
.
├── include/             # Header files
│   ├── push_swap.h      # Core declarations for sorting
│   ├── stack.h          # Stack-specific declarations
│   └── utils.h          # Utility function declarations
├── src/                 # Source files implementing the main functionality
│   ├── main.c           # Entry point of the program
│   ├── push_swap.c      # Main logic for sorting
│   ├── stack_operations.c # Stack manipulation functions
│   ├── sort_small.c     # Sorting logic for small inputs (3-5 numbers)
│   ├── sort_large.c     # Sorting logic for large inputs (100+ numbers)
│   ├── input_validation.c # Input parsing and validation
│   ├── utils.c          # General-purpose helper functions
│   └── memory_management.c # Memory allocation and cleanup
├── tests/               # Test scripts and sample cases
│   ├── test_cases.txt   # List of input test cases
│   └── test.sh          # Automated test script
├── libft/               # Your libft implementation
├── Makefile             # Build system
└── README.md            # Documentation
```

---

## 🔄 **Changes in This Version**

### **Modular Structure**
- The project is structured into clearly defined modules:
  - **Stack Operations**: Manages stack manipulations like `push`, `swap`, and `rotate`.
  - **Sorting Logic**: Implements sorting for small and large inputs.
  - **Input Validation**: Ensures input is properly parsed and checked.
  - **Utilities**: General-purpose functions like error handling and memory cleanup.

### **Why This Structure?**
- **Modularity**: Each module has a specific responsibility, making the project easy to understand, debug, and extend.
- **Reusability**: Modules like stack operations and utilities can be reused in future projects (e.g., **fdf**).
- **Scalability**: Algorithms can be easily swapped or extended without affecting unrelated parts.

---

## 🛠️ **Technologies Used**

- **C Language**: The core language for implementing push_swap and integrating with **libft**.
- **Makefile**: Automates the build process for both **push_swap** and **libft**.
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

This will compile both the **push_swap** program and the **libft**, resulting in an executable for **push_swap**.

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

### **Test with Larger Inputs**:
You can test performance with larger datasets:
```bash
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG
```

---

## 🔨 **Push_Swap Functionality**

### 🔄 **Workflow**

**Push_Swap** follows this workflow:
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

This README should give you a polished and professional guide for your **Push_Swap project** while maintaining the structure and clarity you desire. Let me know if you need further modifications!
