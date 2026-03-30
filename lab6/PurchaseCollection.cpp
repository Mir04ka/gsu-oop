#include "PurchaseCollection.h"

PurchaseCollection::PurchaseCollection(int s) {
    arr = new Purchase*[s];
    size = 0;
    maxSize = s;
}

PurchaseCollection::PurchaseCollection(const PurchaseCollection& pc) : PurchaseCollection(pc.size) {
    int pcSize = pc.size;
    for (int i = 0; i < pcSize; i++) {
        Purchase* curPur = pc.get(i);
        Purchase* newPur = new Purchase(curPur->getProductName(), curPur->getPrice(), curPur->getQuantity());
        this->add(newPur);
    }
}

PurchaseCollection::~PurchaseCollection() {
    for (int i = 0; i < size; i++) {
        delete arr[i];
    }
    delete[] arr;
}

void PurchaseCollection::operator+= (Purchase* p) {
    add(p);
}

void PurchaseCollection::operator+= (const Purchase& p) {
    Purchase* newPur = new Purchase(p);
    add(newPur);
}

void PurchaseCollection::operator-= (int index) {
    remove(index);
}

void PurchaseCollection::operator-= (string productName) {
    int pcSize = size;
    for (int i = 0; i < pcSize; i++) {
        if (arr[i]->getProductName() == productName) {
            remove(i);
            return;
        }
    }
}

Purchase* PurchaseCollection::operator[](int index) {
    if (index < 0 || index >= size) {
        return nullptr;
    }
    return arr[index];
}

Purchase* PurchaseCollection::operator[](string productName) {
    int pcSize = size;
    for (int i = 0; i < pcSize; i++) {
        if (arr[i]->getProductName() == productName) {
            return arr[i];
        }
    }

    return nullptr;
}

void PurchaseCollection::add(Purchase* p) {
    if (size == maxSize) {
        maxSize *= 2;

        Purchase** newArr = new Purchase*[maxSize];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
    }

    arr[size] = p;
    size++;
}

void PurchaseCollection::remove(int i) {
    if (i < 0 || i >= size) return;
    delete arr[i];
    for (int j = i; j < size - 1; j++) {
        arr[j] = arr[j + 1];
    }
    size--;
}

int PurchaseCollection::getSize() const {
    return size;
}

Purchase* PurchaseCollection::get(int i) const {
    if (i >= size || i < 0) {
        cout << "\nOut of range\n";
        return nullptr;
    }
    return arr[i];
}

void PurchaseCollection::swap(int i, int j) {
    Purchase* temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void PurchaseCollection::sort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i; j < size - 1; j++) {
            if (arr[j]->getProductName() > arr[j + 1]->getProductName()) {
                swap(j, j + 1);
            }
        }
    }
}

void PurchaseCollection::print() {
    if (size == 0) {
        cout << "Collection is empty\n";
        return;
    }

    cout << "Collection:\n";

    for (int i = 0; i < size; i++) {
        arr[i]->output();
    }
}