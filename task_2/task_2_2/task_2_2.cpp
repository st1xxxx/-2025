#include <iostream>
#include <map>
#include <string>
#include <limits>
#include <windows.h>

using namespace std;

void printStudentInfo() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "Студент: Скворцов Серафим Денисович" << endl;
    cout << "Группа: M10-137БВ-25" << endl;
    cout << "Задача: 2" << endl;
    cout << endl;
}


void addStudent(map<string, bool>& drivers, const string& surname, bool hasLicense) {
    drivers[surname] = hasLicense;
    cout << "Студент " << surname << " добавлен. Права: " << (hasLicense ? "есть" : "нет") << endl;
}


void removeStudent(map<string, bool>& drivers, const string& surname) {
    auto it = drivers.find(surname);
    if (it != drivers.end()) {
        drivers.erase(it);
        cout << "Студент " << surname << " удален." << endl;
    } else {
        cout << "Студент " << surname << " не найден." << endl;
    }
}


void printDrivers(const map<string, bool>& drivers) {
    cout << "\nТекущий список:" << endl;
    for (const auto& student : drivers) {
        cout << student.first << " -> " << (student.second ? "есть права" : "нет прав") << endl;
    }
}

int main() {
    printStudentInfo();
    
    map<string, bool> drivers;
    
    
    cout << "Добавление студентов:" << endl;
    addStudent(drivers, "Иванов", true);
    addStudent(drivers, "Петров", false);
    addStudent(drivers, "Сидоров", true);
    addStudent(drivers, "Кузнецов", false);
    
    printDrivers(drivers);
    
    
    cout << "\nУдаление студентов:" << endl;
    removeStudent(drivers, "Петров");
    removeStudent(drivers, "Смирнов"); 
    
    printDrivers(drivers);
    
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    
    return 0;
}
