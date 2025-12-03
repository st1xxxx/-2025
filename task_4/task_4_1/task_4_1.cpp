#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <windows.h>

using namespace std;

void printStudentInfo() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "Student: Skvortsov Serafim Denisovich" << endl;
    cout << "Group: M10-137BV-25" << endl;
    cout << "Task: 1" << endl;
    cout << endl;
}

struct Book {
    string title;
    string author;
    int year;
    int pages;
    
    void display() const {
        cout << "Название: " << title << endl;
        cout << "Автор: " << author << endl;
        cout << "Год издания: " << year << endl;
        cout << "Количество страниц: " << pages << endl;
    }
    
    bool isModern() const {
        return year > 2000;
    }
};

int main() {
    printStudentInfo();
    
    
    vector<Book> library(5);
    
    library[0] = {"Война и мир", "Лев Толстой", 1869, 1225};
    library[1] = {"Преступление и наказание", "Фёдор Достоевский", 1866, 671};
    library[2] = {"Мастер и Маргарита", "Михаил Булгаков", 1967, 480};
    library[3] = {"Евгений Онегин", "Александр Пушкин", 1833, 224};
    library[4] = {"Мёртвые души", "Николай Гоголь", 1842, 352};
    
    cout << "Каталог библиотеки:" << endl;
    cout << "==================" << endl << endl;
    
    for (size_t i = 0; i < library.size(); i++) {
        cout << "Книга #" << (i + 1) << ":" << endl;
        library[i].display();
        cout << "Современная (после 2000): " << (library[i].isModern() ? "Да" : "Нет") << endl;
        cout << endl;
    }
    
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    
    return 0;
}
