#include "BTree.h"

int main() {
    BTree menu(2);

    string platillos[] = {
        "Pizza", "Taco", "Sushi", "Hamburguesa", 
        "Ensalada", "Burrito", "Ramen", "Lasagna"
    };

    for (const string &p : platillos) menu.insert(p);

    cout << "Arbol B => Menu ordenado:\n";
    menu.traverse();

    string buscar = "Ramen";
    cout << "\n Buscando " << buscar << ": ";
    cout << (menu.search(buscar) != nullptr ? "Encontrado" : "No encontrado") << endl;


    menu.generateDot("btree.dot");
    system("dot -Tpng btree.dot -o btree.png");
    cout << "Imagen del Arbol: btree.png\n";

    return 0;
}
