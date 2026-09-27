#include <iostream>
#include "BankAccount.h"

int main() {
    double history1[] = {1000, -200, 500};
    BankAccount acc1("Ермахамбет Нұрасыл", "KZ001122", 1300.0, history1, 3);

    std::cout << "=== acc1 ===" << std::endl;
    acc1.printInfo();
    acc1.printTransactionHistory();

    BankAccount acc2 = acc1;
    acc2.setTransactionAt(0, 9999);
    acc2.setOwnerName("Ермахамбет Нұрасыл (көшірме)");

    std::cout << "\n=== acc2 ===" << std::endl;
    acc2.printInfo();
    acc2.printTransactionHistory();

    std::cout << "\n=== acc1 (deep copy тексеру) ===" << std::endl;
    acc1.printTransactionHistory();

    double history3[] = {2000, 1500};
    BankAccount acc3("Сейітқали Дана", "KZ003344", 3500.0, history3, 2);
    BankAccount acc4;
    acc4 = acc3;

    std::cout << "\n=== acc4 ===" << std::endl;
    acc4.printInfo();
    acc4.printTransactionHistory();

    BankAccount acc5("Басқа Адам", "KZ003344", 100.0, nullptr, 0);
    std::cout << "\n=== Теңдік тексеру ===" << std::endl;
    std::cout << "acc3 == acc5 : " << (acc3 == acc5 ? "true" : "false") << std::endl;
    std::cout << "acc1 == acc3 : " << (acc1 == acc3 ? "true" : "false") << std::endl;

    const BankAccount constAcc("Тестов Тест", "KZ009900", 500.0, history3, 2);
    std::cout << "\n=== Тұрақты объект ===" << std::endl;
    std::cout << constAcc.getOwnerName() << " " << constAcc.getBalance() << std::endl;

    return 0;
}
