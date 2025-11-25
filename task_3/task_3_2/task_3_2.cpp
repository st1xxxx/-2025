#include <iostream>
#include <fstream>
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




int main() {
    printStudentInfo();
    
    ifstream file("books.txt");
    
    if (!file.is_open()) {
        cout << "Ошибка: файл 'books.txt' не найден!" << endl;
        cout << "Сначала выполните задание 1 для создания файла." << endl;
    } else {
        cout << "Содержимое файла 'books.txt':" << endl;
        cout << "=============================" << endl;
        
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        
        file.close();
    }
    
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    
    return 0;
}
