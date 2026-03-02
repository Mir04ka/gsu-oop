// Ларичев, вариант 30, работа 2
// Разработать класс для покупки в магазине
#include "Purchase.h"

int main() {
    Purchase pur;

    pur.input();
    pur.print();

    pur.set_product_name("");
    pur.set_product_name("Milk");

    pur.set_price(-2.3);
    pur.set_price(2.3);

    pur.set_quantity(-2);
    pur.set_quantity(1);
    pur.print();

    cout << "\nDYNAMIC\n";

    Purchase* pur2 = new Purchase;

    pur2->input();
    pur2->print();

    pur2->set_product_name("");
    pur2->set_product_name("Coke");

    pur2->set_price(0);
    pur2->set_price(3.3);

    pur2->set_quantity(-2);
    pur2->set_quantity(2);
    pur2->print();
}