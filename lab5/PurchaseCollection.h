#ifndef GSU_OOP_PURCHASECOLLECTION_H
#define GSU_OOP_PURCHASECOLLECTION_H

#include "Purchase.h"

class PurchaseCollection {
private:
    Purchase* arr[25];
    int size;

public:
    PurchaseCollection();
    ~PurchaseCollection();

    void add(Purchase* p);
    void remove(int i);
    int getSize();
    Purchase* get(int i);
    void swap(int i, int j);
    void sort();
    void print();
};

#endif //GSU_OOP_PURCHASECOLLECTION_H