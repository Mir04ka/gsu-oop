#include "CreditPurchase.h"

CreditPurchase::CreditPurchase() : Purchase() {
    monthCount = 0;
    bank = "";
}

CreditPurchase::CreditPurchase(string productName, float price, int quantity, int monthCount, string bank) : Purchase(productName, price, quantity) {
    this->monthCount = monthCount;
    this->bank = bank;
}

CreditPurchase::~CreditPurchase() {
    cout << "\nCreditPurchase destructor!";
}

int CreditPurchase::getMonthCount() {
    return monthCount;
}

string CreditPurchase::getBank() {
    return bank;
}

void CreditPurchase::setMonthCount(int monthCount) {
    if (monthCount <= 0) {
        cout << "\nMonth count must be positive!\n";
        return;
    }
    this->monthCount = monthCount;
}

void CreditPurchase::setBank(string bank) {
    this->bank = bank;
}

void CreditPurchase::output() {
    Purchase::output();
    cout << "Month count: " << monthCount << "\nBank: " << bank << "\n";
}

void CreditPurchase::input() {
    Purchase::input();

    int input_month;
    cout << "\nMonth count: ";
    cin >> input_month;
    setMonthCount(input_month);

    string input_bank;
    cout << "\nBank: ";
    cin >> input_bank;
    setBank(input_bank);
}

void CreditPurchase::saveToFile(FILE *file) {
    fprintf(file, "%s %f %d %d %s\n", getProductName().c_str(), getPrice(), getQuantity(), monthCount, bank.c_str());
}

void CreditPurchase::loadFromFile(FILE *file) {
    char nameBuffer[100];
    float p;
    int q;
    int m;
    char bankBuffer[100];

    if (fscanf(file, "%99s %f %d %d %99s", nameBuffer, &p, &q, &m, bankBuffer) == 5) {
        setProductName(nameBuffer);
        setPrice(p);
        setQuantity(q);
        setMonthCount(m);
        setBank(bankBuffer);
        return;
    }

    cout << "\nFailed to load from file\n";
}

string CreditPurchase::getKey() {
    return "B" + bank;
}

string CreditPurchase::getType() {
    return "CreditPurchase";
}
