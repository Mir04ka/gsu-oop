#ifndef GSU_OOP_PURCHASECOLLECTION_H
#define GSU_OOP_PURCHASECOLLECTION_H

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

template <typename T>
class PurchaseCollection {
private:
    T** arr;
    int size;
    int maxSize;

public:
    PurchaseCollection(int s = 1);
    PurchaseCollection(const PurchaseCollection& pc);
    ~PurchaseCollection();

    void add(T* p);
    void remove(int i);
    int getSize() const;
    T* get(int i) const;
    void swap(int i, int j);
    void sort();
    void output();

    void saveToFile(string fileName);

    template <typename ChildT>
    void loadFromFile(string fileName);

    void operator+= (T* p);
    void operator+= (const T& p);
    void operator-= (int index);
    void operator-= (string productName);
    T* operator[](int index);
    T* operator[](string productName);
};

template <typename T>
PurchaseCollection<T>::PurchaseCollection(int s) {
    arr = new T*[s];
    size = 0;
    maxSize = s;
}

template <typename T>
PurchaseCollection<T>::PurchaseCollection(const PurchaseCollection& pc) : PurchaseCollection(pc.size) {
    int pcSize = pc.size;
    for (int i = 0; i < pcSize; i++) {
        T* curPur = pc.get(i);
        T* newPur = curPur->clone();
        this->add(newPur);
    }
}

template <typename T>
PurchaseCollection<T>::~PurchaseCollection() {
    for (int i = 0; i < size; i++) {
        delete arr[i];
    }
    delete[] arr;
}

template <typename T>
void PurchaseCollection<T>::add(T* p) {
    if (size == maxSize) {
        maxSize *= 2;

        T** newArr = new T*[maxSize];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
    }

    arr[size] = p;
    size++;
}

template <typename T>
void PurchaseCollection<T>::remove(int i) {
    if (i < 0 || i >= size) return;
    delete arr[i];
    for (int j = i; j < size - 1; j++) {
        arr[j] = arr[j + 1];
    }
    size--;
}

template <typename T>
int PurchaseCollection<T>::getSize() const {
    return size;
}

template <typename T>
T* PurchaseCollection<T>::get(int i) const {
    if (i >= size || i < 0) {
        cout << "\nOut of range\n";
        return nullptr;
    }
    return arr[i];
}

template <typename T>
void PurchaseCollection<T>::swap(int i, int j) {
    T* temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

template <typename T>
void PurchaseCollection<T>::sort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j]->getKey() > arr[j + 1]->getKey()) {
                swap(j, j + 1);
            }
        }
    }
}

template <typename T>
void PurchaseCollection<T>::output() {
    if (size == 0) {
        cout << "Collection is empty\n";
        return;
    }

    cout << "Collection:\n";

    for (int i = 0; i < size; i++) {
        arr[i]->output();
    }
}

template <typename T>
void PurchaseCollection<T>::saveToFile(string fileName) {
    ofstream fout(fileName);

    if (!fout) {
        throw string("PurchaseCollection::saveToFile: error opening file: ") + fileName;
    }

	for (int i = 0; i < size; i++) {
	    arr[i]->saveToFile(fout);
	    fout << "\n";
    }

    fout.close();
}

template <typename T>
template <typename ChildT>
void PurchaseCollection<T>::loadFromFile(string fileName) {
    ifstream fin(fileName);

    if (!fin) {
        throw string("PurchaseCollection::loadFromFile: error opening file: ") + fileName;
    }

    string type;

    while (fin >> type) {
        T* curPur;

        if (type == "Purchase") {
            curPur = new T;
        }
        else {
            curPur = new ChildT;
        }

        curPur->loadFromFile(fin);
        add(curPur);
    }
}

template <typename T>
void PurchaseCollection<T>::operator+= (T* p) {
    add(p);
}

template <typename T>
void PurchaseCollection<T>::operator+= (const T& p) {
    *this += p.clone();
}

template <typename T>
void PurchaseCollection<T>::operator-= (int index) {
    remove(index);
}

template <typename T>
void PurchaseCollection<T>::operator-= (string productName) {
    int pcSize = size;
    for (int i = 0; i < pcSize; i++) {
        if (arr[i]->getProductName() == productName) {
            remove(i);
            return;
        }
    }
}

template <typename T>
T* PurchaseCollection<T>::operator[](int index) {
    return get(index);
}

template <typename T>
T* PurchaseCollection<T>::operator[](string productName) {
    int pcSize = size;
    for (int i = 0; i < pcSize; i++) {
        if (arr[i]->getProductName() == productName) {
            return arr[i];
        }
    }

    return nullptr;
}

#endif //GSU_OOP_PURCHASECOLLECTION_H