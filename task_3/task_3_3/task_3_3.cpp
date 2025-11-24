#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <windows.h>

using namespace std;

void printStudentInfo() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "Студент: Скворцов Серафим Денисович" << endl;
    cout << "Группа: M10-137БВ-25" << endl;
    cout << "Задача: 3" << endl;
    cout << endl;
}


template<typename T>
void printVector(const vector<T>& vec) {
    cout << "My vector has " << vec.size() << " of these elements:" << endl;
    for (size_t i = 0; i < vec.size(); i++) {
        cout << "[" << i << "] -> " << vec[i] << endl;
    }
}

int main() {
    printStudentInfo();
    
    
    vector<int> intVec = {1, 2, 3, 4, 5};
    vector<string> strVec = {"apple", "banana", "cherry"};
    vector<double> doubleVec = {1.1, 2.2, 3.3, 4.4};
    
    cout << "Вектор int:" << endl;
    printVector(intVec);
    
    cout << "\nВектор string:" << endl;
    printVector(strVec);
    
    cout << "\nВектор double:" << endl;
    printVector(doubleVec);
    
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    
    return 0;
}
