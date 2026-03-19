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
    cout << "\n\nCreditPurchase destructor!\n";
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
    cout << "\nMonth count: " << monthCount << "\nBank: " << bank;
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