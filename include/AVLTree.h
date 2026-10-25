#include "thuvien.h"
class AVLTree
{
private:
    /* data */
    AVLNode* root;
    int height(AVLNode* node);
    bool getBalance(AVLNode* node);
    AVLTree* RightRotate(AVLNode* node);
    AVLNode* LeftRotate(AVLNode* node);
    void NLR(AVLNode* node);
    void destroyTree(AVLNode* node);
public:
    AVLTree(/* args */);
    ~AVLTree();
    void insert(string ISBN, string ten, string tacgia, int namXB, int soluong);
    bool search(string ISBN);
    void xuatNLR();
};

