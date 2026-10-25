#include <iostream>
using namespace std;
struct Sach {
    string ISBN;
    string ten;
    string tacgia;
    int namXB;
    int soluong;
};
struct DocGia{
    string CMND;
    string hoten;
    string email;
    string sdt;
    string loaithe;
};
struct Date{
    int ngay;
    int thang;
    int nam;
};
struct PhieuMuon{
    string maphieu;
    string CMND;
    string ISBN;
    Date ngaymuon;
    Date ngayhethan;
};
struct AVLNode{
    string Data;
    AVLNode* left;
    AVLNode* right;
    int height;
};
void menu();