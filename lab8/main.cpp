// Ларичев, вариант 30, работа 7
// Классы: покупка в магазине <- покупка в рассрочку
// Исключения

#include <iostream>

#include "Exception.h"
#include "Purchase.h"
#include "PurchaseCollection.h"

int	main() {
	freopen("logs.txt", "w", stderr);
	
	Purchase* badPur = new Purchase("Cola", -3, 2);
	badPur->output();

	Purchase* pur = new Purchase("Cola", 2.33, 2);
	
	pur->input();

	try {
		pur->setPrice(-1);
	}
	catch (const Exception& e) {
		cerr << e.getMessage() << " Got: " << e.getBadArgument() << endl;
	}
	pur->output();

	PurchaseCollection pc(0);
	pc.add(pur);

	try {
		pc.saveToFile("C:\Collection.txt");
	}
	catch (const string& e) {
		cerr << e << endl;
	}

	PurchaseCollection pc2(0);

	try {
		pc2.loadFromFile("Collection.txt");
	}
	catch (const string& e) {
		cerr << e << endl;
	}

	pc2.output();
	
	delete badPur;

    return 0;
}
