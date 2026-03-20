// Ларичев, вариант 30, работа 5
// Классы: покупка в магазине <- покупка в рассрочку
// Коллекция базового класса

#include "Purchase.h"
#include "PurchaseCollection.h"

int main() {
    PurchaseCollection pc(1);

    Purchase* pur1 = new Purchase("First", 1.33, 2);
    Purchase* pur2 = new Purchase("Second", 1.33, 2);
    Purchase* pur3 = new Purchase("3rd", 1.33, 2);
    Purchase* pur4 = new Purchase("Fourth", 1.33, 2);

    pc.add(pur1);
    pc.add(pur2);
    pc.add(pur3);
    pc.add(pur4);
    cout << "Collection size: " << pc.getSize() << "\n";
    pc.print();

    pc.remove(3);
    cout << "\nRemoved last:\n";
    pc.print();

    pc.swap(0, 1);
    cout << "\nAfter swap:\n";
    pc.print();

    pc.sort();
    cout << "\nSorted collection:\n";
    for (int i = 0; i < pc.getSize(); i++) {
        cout << pc.get(i)->getProductName() << "\n";
    }

    return 0;
}