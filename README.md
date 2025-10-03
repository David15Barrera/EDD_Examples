# EDD_Examples
Examples used for Edd's class

# B-Tree Implementation in C++

This project presents an educational implementation of a minimum-order **t=2** B-Tree in C++. This self-balancing data structure is used to store and manage alphabetical keys (`std::string`), simulating a menu of dishes.

The B-Tree ensures that search and insertion operations are performed efficiently, keeping the structure automatically balanced through the process of node splitting.

---

## Configuration and Compilation

To compile and run the project, you will need a C++ compiler (such as g++).

### Project Requirements
1. **C++ Compiler:** `g++` or another modern compiler is required.
2. **Graphviz (Optional):** Required if you want to generate visual tree diagrams (see **Visualization** section).

### Compilation Steps

Assuming you have saved the tree implementation in a file named `BTree.cpp`, compile both source files (`main.cpp` and `BTree.cpp`) and link them:

```bash
g++ main.cpp BTree.cpp -o arbolB