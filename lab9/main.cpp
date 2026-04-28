// Ларичев, вариант 30, работа 9
// Классы: покупка в магазине <- покупка в рассрочку
// Потоки

#include <iostream>
#include <iomanip>

#include "CreditPurchase.h"
#include "Exception.h"
#include "Purchase.h"
#include "PurchaseCollection.h"

int	main() {
	PurchaseCollection c(1);
	Purchase p("Bread", 1.23, 2);
	CreditPurchase cp("Milk", 0.99, 1, 2, "Alfa");

	c.add(p.clone());
	c.add(cp.clone());

	cout << "Enter Purchase:\n";
	cin >> p;

	cout << "Enter CreditPurchase:\n";
	cin >> cp;

	cout << p << "\n" << cp << endl;

	c.saveToFile("Collection.txt");

	PurchaseCollection coll2(1);
	coll2.loadFromFile("Collection.txt");
	coll2.output();

	return 0;
}