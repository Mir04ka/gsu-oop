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
    cout << *this;
}

void CreditPurchase::input() {
    cout << "\nEnter CreditPurchase:\n";
    cin >> *this;
}

void CreditPurchase::saveToFile(ostream& os) {
    Purchase::saveToFile(os);
    os << monthCount << " " << bank << " ";
}

void CreditPurchase::loadFromFile(istream& is) {
    Purchase::loadFromFile(is);

    int m;
    string b;

    if (is >> m >> b) {
        setMonthCount(m);
        setBank(b);
    }
    else {
        throw "Failed to load from file";
    }
}

string CreditPurchase::getKey() {
    return "B" + bank;
}

string CreditPurchase::getType() const {
    return "CreditPurchase";
}

CreditPurchase* CreditPurchase::clone() const {
    return new CreditPurchase(*this);
}

ostream& operator<< (ostream& os, const CreditPurchase& p) {
    operator<<(os, (const Purchase&)p);
    os << "Month count: " << p.monthCount << "\nBank: " << p.bank << "\n";
    return os;
}

istream& operator>> (istream& is, CreditPurchase& p) {
    operator>>(is, (Purchase&)p);

    int input_month;
    is >> input_month;
    p.setMonthCount(input_month);

    string input_bank;
    is >> input_bank;
    p.setBank(input_bank);

    return is;
}