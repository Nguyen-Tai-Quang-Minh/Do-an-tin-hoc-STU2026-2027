#pragma once
#include <iostream>
using namespace std;
struct Sach {
    string ISBN;
    string ten;
    string tacgia;
    string theloai;
    int namXB;
    int soluong;
    Sach(string sisbn, string sten, string stacgia, string stloai, int nam, int sl): ISBN(sisbn), ten(sten), tacgia(stacgia), theloai(stloai), namXB(nam), soluong(sl){}
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
    Sach Data;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode(Sach s) : Data(s), left(nullptr), right(nullptr), height(1){}
};
struct BSTNode
{
    /* data */
    Sach Data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(Sach s): Data(s), left(nullptr),right(nullptr) {}
};
struct HashNode{
    DocGia Data;
    HashNode* link;
};
struct TransactionRecord{
    string TransactionID;
    string CMND;
    string ISBN;
    string type;
    string timestamp;
};
void menu();