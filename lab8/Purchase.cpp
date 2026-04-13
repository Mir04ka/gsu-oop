#include "Purchase.h"

#include "Exception.h"

Purchase::Purchase() {
    productName = "";
    price = 0;
    quantity = 0;
}

Purchase::Purchase(string productName, float price, int quantity) {
    this->productName = productName;
    this->quantity = quantity;

    if (price < 0) {
        throw Exception("Purchase constructor got price: " + to_string(price));
    }

    this->price = price;
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
        throw Exception("Purchase::setPrice(): got price: " + to_string(price));
    }

    this->price = price;
}

void Purchase::setQuantity(int quantity) {
    if (quantity < 0) {
        cout << "\nQuantity must be positive or zero!\n";
        return;
    }

    this->quantity = quantity;
}

void Purchase::output() {
    cout << "\nProduct name: " << productName << "\nPrice: " << price << "\nQuantity: " << quantity << "\n";
}

void Purchase::input() {
    string input_name;
    cout << "\nProduct name: ";
    cin >> input_name;
    setProductName(input_name);

    float input_price;
    cout << "\nPrice: ";
    cin >> input_price;

    if (input_price < 0) {
        throw Exception("Purchase::input(): got price: " + to_string(input_price));
    }

    setPrice(input_price);

    int input_quantity;
    cout << "\nQuantity: ";
    cin >> input_quantity;
    setQuantity(input_quantity);
}

void Purchase::saveToFile(FILE* file) {
    fprintf(file, "%s\n%s %f %d ", getType().c_str(), productName.c_str(), price, quantity);
}

void Purchase::loadFromFile(FILE* file) {
    char buffer[100];
    float p;
    int q;

    if (fscanf(file, "%99s %f %d ", buffer, &p, &q) == 3) {
        setProductName(buffer);
        setPrice(p);
        setQuantity(q);
        return;
    }

    cout << "\nFailed to load from file\n";
}

string Purchase::getKey() {
    return "A" + productName;
}

string Purchase::getType() {
    return "Purchase";
}

Purchase* Purchase::clone() const {
    return new Purchase(*this);
}
