#include "FileManager.h"
FileManager::FileManager(string dir) {
    dataDir = dir;
}
void FileManager::writeString(FILE* out, const string& str){
    size_t lenght = str.size();
    fwrite(&lenght, sizeof(lenght), 1, out);
    if(lenght>0){
        fwrite(str.data(), sizeof(char), lenght, out);
    }
}
string FileManager::readString(FILE* in){
    size_t lenght= 0;
    if(fread(&lenght, sizeof(lenght), 1, in)!= 1)
        return "";
    if(lenght==0)
        return "";
    string str(lenght, '\0');
    fread(&str[0], sizeof(char), lenght, in);
    return str;
}
void FileManager::serializeAVL(FILE* out, AVLNode* node){
    if(!node) return;
    writeString(out, node->Data.ISBN);
    writeString(out, node->Data.ten);
    writeString(out, node->Data.tacgia);
    writeString(out, node->Data.theloai);
    fwrite(&node->Data.namXB, sizeof(node->Data.namXB), 1, out);
    fwrite(&node->Data.soluong, sizeof(node->Data.namXB), 1, out);
    serializeAVL(out, node->left);
    serializeAVL(out, node->right);
}
bool FileManager::saveBooks(AVLTree& avlTree){
    FILE* f = fopen((dataDir+"sach.dat").c_str(), "wb");
    if(!f){
        cout<<"\n ko mo file dc";
        return false;
    }
    serializeAVL(f, avlTree.getRoot());
    fclose(f);
    return true;
}
bool FileManager::loadBooks(AVLTree& avlTree){
    FILE* f = fopen((dataDir+"sach.dat").c_str(), "rb");
    if(!f){
        cout<<"\n ko mo file dc";
        return false;
    }
    while(true){
        string isbn = readString(f);
        if(isbn.empty())
            break;
        string ten = readString(f);
        string tacgia = readString(f);
        string theloai = readString(f);
        int namXB= 0;
        int soluong = 0;
        fread(&namXB, sizeof(namXB), 1, f);
        fread(&soluong, sizeof(soluong), 1, f);
        Sach s = Sach(isbn, ten, tacgia, theloai, namXB, soluong);
        avlTree.insert(s);
    }
    fclose(f);
    return true;
}
// Đọc/Ghi dữ liệu Độc giả (Hash Table)
bool FileManager::saveReaders(HashTable& hashTable){
    FILE* f = fopen((dataDir+ "docgia.dat").c_str(), "wb");
    if(!f)
        return false;
    for(int i = 0; i<hashTable.getTableSize(); ++i){
        HashNode* current = hashTable.getBucket(i);
        while(current!=nullptr){
            writeString(f, current->Data.CMND);
            writeString(f, current->Data.hoten);
            writeString(f, current->Data.email);
            writeString(f, current->Data.sdt);
            writeString(f, current->Data.loaithe);
            current = current->link;
        }
    }
    fclose(f);
    return true;
}
bool FileManager::loadReaders(HashTable& hashTable){
    FILE* f = fopen((dataDir+ "docgia.dat").c_str(), "rb");
    if(!f)
        return false;
    while(true){
        string CMND = readString(f);
        if(CMND.empty())
            break;
        DocGia d;
        d.CMND = CMND;
        d.hoten = readString(f);
        d.email = readString(f);
        d.sdt = readString(f);
        d.loaithe = readString(f);
        hashTable.insert(d);
    }
    fclose(f);
    return true;
}
bool FileManager::saveTickets(DSPhieuMuon& PM){
    FILE* f = fopen((dataDir+ "phieumuon.dat").c_str(), "wb");
    if(!f)
        return false;
    LinkedListNode* current = PM.getHead();
    while(current!=nullptr){
        //PM.addTicket
        writeString(f, current->data.CMND);
        writeString(f, current->data.ISBN);
        writeString(f, current->data.maphieu);
        writeString(f, current->data.ngaymuon);
        writeString(f, current->data.ngayhethan);
       
        writeString(f, current->data.trangthai);
        current = current->next;
    }
    fclose(f);
    return true;
}
bool FileManager::loadTickets(DSPhieuMuon& PM){
    FILE* f = fopen((dataDir+ "phieumuon.dat").c_str(), "rb");
    if(!f)
        return false;

    while(true){
        //PM.addTicket
        PhieuMuon p;
        p.CMND = readString(f);
        if(p.CMND.empty())
            break;
        p.ISBN = readString(f);
        p.maphieu = readString(f);
        p.ngaymuon = readString(f);
        p.ngayhethan = readString(f);
        
        p.trangthai = readString(f);
        PM.addTicket(p);
    }
    fclose(f);
    return true;
}
bool FileManager::saveTransactions(TransactionArray& history) {
    FILE* file = fopen((dataDir + "history.dat").c_str(), "wb");
    if (!file) {
        cout << "[Loi] Khong the mo file " << (dataDir + "history.dat") << " de ghi!\n";
        return false;
    }

    int count = history.getSize();
    fwrite(&count, sizeof(count), 1, file);

    for (int i = 0; i < count; ++i) {
        const TransactionRecord& rec = history.getAt(i);
        writeString(file, rec.transactionId);
        writeString(file, rec.cmnd);
        writeString(file, rec.isbn);
        writeString(file, rec.actionType);
        writeString(file, rec.timestamp);
    }

    fclose(file);
    return true;
}

bool FileManager::loadTransactions(TransactionArray& history) {
    FILE* file = fopen((dataDir + "history.dat").c_str(), "rb");
    if (!file) return false;

    int count = 0;
    if (fread(&count, sizeof(count), 1, file) != 1) {
        fclose(file);
        return false;
    }

    for (int i = 0; i < count; ++i) {
        string transactionId = readString(file);
        string cmnd = readString(file);
        string isbn = readString(file);
        string actionType = readString(file);
        string timestamp = readString(file);

        history.pushBack(TransactionRecord(transactionId, cmnd, isbn, actionType, timestamp));
    }

    fclose(file);
    return true;
}

// =========================================================================
// 5. TIỆN ÍCH LƯU / NẠP TOÀN BỘ HỆ THỐNG
// =========================================================================
void FileManager::saveAll(AVLTree& books, HashTable& readers, DSPhieuMuon& tickets, TransactionArray& history) {
    saveBooks(books);
    saveReaders(readers);
    saveTickets(tickets);
    saveTransactions(history);
    cout << "[Success] Da luu toan bo du lieu he thong xuong thu muc " << dataDir << "\n";
}

void FileManager::loadAll(AVLTree& books, HashTable& readers, DSPhieuMuon& tickets, TransactionArray& history) {
    loadBooks(books);
    loadReaders(readers);
    loadTickets(tickets);
    loadTransactions(history);
    cout << "[Success] Da nap du lieu he thong tu thu muc " << dataDir << "\n";
}



