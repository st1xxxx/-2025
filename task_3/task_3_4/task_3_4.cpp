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
    cout << "Задача: 4" << endl;
    cout << endl;
}


template<typename T>
void printVector(const vector<T>& vec) {
    cout << "My vector has " << vec.size() << " of these elements:" << endl;
    for (size_t i = 0; i < vec.size(); i++) {
        cout << "[" << i << "] -> " << vec[i] << endl;
    }
}


template<typename T>
vector<T> operator+(const vector<T>& vec1, const vector<T>& vec2) {
    vector<T> result = vec1;
    result.insert(result.end(), vec2.begin(), vec2.end());
    return result;
}

int main() {
    printStudentInfo();
    
    vector<int> vec1 = {1, 2, 3};
    vector<int> vec2 = {4, 5, 6};
    
    cout << "Первый вектор:" << endl;
    printVector(vec1);
    
    cout << "\nВторой вектор:" << endl;
    printVector(vec2);
    
    vector<int> result = vec1 + vec2;
    
    cout << "\nРезультат объединения (vec1 + vec2):" << endl;
    printVector(result);
    
    // Демонстрация с string
    vector<string> strVec1 = {"Hello", "World"};
    vector<string> strVec2 = {"from", "C++"};
    
    cout << "\nОбъединение строковых векторов:" << endl;
    vector<string> strResult = strVec1 + strVec2;
    printVector(strResult);
    
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    
    return 0;

}
