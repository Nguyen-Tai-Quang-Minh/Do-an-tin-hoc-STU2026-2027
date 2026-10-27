#include <iostream>
using namespace std;
struct Sach {
    string ISBN;
    string ten;
    string tacgia;
    string theloai;
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
    string trangthai;
};
struct AVLNode{
    string Data;
    AVLNode* left;
    AVLNode* right;
    int height;
};
struct TransactionRecord{
    string TransactionID;
    string CMND;
    string ISBN;
    string type;
    string timestamp;
};
void menu();