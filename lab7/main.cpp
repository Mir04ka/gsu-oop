// Ларичев, вариант 30, работа 7
// Классы: покупка в магазине <- покупка в рассрочку
// Виртуальные методы

#include <iostream>

#include "CreditPurchase.h"
#include "Purchase.h"
#include "PurchaseCollection.h"

int main() {
    PurchaseCollection pc(1);

    CreditPurchase* pur1 = new CreditPurchase("Gold", 999.0, 1, 12, "Alfa");
    CreditPurchase* pur2 = new CreditPurchase("Apple", 9.0, 2, 1, "Belarus");
    CreditPurchase* pur3 = new CreditPurchase("Silver", 99.0, 3, 3, "Belagro");
    Purchase* pur4 = new Purchase("Milk", 1.33, 2);
    Purchase* pur5 = new Purchase("Cola", 2.33, 2);
    Purchase pur6("Bread", 1.00, 2);

    pc += pur1;
    pc += pur2;
    pc += pur3;
    pc += pur4;
    pc += pur5;
    pc += pur6;

    pc.print();

    pc.sort();

    cout << "\nAfter sort:\n";
    pc.print();

    FILE* f = fopen("Purchase.txt", "wt");
    pur5->saveToFile(f);
    fclose(f);

    Purchase loadedPurchase;
    f = fopen("Purchase.txt", "rt");
    loadedPurchase.loadFromFile(f);
    fclose(f);

    cout << "\nPurchase loaded from file:\n";
    loadedPurchase.output();

    f = fopen("CreditPurchase.txt", "wt");
    pur1->saveToFile(f);
    fclose(f);

    CreditPurchase loadedCreditPurchase;
    f = fopen("CreditPurchase.txt", "rt");
    loadedCreditPurchase.loadFromFile(f);
    fclose(f);

    cout << "\nCreditPurchase loaded from file:\n";
    loadedCreditPurchase.output();

    pc.saveToFile("Collection.txt");

    PurchaseCollection pc2(1);
    pc2.loadFromFile("Collection.txt");
    cout << "\nLoaded collection:\n";
    pc2.print();

    return 0;
}