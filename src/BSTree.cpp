#include "BSTree.h"

BSTree::BSTree() : root(nullptr) {}
BSTree::~BSTree() {
    clearTree(root);
}
void BSTree::clearTree(BSTNode* node) {
if (node != nullptr) {
    clearTree(node->left);
    clearTree(node->right);
    delete node;
}
}
void BSTree::clear() {
clearTree(root);
root = nullptr;
}
BSTNode* BSTree::insertnode(BSTNode* node, Sach& book) {
    if (node == nullptr) {
        return new BSTNode(book);
    }
    // Sort alphabetically by Sach Title
    if (book.ten < node->Data.ten) {
        node->left = insertnode(node->left, book);
    } else {
        node->right = insertnode(node->right, book);
    }
        return node;
}
void BSTree::insert(Sach& book) {
    root = insertnode(root, book);
}
void BSTree::retrievefromAVL(AVLNode* avlNode) {
    if (avlNode != nullptr) {
        insert(avlNode->Data);
        retrievefromAVL(avlNode->left);
        retrievefromAVL(avlNode->right);
    }
}
void BSTree::getfromAVL(AVLTree& avl) {
    clear();
    retrievefromAVL(avl.getRoot());
}
void BSTree::NLR(BSTNode* node) {
    if (node != nullptr) {
        NLR(node->left);
        cout << "[Title: " << node->Data.ten
        << " | ISBN: " << node->Data.ISBN
        << " | Author: " << node->Data.tacgia
        << " | Year: " << node->Data.namXB
        << " | Available: " << node->Data.soluong << "]\n";
        NLR(node->right);
    }
}
void BSTree::printNLR() {
    NLR(root);
}

