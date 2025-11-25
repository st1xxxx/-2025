#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#include <windows.h>

using namespace std;

void printStudentInfo() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "Student: Skvortsov Serafim Denisovich" << endl;
    cout << "Group: M10-137BV-25" << endl;
    cout << "Task: 4" << endl;
    cout << endl;
}




int main() {
    printStudentInfo();
    
    string filename;
    cout << "Введите имя файла для анализа (например: input.txt): ";
    cin >> filename;
    
    ifstream file(filename);
    
    if (!file.is_open()) {
        cout << "Ошибка: файл '" << filename << "' не найден!" << endl;
        cout << "Убедитесь, что файл существует в текущей папке." << endl;
    } else {
        int lineCount = 0;
        int wordCount = 0;
        string line;
        
        while (getline(file, line)) {
            lineCount++;
            
            stringstream ss(line);
            string word;
            while (ss >> word) {
                wordCount++;
            }
        }
        
        file.close();
        
        
        cout << "\nСтатистика файла '" << filename << "':" << endl;
        cout << "Общее количество строк: " << lineCount << endl;
        cout << "Общее количество слов: " << wordCount << endl;
        
        
        ofstream report("report.txt");
        if (report.is_open()) {
            report << "Статистика файла: " << filename << endl;
            report << "Общее количество строк: " << lineCount << endl;
            report << "Общее количество слов: " << wordCount << endl;
            report.close();
            cout << "\nРезультаты сохранены в файл 'report.txt'" << endl;
        } else {
            cout << "\nОшибка создания файла 'report.txt'" << endl;
        }
    }
    
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    
    return 0;

}
