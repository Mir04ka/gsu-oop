// Ларичев, вариант 30, работа 2
// Разработать класс для покупки в магазине
#include "Purchase.h"

int main() {
    Purchase pur;

    pur.input();
    pur.print();

    pur.setProductName("Milk");

    pur.setPrice(2.3);

    pur.setQuantity(1);
    pur.print();

    cout << "\nDYNAMIC\n";

    Purchase* pur2 = new Purchase;

    pur2->input();
    pur2->print();

    pur2->setProductName("Coke");

    pur2->setPrice(3.3);

    pur2->setQuantity(2);
    pur2->print();

    delete pur2;
}