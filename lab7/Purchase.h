#ifndef GSU_OOP_PURCHASE_H
#define GSU_OOP_PURCHASE_H
#include <string>
#include <iostream>

using namespace std;

class Purchase {
private:
    string productName;
    float price;
    int quantity;

public:
    Purchase();
    Purchase(string productName, float price, int quantity);
    Purchase(const Purchase& pur);
    Purchase(string productName);
    virtual ~Purchase();

    string getProductName();
    float getPrice();
    int getQuantity();

    void setProductName(string name);
    void setPrice(float price);
    void setQuantity(int quantity);

    virtual void output();
    virtual void input();
    virtual void saveToFile(FILE* file);
    virtual void loadFromFile(FILE* file);

    virtual string getKey();
    virtual string getType();
};

#endif //GSU_OOP_PURCHASE_H