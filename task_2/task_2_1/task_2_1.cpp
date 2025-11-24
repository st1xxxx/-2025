#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <windows.h>

using namespace std;

void printStudentInfo() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "Студент: Скворцов Серафим Денисович" << endl;
    cout << "Группа: M10-137БВ-25" << endl;
    cout << "Задача: 1" << endl;
    cout << endl;
}

int main() {
    printStudentInfo();
    srand(time(nullptr));
    
    map<string, vector<int>> students;
    int studentCount = 3; 
    int gradesCount = 5;
    
    cout << "Введите фамилии " << studentCount << " студентов:" << endl;
    
    for (int i = 0; i < studentCount; i++) {
        string surname;
        cout << "Студент " << (i + 1) << ": ";
        cin >> surname;
        
        vector<int> grades;
        for (int j = 0; j < gradesCount; j++) {
            grades.push_back(rand() % 4 + 2); 
        }
        
        students[surname] = grades;
    }
    
    cout << "\nСписок группы и успеваемость:" << endl;
    cout << "=============================" << endl;
    
    for (const auto& student : students) {
        cout << student.first << ": ";
        for (int grade : student.second) {
            cout << grade << " ";
        }
        cout << endl;
    }
    
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    
    return 0;
}
