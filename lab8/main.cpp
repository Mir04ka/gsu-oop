// Ларичев, вариант 30, работа 7
// Классы: покупка в магазине <- покупка в рассрочку
// Виртуальные методы

#include <iostream>

#include "CreditPurchase.h"
#include "Exception.h"
#include "Purchase.h"
#include "PurchaseCollection.h"

int main() {
	Purchase* pur = new Purchase("Cola", 2.33, 2);

	try {
		pur->setPrice(-1);
	}
	catch (const Exception& e) {
		cout << e.getMessage();
	}


    return 0;
}