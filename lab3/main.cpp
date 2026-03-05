// Ларичев, вариант 30, работа 3
// Класс для покупки в магазине
// Написать 4 вида конструкторов и деструктор

#include "Purchase.h"

int main() {
    Purchase pur1;
    pur1.print();

    Purchase pur2("Milk", 2.5, 2);
    pur2.print();

    Purchase pur3 = pur2;
    pur3.print();

    Purchase pur4("Coke");
    pur4.print();

    Purchase* dyn_pur1 = new Purchase;
    dyn_pur1->print();

    Purchase* dyn_pur2 = new Purchase("Meat", 10, 1);
    dyn_pur2->print();

    Purchase* dyn_pur3 = new Purchase(*dyn_pur2);
    dyn_pur3->print();

    Purchase* dyn_pur4 = new Purchase("Tomato");
    dyn_pur4->print();

    delete dyn_pur1;
    delete dyn_pur2;
    delete dyn_pur3;
    delete dyn_pur4;

    return 0;
}