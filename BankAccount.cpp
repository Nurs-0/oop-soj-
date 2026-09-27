#include "BankAccount.h"
#include <iostream>
#include <stdexcept>

BankAccount::BankAccount()
    : ownerName(""), accountNumber(""), balance(0.0),
      transactionHistory(nullptr), transactionCount(0) {
}

BankAccount::BankAccount(const std::string& ownerName, const std::string& accountNumber,
                          double balance, const double* history, int transactionCount)
    : ownerName(ownerName), accountNumber(accountNumber), balance(balance),
      transactionHistory(nullptr), transactionCount(transactionCount) {
    if (transactionCount > 0 && history != nullptr) {
        transactionHistory = new double[transactionCount];
        for (int i = 0; i < transactionCount; ++i) {
            transactionHistory[i] = history[i];
        }
    }
}

BankAccount::BankAccount(const BankAccount& other)
    : ownerName(other.ownerName), accountNumber(other.accountNumber),
      balance(other.balance), transactionHistory(nullptr),
      transactionCount(other.transactionCount) {
    if (transactionCount > 0 && other.transactionHistory != nullptr) {
        transactionHistory = new double[transactionCount];
        for (int i = 0; i < transactionCount; ++i) {
            transactionHistory[i] = other.transactionHistory[i];
        }
    }
}

BankAccount::~BankAccount() {
    delete[] transactionHistory;
    transactionHistory = nullptr;
}

std::string BankAccount::getOwnerName() const {
    return this->ownerName;
}

std::string BankAccount::getAccountNumber() const {
    return this->accountNumber;
}

double BankAccount::getBalance() const {
    return this->balance;
}

int BankAccount::getTransactionCount() const {
    return this->transactionCount;
}

double BankAccount::getTransactionAt(int index) const {
    if (index < 0 || index >= transactionCount) {
        throw std::out_of_range("Index out of range");
    }
    return transactionHistory[index];
}

void BankAccount::printTransactionHistory() const {
    std::cout << this->accountNumber << ": ";
    if (transactionCount == 0) {
        std::cout << "(бос)";
    }
    for (int i = 0; i < transactionCount; ++i) {
        std::cout << transactionHistory[i];
        if (i != transactionCount - 1) std::cout << ", ";
    }
    std::cout << std::endl;
}

void BankAccount::setOwnerName(const std::string& newOwnerName) {
    this->ownerName = newOwnerName;
}

void BankAccount::setAccountNumber(const std::string& newAccountNumber) {
    this->accountNumber = newAccountNumber;
}

void BankAccount::setBalance(double newBalance) {
    this->balance = newBalance;
}

void BankAccount::setTransactionAt(int index, double value) {
    if (index < 0 || index >= transactionCount) {
        throw std::out_of_range("Index out of range");
    }
    this->transactionHistory[index] = value;
}

void BankAccount::setTransactionHistory(const double* history, int count) {
    delete[] this->transactionHistory;
    this->transactionHistory = nullptr;
    this->transactionCount = count;
    if (count > 0 && history != nullptr) {
        this->transactionHistory = new double[count];
        for (int i = 0; i < count; ++i) {
            this->transactionHistory[i] = history[i];
        }
    }
}

BankAccount& BankAccount::operator=(const BankAccount& other) {
    if (this == &other) {
        return *this;
    }

    this->ownerName = other.ownerName;
    this->accountNumber = other.accountNumber;
    this->balance = other.balance;

    delete[] this->transactionHistory;
    this->transactionHistory = nullptr;
    this->transactionCount = other.transactionCount;

    if (transactionCount > 0 && other.transactionHistory != nullptr) {
        this->transactionHistory = new double[transactionCount];
        for (int i = 0; i < transactionCount; ++i) {
            this->transactionHistory[i] = other.transactionHistory[i];
        }
    }

    return *this;
}

bool BankAccount::operator==(const BankAccount& other) const {
    return this->accountNumber == other.accountNumber;
}

void BankAccount::printInfo() const {
    std::cout << "Иесі: " << ownerName
              << " | Шот нөмірі: " << accountNumber
              << " | Баланс: " << balance << std::endl;
}
