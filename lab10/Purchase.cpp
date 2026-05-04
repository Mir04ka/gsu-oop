#include "Purchase.h"

#include <iomanip>

#include "Exception.h"

Purchase::Purchase() {
    productName = "";
    price = 0;
    quantity = 0;
}

Purchase::Purchase(string productName, float price, int quantity) {
    this->productName = productName;
    this->quantity = quantity;
    
    try {
    	setPrice(price);
	}
	catch (const Exception& e) {
		this->price = 0;
	}
}

Purchase::Purchase(const Purchase& pur) {
    *this = pur;
}

Purchase::Purchase(string productName) : Purchase() {
    this->productName = productName;
}

Purchase::~Purchase() {
    cout << "\nPurchase destructor!";
}

string Purchase::getProductName() {
    return productName;
}

float Purchase::getPrice() {
    return price;
}
int Purchase::getQuantity() {
    return quantity;
}

void Purchase::setProductName(string name) {
    productName = name;
}

void Purchase::setPrice(float price) {
    if (price < 0) {
        throw Exception("Purchase: got wrong price.", price);
    }

    this->price = price;
}

void Purchase::setQuantity(int quantity) {
    if (quantity < 0) {
        cout << "Wrong quantity\n";
        return;
    }

    this->quantity = quantity;
}

void Purchase::output() {
	cout << *this;
}

void Purchase::input() {
	cout << "\nEnter Purchase:\n";
	cin >> *this;
}

void Purchase::saveToFile(ostream& os) {
    os << getType() << " " << productName << " " << price << " " << quantity << " ";
}

void Purchase::loadFromFile(istream& is) {
    string n;
    float p;
    int q;

    if (is >> n >> p >> q) {
        setProductName(n);
        setPrice(p);
        setQuantity(q);
    }
    else {
        throw "Failed to load from file";
    }
}

string Purchase::getKey() {
    return "A" + productName;
}

string Purchase::getType() const {
    return "Purchase";
}

Purchase* Purchase::clone() const {
    return new Purchase(*this);
}

ostream& operator<< (ostream& os, const Purchase& p) {
    os << p.getType() << ":\nName: " << p.productName << "\nPrice: " << fixed << setprecision(2) << p.price << "$\nQuantity: " << p.quantity << "\n";
    return os;
}

istream& operator>> (istream& is, Purchase& p) {
    string input_name;
    is >> input_name;
    p.setProductName(input_name);

    float input_price;
    is >> input_price;
    try {
        p.setPrice(input_price);
    }
    catch (const Exception& e) {
        throw;
    }

    int input_quantity;
    is >> input_quantity;
    p.setQuantity(input_quantity);

    return is;
}
