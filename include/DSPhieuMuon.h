#pragma once
#include <string>
#include "thuvien.h"

class DSPhieuMuon {
private:
    LinkedListNode* head;
    int count;

public:
    DSPhieuMuon();
    ~DSPhieuMuon();

    void addTicket(const PhieuMuon& ticket);
    PhieuMuon* searchTicket(const string& ticketId);
    bool removeTicket(const string& ticketId);
    void printTickets() const;
    int getCount() const { return count; }
    LinkedListNode* getHead() const { return head; }
    void clear();
};
