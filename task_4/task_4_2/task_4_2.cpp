#include <iostream>
#include <string>
#include <limits>
#include <windows.h>

using namespace std;

void printStudentInfo() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "Student: Skvortsov Serafim Denisovich" << endl;
    cout << "Group: M10-137BV-25" << endl;
    cout << "Task: 2" << endl;
    cout << endl;
}

struct BankAccount {
    string accountNumber;
    string owner;
    double balance;
    
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Внесено: $" << amount << endl;
            cout << "Новый баланс: $" << balance << endl;
        } else {
            cout << "Неверная сумма пополнения!" << endl;
        }
    }
    
    void withdraw(double amount) {
        if (amount > 0) {
            if (balance >= amount) {
                balance -= amount;
                cout << "Снято: $" << amount << endl;
                cout << "Новый баланс: $" << balance << endl;
            } else {
                cout << "Недостаточно средств! Текущий баланс: $" << balance << endl;
            }
        } else {
            cout << "Неверная сумма снятия!" << endl;
        }
    }
    
    void printSummary() const {
        cout << "Информация о счёте:" << endl;
        cout << "  Номер счёта: " << accountNumber << endl;
        cout << "  Владелец: " << owner << endl;
        cout << "  Баланс: $" << balance << endl;
    }
};

int main() {
    printStudentInfo();
    
    
    BankAccount account = {"ACC-123456", "Иван Петров", 1000.0};
    
    cout << "Начальное состояние счёта:" << endl;
    account.printSummary();
    cout << endl;
    
    
    cout << "Пополнение на $500..." << endl;
    account.deposit(500.0);
    cout << endl;
    
    
    cout << "Снятие $300..." << endl;
    account.withdraw(300.0);
    cout << endl;
    
    
    cout << "Попытка снять $2000..." << endl;
    account.withdraw(2000.0);
    cout << endl;
    
    
    cout << "Итоговое состояние счёта:" << endl;
    account.printSummary();
    
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    
    return 0;
}
