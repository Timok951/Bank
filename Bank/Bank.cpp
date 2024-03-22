#include <iostream>
#include <Windows.h>
#pragma execution_character_set("utf-8")
using namespace std;

class BankAccount {

private:int accountNumber;
private:double balance;
private:double interestRate;

friend bool transfer(BankAccount& from, BankAccount& to, double sum);

public:BankAccount(int accountNumber, double balance, double interestRate) {
        this->accountNumber = accountNumber;
        this->balance = balance;
        this->interestRate = interestRate;

    }
    
    void deposit() {
        int add;
        cout << "Input sum";
        cin >> add;
        if (add > 0) {
            this->balance = this->balance + add;
        }
        else
        {
            cout << "error";
        }
    }

    void withdraw() {
        double withdraw;
        cout << "введите сумму";
        cin >> withdraw;
        if (this->balance >= withdraw) {

            this->balance = this->balance - withdraw;
        }

        else {
            cout << "ошибка";
        }
    }


    void getbalance() {
        cout << this->balance;

    }

    void setInterestRate() {
        this->interestRate = this->balance * this->interestRate / 100;
        cout << this->interestRate;
    }

    void GetaccountNumber() {
        cout << this->accountNumber;
    }

};

bool transfer(BankAccount& from,BankAccount& to, double sum) {
    if (from.balance >= sum) {
        to.balance += sum;
        from.balance -= sum;
        return true;
    }
    else {
        cout << "ошибка";
        return false;
    }
}

int main()
{
    SetConsoleCP(65001); // устанавливаем кодировку входящего потока данных на UTF-8
    SetConsoleOutputCP(65001); // устанавливаем кодировку исходящего потока данных на UTF-8

        cout << "Введите номер первого аккаунта ";
        int a;
        cin >> a;
        cout << "Введите баланс аккаунта ";
        double b;
        cin >> b;
        cout << "Введите процентную ставку ";
        int c;
        cin >> c;
        BankAccount account1 = BankAccount(a, b, c);
        cout << "Введите номер второго аккаунта ";

        cin >> a;
        cout << "Введите баланс второго аккаунта ";

        cin >> b;
        cout << "Введите процентную ставку второго аккаунта ";
        cin >> c;
        BankAccount account2 = BankAccount(a, b, c);
        
        cout << "0-выход, 1-баланс аккаунтов, 2-пересчитать процентную ставку, 3-получить номера аккаунтов, 4-перевести с 1-о на 2-й аккаунт сумму, 5-добавить сумму на первый аккаунт ";
        int input;
        cin >> input;
        while(input !=0 ) {
            if (input == 0) {
                break;
            }
            else if (input == 1)
            {
                account1.getbalance();
                cout <<"\n";
                account2.getbalance();
                cin >> input;

                
            }

            else if (input == 2)
            {
                account1.setInterestRate();
                cout << "\n";

                account2.setInterestRate();
                cout << "\n";

                cin >> input;

            }


            else if (input == 3)
            {
                account1.GetaccountNumber();
                cout << "\n";
                account2.GetaccountNumber();
                cout << "\n";
                cin >> input;

            }

            else if (input == 4)
            {   
                cout << "введите сумму ";
                cin >> input;
                transfer(account1, account2, input);
                cin >> input;

            }

            else if (input == 5) {
                account1.withdraw();
                cin >> input;

            }
        }



    }



