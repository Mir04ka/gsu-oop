#include "PurchaseCollection.h"

PurchaseCollection::PurchaseCollection() {
    size = 0;
}

PurchaseCollection::~PurchaseCollection() {
    for (int i = 0; i < size; i++) {
        delete arr[i];
    }
}

void PurchaseCollection::add(Purchase* p) {
    arr[size] = p;
    size++;
}

void PurchaseCollection::remove(int i) {
    delete arr[i];
    for (int j = i; j < size - 1; j++) {
        arr[j] = arr[j + 1];
    }
    size--;
}

int PurchaseCollection::getSize() {
    return size;
}

Purchase* PurchaseCollection::get(int i) {
    return arr[i];
}

void PurchaseCollection::swap(int i, int j) {
    Purchase* temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void PurchaseCollection::sort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
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