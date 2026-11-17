#pragma once
#include "thuvien.h"

class TransactionArray {
private:
    TransactionRecord* data; // Mảng động lưu trữ lịch sử
    int capacity; // Sức chứa hiện tại của mảng
    int size; // Số lượng phần tử thực tế đang dùng

    void resize(); // Tự động gấp đôi kích thước khi mảng đầy

public:
    TransactionArray(int initialCapacity = 10);
    ~TransactionArray();

    void pushBack(const TransactionRecord& record);
    TransactionRecord& getAt(int index) const;
    int getSize() const { return size; }
    void printHistory() const;
};