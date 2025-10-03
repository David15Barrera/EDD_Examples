#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <string>
using namespace std;

class BTreeNode {

    public:
        string *keys;      
        int t;             
        BTreeNode **C;
        int n;             
        bool leaf;         

        BTreeNode(int _t, bool _leaf);

        void traverse();                       
        BTreeNode* search(const string &k);    

        void insertNonFull(const string &k);   
        void splitChild(int i, BTreeNode *y);  
        void generateDotRec(ofstream &out);
};

class BTree {
public:
    BTreeNode *root;  
    int t;            

    BTree(int _t);

    void traverse();
    BTreeNode* search(const string &k);
    void insert(const string &k);
    
    void generateDot(const string &filename);
};


#endif
