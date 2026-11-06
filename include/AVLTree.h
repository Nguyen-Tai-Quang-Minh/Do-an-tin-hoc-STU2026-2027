#pragma once
#include "thuvien.h"
class AVLTree
{
private:
    /* data */
    AVLNode* root;
    int height(AVLNode* node);
    int getBalance(AVLNode* node);
    AVLNode* RightRotate(AVLNode* node);
    AVLNode* LeftRotate(AVLNode* node);
    AVLNode* insertNode(AVLNode* node, Sach Sach);
    AVLNode* searchNode(AVLNode* node, string isbn);
    AVLNode* minValueNode(AVLNode* node);
    AVLNode* deleteNode(AVLNode* node, string isbn);
    void NLR(AVLNode* node);
    void destroyTree(AVLNode* node);
public:
    AVLTree(/* args */);
    ~AVLTree();
    void insert(Sach sach);
    bool search(string ISBN);
    bool xoa(string ISBN);
    void xuatNLR();
    AVLNode* getRoot() const { return root; }
    bool update(string& isbn, Sach& newInfo);
};


