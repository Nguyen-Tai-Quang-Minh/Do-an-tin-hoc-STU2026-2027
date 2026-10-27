#include "thuvien.h"
void menu(){
    int x;
    do{
        cout << "+*+*+*+*+*+*MENU*+*+*+*+*+*+";
        cout <<"\n0: getout";
        cout <<"\n1: helo\n";
        cout << "=================================================================== \n ";
        cout << "HE THONG QUAN LY THU VIEN C++ \n";
        cout << "===================================================================\n";
        cout << "1. QUAN LY DANH MUC SACH (AVL TREE)\n";
        cout<< "[1] Them sach moi [2] Tim sach theo ISBN [3] Xoa / Sua thong tin [4] In danh muc (Inorder)\n";
        cout << "2. QUAN LY DOC GIA (HASH TABLE)\n";
        cout << "[1] Them doc gia [2] Tra cuu theo CMND\n";
        cout << "[3] Thong ke theo loai the\n";
        cout << "3. QUAN LY MUON - TRA SACH\n";
        cout << "[1] Lap phieu muon [2] Tra sach & Tinh tien phat\n";
        cout << "4. GOI Y & TIM KIEM NANG CAO\n";
        cout << "[1] Autocomplete ten sach (Trie) [2] Goi y cung the loai (Graph)\n";
        cout << "5. LUU TRU & THOAT CHUONG TRINH\n===================================================================";

        cin >> x;
        switch (x)
        {
        case 0:
            break;
        case 1:
            /* code */
            cout<<"helo\n";
            break;
        default:
            break;
        }
    }while(x!=0);
}