// Ларичев, вариант 30, работа 7
// Классы: покупка в магазине <- покупка в рассрочку
// Виртуальные методы

#include <iostream>

#include "CreditPurchase.h"
#include "Purchase.h"
#include "PurchaseCollection.h"

int main() {
	Purchase* newPur;
	newPur = new CreditPurchase("TEST2", 99.0, 3, 3, "Belagro");	
	newPur->output();
	
    PurchaseCollection pc(1);

    CreditPurchase* pur1 = new CreditPurchase("Gold", 999.0, 1, 12, "Alfa");
    CreditPurchase* pur2 = new CreditPurchase("Apple", 9.0, 2, 1, "Belarus");
    CreditPurchase pur3("Silver", 99.0, 3, 3, "Belagro");
    Purchase* pur4 = new Purchase("Milk", 1.33, 2);
    Purchase* pur5 = new Purchase("Cola", 2.33, 2);
    Purchase pur6("Bread", 1.00, 2);

    pc += pur1;
    pc += pur2;
    pc += pur3;
    pc += pur4;
    pc += pur5;
    pc += pur6;

    pc.output();

    pc.sort();

    cout << "\nAfter sort:\n";
    pc.output();

    pc.saveToFile("Collection.txt");

    PurchaseCollection pc2(1);
    pc2.loadFromFile("Collection.txt");
    cout << "\nLoaded collection:\n";
    pc2.output();
    
    PurchaseCollection pc3 = pc2;
    pc3.output();

    return 0;
}