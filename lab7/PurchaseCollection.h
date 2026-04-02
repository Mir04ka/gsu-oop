#ifndef GSU_OOP_PURCHASECOLLECTION_H
#define GSU_OOP_PURCHASECOLLECTION_H

#include "Purchase.h"

class PurchaseCollection {
private:
    Purchase** arr;
    int size;
    int maxSize;

public:
    PurchaseCollection(int s);
    PurchaseCollection(const PurchaseCollection& pc);
    ~PurchaseCollection();

    void add(Purchase* p);
    void remove(int i);
    int getSize() const;
    Purchase* get(int i) const;
    void swap(int i, int j);
    void sort();
    void print();

    void saveToFile(string fileName);
    void loadFromFile(string fileName);

    void operator+= (Purchase* p);
    void operator+= (const Purchase& p);
    void operator-= (int index);
    void operator-= (string productName);
    Purchase* operator[](int index);
    Purchase* operator[](string productName);
};

#endif //GSU_OOP_PURCHASECOLLECTION_H