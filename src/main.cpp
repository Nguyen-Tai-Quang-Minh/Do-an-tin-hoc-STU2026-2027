#include "BSTree.h"

int main() {
    cout << "=== KIEM THU CAY TIM KIEM NHI PHAN (BST) ===" << endl << endl;

    // 1. Khởi tạo Cây AVL (Quản lý theo ISBN)
    AVLTree avl;
    avl.insert(Sach("978-0131103627", "C Programming Language", "Kernighan & Ritchie", "tloai1", 1988, 6767));
    avl.insert(Sach("978-0321563842", "The C++ Programming Language", "Bjarne Stroustrup", "tloai2", 2013, 3));
    avl.insert(Sach("978-0262033848", "Introduction to Algorithms", "Cormen et al.", "tloai3", 2009, 8));
    avl.insert(Sach("978-0132350884", "Clean Code", "Robert C. Martin", "tloai4", 2008, 4));

    cout << "--- 1. Danh sach trong cay AVL (Theo ISBN) ---" << endl;
    avl.xuatNLR();
    cout << endl;

    // 2. Chuyển đổi dữ liệu từ AVL sang BST
    BSTree bst;
    bst.getfromAVL(avl);

    // 3. In danh mục sách từ BST theo thứ tự bảng chữ cái (In-Order Traversal)
    cout << "--- 2. Danh sach trong cay BST (Theo Ten A-Z) ---" << endl;
    bst.printNLR();
    cout<<"xoa sach nao? ";
    string input;
    cin >> input;
    if (avl.xoa(input))
        cout<<"xoa thanh cong";
    else
        cout<<"welp";
    cout << "--- 2. Danh sach trong cay BST (Theo Ten A-Z) ---" << endl;
    bst.getfromAVL(avl);
    bst.printNLR();
    cout<<"tim sach nao? ";
    cin >> input;
    if (avl.search(input))
        cout<<"tim thanh cong, sach ton tai!";
    else
        cout<<"welp";
    cout << "--- 2. Danh sach trong cay BST (Theo Ten A-Z) ---" << endl;
    bst.getfromAVL(avl);
    bst.printNLR();
    cout<<"sua sach nao? ";
    cin >> input;
    Sach s = Sach("","","","",0,0);
    if (avl.search(input)){
        cout<<"tim thanh cong, sach ton tai!";
        cout<<"nhap tt sach:";
        cin>> s.ISBN;
        cin>> s.tacgia;
        cin>> s.ten;
        cin>> s.theloai;
        cin>> s.namXB;
        cin>> s.soluong;
    }
    else
        cout<<"welp";
    if (avl.update(input, s))
        cout<<"update thanh cong!";
    else
        cout<<"welp";
    cout << "--- 2. Danh sach trong cay BST (Theo Ten A-Z) ---" << endl;
    cout << "--- 2. Danh sach trong cay BST (Theo Ten A-Z) ---" << endl;
    bst.getfromAVL(avl);
    bst.printNLR();
    return 0;
}
