#pragma once
#include "thuvien.h"
#include "AVLTree.h"
class BSTree{
private:
    BSTNode* root;
    void retrievefromAVL(AVLNode* root);
    BSTNode* insertnode(BSTNode* bst, Sach &s);
    void NLR(BSTNode* node);
    void clearTree(BSTNode* node);
public:
    BSTree();
    ~BSTree();
    void insert(Sach &s);
    void getfromAVL(AVLTree& tree);
    void printNLR();
    void clear();
};