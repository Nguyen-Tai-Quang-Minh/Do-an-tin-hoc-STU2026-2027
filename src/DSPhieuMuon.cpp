#include "DSPhieuMuon.h"

DSPhieuMuon::DSPhieuMuon() : head(nullptr), count(0) {}

DSPhieuMuon::~DSPhieuMuon() {
    clear();
}

void DSPhieuMuon::clear() {
    LinkedListNode* current = head;
    while (current != nullptr) {
        LinkedListNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    count = 0;
}

void DSPhieuMuon::addTicket(const PhieuMuon& ticket) {
    LinkedListNode* newNode = new LinkedListNode(ticket);
    newNode->next = head;
    head = newNode;
    count++;
}

PhieuMuon* DSPhieuMuon::searchTicket(const string& maphieu) {
    LinkedListNode* current = head;
    while (current != nullptr) {
        if (current->data.maphieu == maphieu) {
            return &(current->data);
        }
        current = current->next;
    }
    return nullptr;
}

bool DSPhieuMuon::removeTicket(const string& maphieu) {
    LinkedListNode* current = head;
    LinkedListNode* prev = nullptr;

    while (current != nullptr) {
        if (current->data.maphieu == maphieu) {
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            count--;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

void DSPhieuMuon::printTickets() const {
    cout << "\n==================== DANH SACH PHIEU MUON ====================\n";
    LinkedListNode* current = head;
    if (!current) {
        cout << "Danh sach phieu muon hien dang trong.\n";
    }
    while (current != nullptr) {
        cout << "Ma Phieu: " << current->data.maphieu 
             << " | CMND: " << current->data.CMND 
             << " | ISBN: " << current->data.ISBN
             << " | ngay muon : " << current->data.ngaymuon
             << " | ngay hen tra: " << current->data.ngayhethan 
             << " | Trang Thai: " 
             << current->data.trangthai << "\n";
        current = current->next;
    }
    cout << "==============================================================\n\n";
}



