#include <iostream>
#include <fstream>
#include <string>
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
    
    ofstream file("books.txt");
    
    if (!file.is_open()) {
        cout << "Ошибка создания файла!" << endl;
        return 1;
    }
    
    
    file << "1. Name: The Great Gatsby" << endl;
    file << "   Author: F. Scott Fitzgerald" << endl;
    file << "   Year: 1925" << endl;
    file << "   ----------" << endl;
    
    file << "2. Name: To Kill a Mockingbird" << endl;
    file << "   Author: Harper Lee" << endl;
    file << "   Year: 1960" << endl;
    file << "   ----------" << endl;
    
    file << "3. Name: 1984" << endl;
    file << "   Author: George Orwell" << endl;
    file << "   Year: 1949" << endl;
    file << "   ----------" << endl;
    
    file << "4. Name: Pride and Prejudice" << endl;
    file << "   Author: Jane Austen" << endl;
    file << "   Year: 1813" << endl;
    file << "   ----------" << endl;
    
    file << "5. Name: The Catcher in the Rye" << endl;
    file << "   Author: J.D. Salinger" << endl;
    file << "   Year: 1951" << endl;
    file << "   ----------" << endl;
    
    file.close();
    
    cout << "Файл 'books.txt' успешно создан с 5 записями о книгах." << endl;
    
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    
    return 0;
}