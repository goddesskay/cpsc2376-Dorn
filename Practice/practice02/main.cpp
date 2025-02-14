#include <iostream>
#include <fstream>

void showMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Check Balance\n";
    std::cout << "2. Deposit Money\n";
    std::cout << "3. Withdraw Money\n";
    std::cout << "4. Exit\n";
}

double readBalance() {
    std::ifstream inf("account_balance.txt");

    if (!inf.is_open())
    {
        std::cout << "Initiliazing account with $100.00.. " << std::endl;

        std::ofstream outf("account_balance.txt");
        outf << "100.00";
        outf.close();

        return 100;

    }

    double balance;
    inf >> balance;
    inf.close();

    return balance;

}

double depositMoney(double& balance) {
    double deposit;
    std::cout << "How much money would you like to deposit? " << std::endl;
    std::cin >> deposit;

    if (deposit <= 0)
    {
        std::cout << "Error: Deposit must be positive" << std::endl;
    }

    balance += deposit;
    std::cout << "Money Deposited! Account balance is now: " << balance << std::endl;

    std::ofstream outf("account_balance.txt");
    if (outf.is_open())
    {
        outf << balance;
        outf.close();
    }
    else {
        std::cerr << "Error: Could not update account balance." << std::endl;
    }

    return deposit;

}

double withdrawMoney(double& balance) {
    double withdraw;
    std::cout << "How much money would you like to withdraw? " << std::endl;
    std::cin >> withdraw;

    if (withdraw <= 0)
    {
        std::cout << "Error: Deposit must be positive" << std::endl;
        return 0.0;
    }

    if (withdraw > balance) {
        std::cout << "Insufficient funds. Your balance is: " << balance << std::endl;
        return 0.0;
    }

    balance -= withdraw;
    std::cout << "Money Withdrawn! Account balance is now: " << balance << std::endl;

    std::ofstream outf("account_balance.txt");
    if (outf.is_open())
    {
        outf << balance;
        outf.close();
    }
    else {
        std::cerr << "Error: Could not update account balance." << std::endl;
    }



    return withdraw;
}





int main() {

    double balance = readBalance();

    std::cout << "Welcome to Bank of Dragoon" << std::endl;
    std::cout << " What would you like to do with your account today? " << std::endl;


    int choice;

    do {
        showMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {

        case 1:
            std::cout << "Your current balance is: " << balance << std::endl;
            break;
        case 2:
            depositMoney(balance);
            break;
        case 3:
            withdrawMoney(balance);
            break;
        case 4:
            std::cout << "Bye-Bye!" << std::endl;
            break;
        }
    } while (choice != 4);
    return 0;
}
