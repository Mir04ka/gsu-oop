// Ларичев, вариант 30, работа 6
// Классы: покупка в магазине <- покупка в рассрочку
// Переопределить операторы

#include "Purchase.h"
#include "PurchaseCollection.h"

int main() {
    PurchaseCollection pc(1);

    Purchase* pur1 = new Purchase("Milk", 1.33, 2);
    Purchase* pur2 = new Purchase("Cola", 2.33, 2);
    Purchase pur3("Meat", 11.50, 2);
    Purchase pur4("Bread", 1.00, 2);

    pc += pur1;
    pc += pur2;
    pc += pur3;
    pc += pur4;

    pc.print();

    cout << "\n3 element:";
    pc[2]->output();
    cout << "\nMilk purhase:";
    pc["Milk"]->output();

    pc -= 0;
    cout << "\nRemoved first element:\n";
    pc.print();

    pc -= "Bread";
    cout << "\nRemoved bread element:\n";
    pc.print();

    return 0;
}