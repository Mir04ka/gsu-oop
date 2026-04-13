// Ларичев, вариант 30, работа 7
// Классы: покупка в магазине <- покупка в рассрочку
// Исключения

#include <iostream>

#include "Exception.h"
#include "Purchase.h"
#include "PurchaseCollection.h"

int	main() {
	freopen("logs.txt", "w", stderr);


	Purchase* pur;

	try {
		pur = new Purchase("Cola", 2.33, 2);
	}
	catch (const Exception& e) {
		cerr << e.getMessage() << endl;
		return 1;
	}

	while (true) {
		try {
			pur->input();
			break;
		}
		catch (const Exception& e) {
			cerr << e.getMessage() << endl;
			cout << e.getMessage() << endl;
		}
	}

	try {
		pur->setPrice(-1);
	}
	catch (const Exception& e) {
		cerr << e.getMessage() << endl;
		cout << e.getMessage() << endl;
	}
	pur->output();

	PurchaseCollection pc(0);
	pc.add(pur);

	try {
		pc.saveToFile("Collection.txt");
	}
	catch (const string& e) {
		cerr << e << endl;
		cout << e << endl;
	}

	PurchaseCollection pc2(0);

	try {
		pc2.loadFromFile("Collection.txt");
	}
	catch (const string& e) {
		cerr << e << endl;
		cout << e << endl;
	}

	pc2.output();

    return 0;
}
