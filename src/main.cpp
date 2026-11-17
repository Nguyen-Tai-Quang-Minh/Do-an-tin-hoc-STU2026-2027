#include "thuvien.h"
#include <iostream>
#include <string>
#include <cstdio>
#include "AVLTree.h"
#include "HashTable.h"
#include "DSPhieuMuon.h"
#include "TransactionArray.h"
#include "FileManager.h"

using namespace std;
int main() {
    // Khởi tạo các cấu trúc dữ liệu cốt lõi (Tuần 3 - 5)
    AVLTree libraryBooks;
    HashTable readerTable;
    DSPhieuMuon borrowList;
    TransactionArray transactionHistory;
    
    // Quản lý file nhị phân (.dat) thông qua con trỏ FILE*
    FileManager fileManager("data/"); 

    // Tự động đọc dữ liệu từ file khi khởi động chương trình (Yêu cầu mục 3.6 & 4.8)
    fileManager.loadAll(libraryBooks, readerTable, borrowList, transactionHistory);

    int choice = 0;
    do {
        menu();
        if (!(cin >> choice)) {
            cout << "[Loi] Vui long nhap mot so nguyen hop le!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        cin.ignore(); // Xóa ký tự xuống dòng trong bộ đệm

        switch (choice) {
            case 1: {
                // --- 1. QUẢN LÝ SÁCH (AVL TREE) ---
                cout << "\n--- 1. QUAN LY DANH MUC SACH ---\n";
                cout << "[1] Them sach moi\n";
                cout << "[2] Tim sach theo ISBN\n";
                cout << "[3] Xoa / Sua thong tin\n";
                cout << "[4] In danh muc\n";
                cout << "[5] Load tu file\n";
                cout << "Chon thao tac sach [1-4]: ";
                int subChoice;
                cin >> subChoice;
                cin.ignore();

                if (subChoice == 1) {
                    string isbn, title, author, theloai;
                    int year, qty;
                    cout << "Nhap ISBN: "; getline(cin, isbn);
                    cout << "Nhap Ten sach: "; getline(cin, title);
                    
                    cout << "Nhap the loai: "; getline(cin, theloai);
                    cout << "Nhap Nam xuat ban: "; cin >> year;
                    cout << "Nhap So luong: "; cin >> qty;
                    cin.ignore(2);
                    cout << "Nhap Tac gia: "; getline(cin, author);
                    

                    libraryBooks.insert(Sach(isbn, title, author, theloai, year, qty));
                    cout << "[Success] Them sach moi vao cay AVL thanh cong!\n";
                } 
                else if (subChoice == 2) {
                    string isbn;
                    cout << "Nhap ISBN can tim: "; getline(cin, isbn);
                    AVLNode* b = libraryBooks.nodesearchreturns(isbn);
                    if (b) {
                        cout << "[Tim thay] ISBN: " << b->Data.ISBN
                             << " | Ten: " << b->Data.ten
                             << " | Tac gia: " << b->Data.tacgia 
                             << " | Nam XB: " << b->Data.namXB
                             << " | The loai: " << b->Data.theloai
                             << " | SL: " << b->Data.soluong << "\n";
                    } else {
                        cout << "[Not Found] Khong tim thay sach co ISBN nay!\n";
                    }
                } 
                else if (subChoice == 3) {
                    cout << "Chon thao tac: [1] Xoa sach [2] Sua thong tin: ";
                    int action;
                    cin >> action;
                    cin.ignore();
                    if (action == 1) {
                        string isbn;
                        cout << "Nhap ISBN sach can xoa: "; getline(cin, isbn);
                        if (libraryBooks.xoa(isbn)) {
                            cout << "[Success] Xoa sach khoi cay AVL thanh cong!\n";
                        } else {
                            cout << "[Loi] Khong tim thay ISBN de xoa!\n";
                        }
                    } else if (action == 2) {
                        string isbn, title, author, theloai;
                        int year, qty;
                        cout << "Nhap ISBN sach can sua: "; getline(cin, isbn);
                        cout << "Nhap Ten moi: "; getline(cin, title);
                        cout << "Nhap Tac gia moi: "; getline(cin, author);
                        cout << "Nhap Nam XB moi: "; cin >> year;
                        cout << "Nhap So luong moi: "; cin >> qty;
                        cout << "Nhap the loai moi: "; cin >> theloai;
                        cin.ignore(3);
                        Sach s = Sach(isbn, title, author, theloai, year, qty);
                        if (libraryBooks.update(isbn, s)) {
                            cout << "[Success] Cap nhat thong tin sach thanh cong!\n";
                        } else {
                            cout << "[Loi] Khong tim thay ISBN de cap nhat!\n";
                        }
                    }
                } 
                else if (subChoice == 4) {
                    cout << "\n--- DANH MUC SACH TRONG THU VIEN ---\n";
                    libraryBooks.xuatNLR();
                }
                else if (subChoice == 5) {
                    if (fileManager.loadBooks(libraryBooks)) {
                        cout << "[Success] Nap danh muc sach tu file" <<" thanh cong!\n";
                    } else {
                        cout << "[Loi] Khong the mo file hoac file rong!\n";
                    }
                }
                break;
                
            }
            case 2: {
                // --- 2. QUẢN LÝ ĐỘC GIẢ (HASH TABLE) ---
                cout << "\n--- 2. QUAN LY DOC GIA (HASH TABLE) ---\n";
                cout << "[1] Them doc gia\n";
                cout << "[2] Tra cuu theo CMND\n";
                cout << "[3] Thong ke theo loai the (Chua co)\n";
                cout << "[4] load tu file\n";
                cout << "Chon thao tac doc gia [1-3]: ";
                int subChoice;
                cin >> subChoice;
                cin.ignore();

                if (subChoice == 1) {
                    //string cmnd, name, phone;
                    DocGia d;
                    cout << "Nhap CMND: "; getline(cin, d.CMND);
                    cout << "Nhap Ho ten: "; getline(cin, d.hoten);
                    cout << "Nhap SĐT: "; getline(cin, d.sdt);
                    cout << "Nhap email: "; getline(cin, d.email);
                    cout << "Nhap loai the: "; getline(cin, d.loaithe);

                    readerTable.insert(d);
                    cout << "[Success] Them doc gia vao bang bam thanh cong!\n";
                } 
                else if (subChoice == 2) {
                    string cmnd;
                    cout << "Nhap CMND can tra cuu: "; getline(cin, cmnd);
                    HashNode* r = readerTable.search(cmnd);
                    if (r) {
                        cout << "[Tim thay] CMND: " << r->Data.CMND 
                             << " | Ho ten: " << r->Data.hoten
                             << " | email: " << r->Data.email
                             << " | loai the: " << r->Data.loaithe
                             << " | SĐT: " << r->Data.sdt << "\n";
                    } else {
                        cout << "[Not Found] Khong tim thay doc gia co CMND nay!\n";
                    }
                } 
                else if (subChoice == 4) {
                    if (fileManager.loadReaders(readerTable)) {
                        cout << "[Success] Nap danh sach doc gia tu file" << " thanh cong!\n";
                    } else {
                        cout << "[Loi] Khong the mo file hoac file rong!\n";
                    }
                }
                else {
                    cout << "[Info] Chuc nang nay chua duoc xay dung.\n";
                }
                break;
            }
            case 3: {
                // --- 3. QUẢN LÝ MƯỢN - TRẢ SÁCH ---
                cout << "\n--- 3. QUAN LY MUON - TRA SACH ---\n";
                cout << "[1] Lap phieu muon\n";
                cout << "[2] Xem danh sach phieu muon & Lich su giao dich\n";
                cout << "[3] load tu file\n";
                cout << "Chon thao tac [1-2]: ";
                int subChoice;
                cin >> subChoice;
                cin.ignore();

                if (subChoice == 1) {
                    string bDate, dDate;
                    PhieuMuon p;
                    cout << "Nhap Ma phieu muon: "; getline(cin, p.maphieu);
                    cout << "Nhap CMND doc gia: "; getline(cin, p.CMND);
                    cout << "Nhap ISBN sach: "; getline(cin, p.ISBN);
                    cout << "Nhap Ngay hen tra (YYYY-MM-DD): "; getline(cin, p.ngayhethan);
                    cout << "Nhap Ngay muon (YYYY-MM-DD): "; getline(cin, p.ngaymuon);
                    p.trangthai = "BORROW";
                    TransactionRecord t;
                    t.transactionId = "TX_" + p.maphieu;
                    t.cmnd = p.CMND;
                    t.isbn = p.ISBN;
                    t.actionType = "BORROW";
                    t.timestamp = p.ngaymuon;
                    borrowList.addTicket(p);
                    transactionHistory.pushBack(t);
                    cout << "[Success] Lap phieu muon va ghi nhan lich su giao dich thanh cong!\n";
                } 
                else if (subChoice == 2) {
                    borrowList.printTickets();
                    transactionHistory.printHistory();
                }
                else if (subChoice == 3) {
                    bool tLoaded = fileManager.loadTickets(borrowList);
                    bool txLoaded = fileManager.loadTransactions(transactionHistory);

                    if (tLoaded || txLoaded) {
                        cout << "[Success] Nap du lieu muon tra tu file thanh cong!\n";
                    } else {
                        cout << "[Loi] Khong the tai du lieu tu file.\n";
                    }
                }
                break;
            }
            case 4: {
                // --- 4. GỢI Ý & TÌM KIẾM NÂNG CAO (Trie / Graph) ---
                cout << "\n[Info] Chuc nang Gợi ý & Tìm kiếm nâng cao (Trie/Graph) thuoc Giai đoạn 4 (Tuần 8), hien tai chua co!\n";
                break;
            }
            case 5: {
                // --- 5. LƯU TRỮ & THOÁT CHƯƠNG TRÌNH ---
                //fileManager.loadAll(libraryBooks, readerTable,  borrowList, transactionHistory);
                fileManager.saveAll(libraryBooks, readerTable, borrowList, transactionHistory);
                cout << "\n[Exit] Da tu động lưu toàn bộ dữ liệu xuống file nhị phân (.dat). Tam biệt!\n";
                break;
            }
            default: {
                cout << "[Loi] Lua chon khong hop le. Vui long chon tu 1 den 5!\n";
                break;
            }
        }
    } while (choice != 5);

    return 0;
}