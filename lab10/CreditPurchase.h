#ifndef GSU_OOP_CREDITPURCHASE_H
#define GSU_OOP_CREDITPURCHASE_H

#include "Purchase.h"

class CreditPurchase : public Purchase {
private:
    int monthCount;
    string bank;

public:
    CreditPurchase();
    CreditPurchase(string productName, float price, int quantity, int monthCount, string bank);
    ~CreditPurchase() override;

    int getMonthCount();
    string getBank();

    void setMonthCount(int monthCount);
    void setBank(string bank);

    void output() override;
    void input() override;
    void saveToFile(ostream& os) override;
    void loadFromFile(istream& is) override;

    string getKey() override;
    string getType() const override;
    CreditPurchase* clone() const override;

    friend ostream& operator<< (ostream& os, const CreditPurchase& p);
    friend istream& operator>> (istream& is, CreditPurchase& p);
};

#endif //GSU_OOP_CREDITPURCHASE_H