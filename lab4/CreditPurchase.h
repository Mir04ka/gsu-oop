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
    ~CreditPurchase();

    int getMonthCount();
    string getBank();

    void setMonthCount(int monthCount);
    void setBank(string bank);

    void output();
    void input();
};

#endif //GSU_OOP_CREDITPURCHASE_H