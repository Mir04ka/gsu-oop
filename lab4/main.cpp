// Ларичев, вариант 30, работа 4
// Класс для покупки в магазине
// Класс наследник: покупка в рассрочку

#include "Purchase.h"
#include "CreditPurchase.h"

int main() {
    CreditPurchase pur1;
    pur1.output();
    pur1.Purchase::input();
    pur1.Purchase::output();
    pur1.input();
    pur1.output();

    CreditPurchase pur2("Milk", 2.5, 2, 3, "AlfaBank");
    pur2.output();

    pur2.setProductName("Coke");
    pur2.setPrice(3.14);
    pur2.setQuantity(3);
    pur2.setMonthCount(12);
    pur2.setBank("BelarusBank");

    cout << "\n\nPurchase: \nName: " << pur2.getProductName() << "\nPrice: " << pur2.getPrice() << "\nQuantity: " << pur2.getQuantity() << " \nMonth count: " << pur2.getMonthCount() << "\nBank: " << pur2.getBank();


    CreditPurchase* dyn_pur1 = new CreditPurchase();
    dyn_pur1->output();
    dyn_pur1->Purchase::input();
    dyn_pur1->Purchase::output();
    dyn_pur1->input();
    dyn_pur1->output();

    CreditPurchase* dyn_pur2 = new CreditPurchase("Milk", 2.5, 2, 3, "AlfaBank");
    dyn_pur2->output();

    dyn_pur2->setProductName("Coke");
    dyn_pur2->setPrice(3.14);
    dyn_pur2->setQuantity(3);
    dyn_pur2->setMonthCount(12);
    dyn_pur2->setBank("BelarusBank");

    cout << "\n\nPurchase: \nName: " << dyn_pur2->getProductName() << "\nPrice: " << dyn_pur2->getPrice() << "\nQuantity: " << dyn_pur2->getQuantity() << " \nMonth count: " << dyn_pur2->getMonthCount() << "\nBank: " << dyn_pur2->getBank();

    delete dyn_pur1;
    delete dyn_pur2;

    return 0;
}