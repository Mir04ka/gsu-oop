#ifndef GSU_OOP_PURCHASE_H
#define GSU_OOP_PURCHASE_H
#include <string>
#include <iostream>

using namespace std;

class Purchase {
private:
    string product_name;
    float price;
    int quantity;

public:
    string get_product_name();
    float get_price();
    int get_quantity();

    void set_product_name(string name);
    void set_price(float price);
    void set_quantity(int quantity);

    void print();
    void input();
};

#endif //GSU_OOP_PURCHASE_H