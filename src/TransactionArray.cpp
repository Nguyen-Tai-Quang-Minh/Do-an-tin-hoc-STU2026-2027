
#include "TransactionArray.h"

TransactionArray::TransactionArray(int initialCapacity) {
    capacity = initialCapacity;
    size = 0;
    data = new TransactionRecord[capacity];
}

TransactionArray::~TransactionArray() {
    delete[] data;
}

void TransactionArray::resize() {
    capacity *= 2;
    TransactionRecord* newData = new TransactionRecord[capacity];
    for (int i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

void TransactionArray::pushBack(const TransactionRecord& record) {
    if (size >= capacity) {
        resize();
    }
    data[size++] = record;
}

TransactionRecord& TransactionArray::getAt(int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of bounds in TransactionArray!");
    }
    return data[index];
}

void TransactionArray::printHistory() const {
    cout << "\n================== LICH SU GIAO DICH (DYNAMIC ARRAY) ==================\n";
    if (size == 0) {
        cout << "Chua co giao dịch nao ghi nhận.\n";
    }
    for (int i = 0; i < size; ++i) {
        cout << "[" << data[i].timestamp << "] " 
             << data[i].actionType << " - Ma GD: " << data[i].transactionId 
             << " (CMND: " << data[i].cmnd << ", ISBN: " << data[i].isbn << ")\n";
    }
    cout << "========================================================================\n\n";
}


