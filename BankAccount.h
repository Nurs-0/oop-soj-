#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount {
private:
    std::string ownerName;
    std::string accountNumber;
    double balance;

    double* transactionHistory;
    int transactionCount;

public:
    BankAccount();
    BankAccount(const std::string& ownerName, const std::string& accountNumber,
                double balance, const double* history, int transactionCount);
    BankAccount(const BankAccount& other);
    ~BankAccount();

    std::string getOwnerName() const;
    std::string getAccountNumber() const;
    double getBalance() const;
    int getTransactionCount() const;
    double getTransactionAt(int index) const;
    void printTransactionHistory() const;

    void setOwnerName(const std::string& newOwnerName);
    void setAccountNumber(const std::string& newAccountNumber);
    void setBalance(double newBalance);
    void setTransactionAt(int index, double value);
    void setTransactionHistory(const double* history, int count);

    BankAccount& operator=(const BankAccount& other);
    bool operator==(const BankAccount& other) const;

    void printInfo() const;
};

#endif
