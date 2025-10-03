#include "BTree.h"
#include <fstream>

// ---- Arbol B ----
BTreeNode::BTreeNode(int _t, bool _leaf) {
    t = _t;
    leaf = _leaf;
    keys = new string[2*t-1];
    C = new BTreeNode*[2*t];
    n = 0;
}

//Recorremos y mostramos las claves del subárbol de forma ordenada
//In-order 
void BTreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (!leaf) C[i]->traverse();
        cout << " " << keys[i];
    }
    if (!leaf) C[i]->traverse();
}
// Busqueda
BTreeNode* BTreeNode::search(const string &k) {
    int i = 0;

    while (i < n && k > keys[i]) i++;
        
        if (i < n && keys[i] == k) return this;
        if (leaf) return nullptr;

    return C[i]->search(k);
}

//Clave de forma Recursiva
void BTreeNode::insertNonFull(const string &k) {
    int i = n-1;
    if (leaf) {
        while (i >= 0 && keys[i] > k) {
            keys[i+1] = keys[i];
            i--;
        }
        keys[i+1] = k;
        n++;
    } else {
        while (i >= 0 && keys[i] > k) i--;
        if (C[i+1]->n == 2*t-1) {
            splitChild(i+1, C[i+1]);
            if (keys[i+1] < k) i++;
        }
        C[i+1]->insertNonFull(k);
    }
}

//Balanceo
void BTreeNode::splitChild(int i, BTreeNode *y) {
    BTreeNode *z = new BTreeNode(y->t, y->leaf);
    z->n = t-1;

    for (int j=0; j<t-1; j++) z->keys[j] = y->keys[j+t];
    if (!y->leaf) {
        for (int j=0; j<t; j++) z->C[j] = y->C[j+t];
    }
    y->n = t-1;

    for (int j=n; j>=i+1; j--) C[j+1] = C[j];
    C[i+1] = z;

    for (int j=n-1; j>=i; j--) keys[j+1] = keys[j];
    keys[i] = y->keys[t-1];
    n++;
}

// ---- BTree ----
//Clase complemta y manejo de la Raiz

BTree::BTree(int _t) {
    root = nullptr;
    t = _t;
}

void BTree::traverse() {
    if (root != nullptr) root->traverse();
}

BTreeNode* BTree::search(const string &k) {
    return (root == nullptr) ? nullptr : root->search(k);
}

void BTree::insert(const string &k) {
    if (root == nullptr) {
        root = new BTreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
    } else {
        if (root->n == 2*t-1) {
            BTreeNode *s = new BTreeNode(t, false);
            s->C[0] = root;
            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0] < k) i++;
            s->C[i]->insertNonFull(k);

            root = s;
        } else {
            root->insertNonFull(k);
        }
    }
}

// Creacion del Graphiz
void BTree::generateDot(const string &filename) {
    ofstream out(filename);
    out << "digraph BTree {\n";
    out << "  node [shape=record];\n";
    if (root != nullptr) root->generateDotRec(out);
    out << "}\n";
    out.close();
}


void BTreeNode::generateDotRec(ofstream &out) {
    out << "  node" << this << " [label=\"";
    for (int i = 0; i < n; i++) {
        out << keys[i];
        if (i < n - 1) out << " | ";
    }
    out << "\"];\n";

    if (!leaf) {
        for (int i = 0; i <= n; i++) {
            out << "  node" << this << " -> node" << C[i] << ";\n";
            C[i]->generateDotRec(out);
        }
    }


}

