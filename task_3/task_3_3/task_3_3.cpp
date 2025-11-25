#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <windows.h>

using namespace std;

void printStudentInfo() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "Student: Skvortsov Serafim Denisovich" << endl;
    cout << "Group: M10-137BV-25" << endl;
    cout << "Task: 3" << endl;
    cout << endl;
}




int main() {
    printStudentInfo();
    srand(time(nullptr));
    
    
    ifstream inputFile("books.txt");
    if (!inputFile.is_open()) {
        cout << "Ошибка: файл 'books.txt' не найден!" << endl;
        cout << "Сначала выполните задание 1." << endl;
        cout << "\nНажмите Enter для выхода...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return 1;
    }
    
    vector<string> names;
    vector<string> authors;
    vector<string> years;
    
    string line;
    while (getline(inputFile, line)) {
        if (line.find("Name:") != string::npos) {
            names.push_back(line.substr(line.find("Name:") + 6));
        } else if (line.find("Author:") != string::npos) {
            authors.push_back(line.substr(line.find("Author:") + 8));
        } else if (line.find("Year:") != string::npos) {
            years.push_back(line.substr(line.find("Year:") + 6));
        }
    }
    inputFile.close();
    
    
    for (int i = names.size() - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(names[i], names[j]);
    }
    
    for (int i = authors.size() - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(authors[i], authors[j]);
    }
    
    for (int i = years.size() - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(years[i], years[j]);
    }
    
    
    ofstream outputFile("incorrect_books.txt");
    
    for (size_t i = 0; i < names.size(); i++) {
        outputFile << (i + 1) << ". Name:" << names[i] << endl;
        outputFile << "   Author:" << authors[i] << endl;
        outputFile << "   Year:" << years[i] << endl;
        outputFile << "   ----------" << endl;
    }
    
    outputFile.close();
    
    cout << "Файл 'incorrect_books.txt' успешно создан с перемешанными данными." << endl;
    
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    
    return 0;
}
