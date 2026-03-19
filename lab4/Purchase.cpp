#include "Purchase.h"

Purchase::Purchase() {
    productName = "";
    price = 0;
    quantity = 0;
}

Purchase::Purchase(string productName, float price, int quantity) {
    this->productName = productName;
    this->price = price;
    this->quantity = quantity;
}

Purchase::Purchase(const Purchase& pur) {
    *this = pur;
}

Purchase::Purchase(string productName) : Purchase() {
    this->productName = productName;
}

Purchase::~Purchase() {
    cout << "\n\nPurchase destructor!\n";
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
        cout << "\nPrice must be positive or zero!\n";
        return;
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

void Purchase::print() {
    cout << "\nProduct name: " << productName << "\nPrice: " << price << "\nQuantity: " << quantity;
}

void Purchase::input() {
    string input_name;
    cout << "\nProduct name: ";
    cin >> input_name;
    setProductName(input_name);

    float input_price;
    cout << "\nPrice: ";
    cin >> input_price;
    setPrice(input_price);

    int input_quantity;
    cout << "\nQuantity: ";
    cin >> input_quantity;
    setQuantity(input_quantity);
}