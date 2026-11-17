
#include "HashTable.h"

// Khởi tạo tất cả các ngăn ban đầu là rỗng (nullptr)
HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        buckets[i] = nullptr;
    }
}

// Hàm hủy: Thu hồi toàn bộ bộ nhớ đã cấp phát động
HashTable::~HashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        HashNode* current = buckets[i];
        while (current != nullptr) {
            HashNode* temp = current;
            current = current->link;
            delete temp;
        }
        buckets[i] = nullptr;
    }
}

// Thuật toán băm: Cộng dồn mã ASCII rồi chia lấy dư cho TABLE_SIZE
int HashTable::hashFunction(string& CMND) {
    int sum = 0;
    for (char c : CMND) {
        sum += c;
    }
    return sum % TABLE_SIZE;
}

// 1. THÊM ĐỘC GIẢ
void HashTable::insert(DocGia& r) {
    if (r.CMND.empty()) return;

    // Kiểm tra nếu đã tồn tại CMND thì không thêm trùng
    if (search(r.CMND) != nullptr) {
        cout << "[Loi] CMND " << r.CMND << " da ton tai trong he thong!\n";
        return;
    }

    int index = hashFunction(r.CMND);
    HashNode* newHashNode = new HashNode(r);

    // Chèn vào đầu danh sách liên kết tại ngăn (Separate Chaining - O(1))
    newHashNode->link = buckets[index];
    buckets[index] = newHashNode;

    cout << "[Success] Da them doc gia: " << r.hoten << " (Ngan " << index << ")\n";
}

// 2. TÌM KIẾM ĐỘC GIẢ THEO CMND
HashNode* HashTable::search(string& CMND) {
    int index = hashFunction(CMND);
    HashNode* current = buckets[index];

    while (current != nullptr) {
        if (current->Data.CMND == CMND) {
            return current; // Tìm thấy
        }
        current = current->link;
    }
    return nullptr; // Không tìm thấy
}
HashNode* HashTable:: sua(string &CMND, HashNode* dg){
    int index = hashFunction(CMND);
    HashNode* current = buckets[index];

    while (current != nullptr) {
        if (current->Data.CMND == CMND) {
            current->Data = dg->Data;
            return current; // Tìm thấy
        }
        current = current->link;
    }
    return nullptr; // Không tìm thấy
}
// 3. XÓA ĐỘC GIẢ THEO CMND
bool HashTable::remove(string& CMND) {
    int index = hashFunction(CMND);
    HashNode* current = buckets[index];
    HashNode* prev = nullptr;

    while (current != nullptr) {
        if (current->Data.CMND == CMND) {
            if (prev == nullptr) {
                // Xóa node đầu tiên trong ngăn
                buckets[index] = current->link;
            } else {
                // Xóa node ở giữa hoặc cuối
                prev->link = current->link;
            }
            delete current;
            cout << "[Success] Da xoa doc gia co CMND: " << CMND << "\n";
            return true;
        }
        prev = current;
        current = current->link;
    }
    cout << "[Loi] Khong tim thay doc gia co CMND " << CMND << " de xoa!\n";
    return false;
}

// 4. IN TOÀN BỘ BẢNG BĂM (PHỤC VỤ DEMO / KIỂM THỬ)
void HashTable::printTable() {
    cout << "\n================ DANH SACH DOC GIA (HASH TABLE) ================\n";
    for (int i = 0; i < TABLE_SIZE; ++i) {
        cout << "Ngan [" << i << "]: ";
        HashNode* current = buckets[i];
        if (!current) {
            cout << "Rong\n";
        } else {
            while (current) {
                cout << " -> [" << current->Data.CMND << " | " << current->Data.hoten << "]";
                current = current->link;
            }
            cout << "\n";
        }
    }
    cout << "=================================================================\n\n";
}
int HashTable::getTableSize(){
    return TABLE_SIZE;
}
HashNode* HashTable::getBucket(int index){
    return (index >= 0 && index < TABLE_SIZE) ? buckets[index] : nullptr;
}
