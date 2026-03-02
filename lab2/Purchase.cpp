#include "Purchase.h"

string Purchase::get_product_name() {
    return product_name;
}

float Purchase::get_price() {
    return price;
}
int Purchase::get_quantity() {
    return quantity;
}

void Purchase::set_product_name(string name) {
    if (name == "") {
        cout << "\nName must be not empty!\n";
        return;
    }

    product_name = name;
}

void Purchase::set_price(float price) {
    if (price <= 0) {
        cout << "\nPrice must be greater than zero!\n";
        return;
    }

    this->price = price;
}

void Purchase::set_quantity(int quantity) {
    if (quantity <= 0) {
        cout << "\nQuantity must be greater than zero!\n";
        return;
    }

    this->quantity = quantity;
}

void Purchase::print() {
    cout << "\nPurchase:\nProduct name: " << product_name << "\nPrice: " << price << "\nQuantity: " << quantity;
}

void Purchase::input() {
    string input_name;
    cout << "\nProduct name: ";
    cin >> input_name;
    set_product_name(input_name);

    float input_price;
    cout << "\nPrice: ";
    cin >> input_price;
    set_price(input_price);

    int input_quantity;
    cout << "\nQuantity: ";
    cin >> input_quantity;
    set_quantity(input_quantity);
}