#pragma once
#include "thuvien.h"


// 3. Lớp Bảng băm cơ bản
class HashTable {
private:
    static const int TABLE_SIZE = 10; // Kích thước mảng bucket
    HashNode* buckets[TABLE_SIZE]; // Mảng con trỏ quản lý từng ngăn

    // Hàm băm: Cộng mã ASCII của chuỗi CMND rồi chia lấy dư
    int hashFunction(string& cmnd);

public:
    HashTable();
    ~HashTable();

    // Các phương thức thao tác chính
    void insert(DocGia& r);
    HashNode* search(string& cmnd);
    bool remove(string& cmnd);
    void printTable();
    HashNode* sua(string &CMND, HashNode* dg);
    int getTableSize();
    HashNode* getBucket(int index);
};


