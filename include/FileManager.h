
#include <string>
#include <fstream>
#include "thuvien.h"
#include "AVLTree.h"
#include "DSPhieuMuon.h"
#include "HashTable.h"
#include "TransactionArray.h"
using namespace std;

class FileManager {
private:
    string dataDir;

    // Hàm hỗ trợ ghi/đọc chuỗi an toàn vào file nhị phân
    void writeString(FILE* out, const string& str);
    string readString(FILE* in);

    // Hàm đệ quy ghi các node của AVL Tree xuống file
    void serializeAVL(FILE* out, AVLNode* node);

public:
    FileManager(string dir = "data/");

    // Đọc/Ghi dữ liệu Sách (AVL Tree)
    bool saveBooks(AVLTree& avlTree);
    bool loadBooks(AVLTree& avlTree);

    // Đọc/Ghi dữ liệu Độc giả (Hash Table)
    bool saveReaders(HashTable& hashTable);
    bool loadReaders(HashTable& hashTable);
    bool saveTickets(DSPhieuMuon& PM);
    bool loadTickets(DSPhieuMuon& PM);
    bool saveTransactions(TransactionArray& history);
    bool loadTransactions(TransactionArray& history);
    void saveAll(AVLTree& books, HashTable& readers, DSPhieuMuon& tickets, TransactionArray& history);
    void loadAll(AVLTree& books, HashTable& readers, DSPhieuMuon& tickets, TransactionArray& history);
};