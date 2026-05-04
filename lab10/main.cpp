// Ларичев, вариант 30, работа 9
// Классы: покупка в магазине <- покупка в рассрочку
// Потоки

#include <iostream>

#include "CreditPurchase.h"
#include "Exception.h"
#include "Purchase.h"
#include "PurchaseCollection.h"

int	main() {
	PurchaseCollection<Purchase> c;
	Purchase p1("Bread", 1.23, 2);
	Purchase p2("Butter", 2.50, 1);
	CreditPurchase cp1("Cheese", 3.75, 1, 3, "VTB");
	CreditPurchase cp2("Milk", 0.99, 1, 2, "Alfa");

	c += p1;
	c.add(p2.clone());
	c += cp1.clone();
	c += cp2;

	cout << "\nAfter adding:\n";
	c.output();

	cout << "\nIndex:\n";
	c[0]->output();
	c.get(1)->output();

	cout << "\nName:\n";
	Purchase* found = c["Milk"];
	if (found) found->output();

	cout << "\nSort:\n";
	c.sort();
	c.output();

	c -= 1;
	cout << "\nRemove by index:\n";
	c.output();

	c -= "Bread";
	cout << "\nRemove by name:\n";
	c.output();

	c.saveToFile("Collection.txt");
	PurchaseCollection<Purchase> c2;
	c2.loadFromFile<CreditPurchase>("Collection.txt");
	cout << "\nLoaded:\n";
	c2.output();

	PurchaseCollection<Purchase> c3 = c2;

	cout << "\nCopied:\n";
	c3.output();

	cout << "\n\nCredit purchase\n\n";
	PurchaseCollection<CreditPurchase> cc;

	cc += cp1;
	cc.add(cp2.clone());

	cout << "\nAfter adding:\n";
	cc.output();

	cout << "\nIndex:\n";
	cc[0]->output();
	cc.get(1)->output();

	cout << "\nName:\n";
	CreditPurchase* foundCP = cc["Milk"];
	if (foundCP) foundCP->output();

	cout << "\nSort:\n";
	cc.sort();
	cc.output();

	cc -= 1;
	cout << "\nRemove by index:\n";
	cc.output();

	cc -= "Milk";
	cout << "\nRemove by name:\n";
	cc.output();

	cc.saveToFile("CollectionCP.txt");
	PurchaseCollection<CreditPurchase> cc2;
	cc2.loadFromFile<CreditPurchase>("CollectionCP.txt");
	cout << "\nLoaded:\n";
	cc2.output();

	PurchaseCollection<CreditPurchase> cc3 = cc2;

	cout << "\nCopied:\n";
	c3.output();

	return 0;
}