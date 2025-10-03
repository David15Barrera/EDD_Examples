# EDD_Examples
Examples used for Edd's class

# 🌳 Implementación del Árbol B (B-Tree) en C++

Este proyecto presenta una implementación didáctica de un **Árbol B** de orden mínimo **t=2** en C++. Esta estructura de datos auto-balanceada se utiliza para almacenar y gestionar claves alfabéticas (`std::string`), simulando un menú de platillos.

El Árbol B garantiza que las operaciones de búsqueda e inserción se realicen de manera eficiente, manteniendo la estructura balanceada automáticamente mediante el proceso de división de nodos.

---

## Configuración y Compilación

Para compilar y ejecutar el proyecto, necesitarás un compilador de C++ (como g++).

### Pasos de Compilación

Asumiendo que has guardado la implementación del árbol en un archivo llamado `BTree.cpp`, compila ambos archivos fuente (`main.cpp` y `BTree.cpp`) y enlázalos:

```bash
g++ main.cpp BTree.cpp -o arbolB