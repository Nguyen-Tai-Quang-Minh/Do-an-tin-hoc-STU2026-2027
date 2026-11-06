#pragma once
#include "thuvien.h"

class HashTable
{
private:
    static const int MAX =100;
    HashNode* table[MAX];
    int count;
};