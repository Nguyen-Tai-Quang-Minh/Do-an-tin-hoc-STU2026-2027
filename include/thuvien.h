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
    Sach(string sisbn, string sten, string stacgia, string stloai, int nam, int sl) : ISBN(sisbn), ten(sten), tacgia(stacgia), theloai(stloai), namXB(nam), soluong(sl){}
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
    string ngaymuon;
    string ngayhethan;
    string trangthai;
    //PhieuMuon() : maphieu(""), CMND(""), ISBN(""), ngaymuon(), ngayhethan(""), trangthai("muon") {}
    //PhieuMuon(string tid, string c, string i, Date bDate, Date dDate, string stat) : maphieu(tid), CMND(c), ISBN(i), ngaymuon(bDate), ngayhethan(dDate), trangthai(stat) {}
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
    HashNode(DocGia r) : Data(r), link(nullptr) {}
};
struct TransactionRecord {
    string transactionId;
    string cmnd;
    string isbn;
    string actionType; // "BORROW" hoặc "RETURN"
    string timestamp;

    TransactionRecord() : transactionId(""), cmnd(""), isbn(""), actionType(""), timestamp("") {}
    TransactionRecord(string tid, string c, string i, string action, string time)
        : transactionId(tid), cmnd(c), isbn(i), actionType(action), timestamp(time) {}
};
struct LinkedListNode {
    PhieuMuon data;
    LinkedListNode* next;

    LinkedListNode(PhieuMuon t) : data(t), next(nullptr) {}
};
void menu();