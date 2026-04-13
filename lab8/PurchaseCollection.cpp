#include "PurchaseCollection.h"

#include "CreditPurchase.h"

PurchaseCollection::PurchaseCollection(int s) {
    arr = new Purchase*[s];
    size = 0;
    maxSize = s;
}

PurchaseCollection::PurchaseCollection(const PurchaseCollection& pc) : PurchaseCollection(pc.size) {
    int pcSize = pc.size;
    for (int i = 0; i < pcSize; i++) {
        Purchase* curPur = pc.get(i);
        Purchase* newPur = curPur->clone();
        this->add(newPur);
    }
}

PurchaseCollection::~PurchaseCollection() {
    for (int i = 0; i < size; i++) {
        delete arr[i];
    }
    delete[] arr;
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
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j]->getKey() > arr[j + 1]->getKey()) {
                swap(j, j + 1);
            }
        }
    }
}

void PurchaseCollection::output() {
    if (size == 0) {
        cout << "Collection is empty\n";
        return;
    }

    cout << "Collection:\n";

    for (int i = 0; i < size; i++) {
        arr[i]->output();
    }
}

void PurchaseCollection::saveToFile(string fileName) {
    FILE* f = fopen(fileName.c_str(), "wt");
    if (!f) {
        throw string("PurchaseCollection::saveToFile: error opening file: ") + fileName;
    }
    
    fprintf(f, "%d\n", size);

	for (int i = 0; i < size; i++) {
	    arr[i]->saveToFile(f);
	    fprintf(f, "\n");
    }

    fclose(f);
}

void PurchaseCollection::loadFromFile(string fileName) {
    FILE* f = fopen(fileName.c_str(), "rt");
    if (!f) {
        throw string("PurchaseCollection::loadFromFile: error opening file: ") + fileName;
    }
    
    int pcSize = size;
    for (int i = 0; i < pcSize; i++) {
    	remove(0);
	}
    
    int collectionSize;
    fscanf(f, "%d\n", &collectionSize);
    
    char type[100];
    
    for (int i = 0; i < collectionSize; i++) {
    	fscanf(f, "%99s", type);
    	Purchase* curPur;

        if (string(type) == "Purchase") {
            curPur = new Purchase;
        }
        else {
            curPur = new CreditPurchase;
        }

        curPur->loadFromFile(f);
        add(curPur);
	}

    fclose(f);
}

void PurchaseCollection::operator+= (Purchase* p) {
    add(p);
}

void PurchaseCollection::operator+= (const Purchase& p) {
    *this += p.clone();
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
    return get(index);
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