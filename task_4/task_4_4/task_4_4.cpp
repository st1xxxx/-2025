#include <iostream>
#include <cmath>
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

struct MyRectangle {
    int x1, y1; 
    int x2, y2; 
    
    double calculateArea() const {
        int width = abs(x2 - x1);
        int height = abs(y2 - y1);
        return width * height;
    }
    
    double calculatePerimeter() const {
        int width = abs(x2 - x1);
        int height = abs(y2 - y1);
        return 2 * (width + height);
    }
    
    void move(int dx, int dy) {
        cout << "Перемещение прямоугольника на dx=" << dx << ", dy=" << dy << endl;
        x1 += dx;
        y1 += dy;
        x2 += dx;
        y2 += dy;
    }
    
    bool isSquare() const {
        int width = abs(x2 - x1);
        int height = abs(y2 - y1);
        return width == height;
    }
    
    void display() const {
        cout << "Координаты прямоугольника:" << endl;
        cout << "  Верхняя левая: (" << x1 << ", " << y1 << ")" << endl;
        cout << "  Нижняя правая: (" << x2 << ", " << y2 << ")" << endl;
        cout << "  Ширина: " << abs(x2 - x1) << endl;
        cout << "  Высота: " << abs(y2 - y1) << endl;
        cout << "  Площадь: " << calculateArea() << endl;
        cout << "  Периметр: " << calculatePerimeter() << endl;
        cout << "  Является квадратом: " << (isSquare() ? "Да" : "Нет") << endl;
    }
};

int main() {
    printStudentInfo();
    
    cout << "Демонстрация прямоугольника" << endl;
    cout << "============================" << endl << endl;
    
    
    MyRectangle rect1 = {0, 10, 5, 2};
    
    cout << "Начальный прямоугольник:" << endl;
    rect1.display();
    cout << endl;
    
    
    rect1.move(3, -2);
    cout << "\nПосле перемещения:" << endl;
    rect1.display();
    cout << endl;
    
    
    MyRectangle square = {1, 6, 5, 2};
    
    cout << "\nПример квадрата:" << endl;
    square.display();
    cout << endl;
    
    
    square.move(-1, 1);
    cout << "\nПосле перемещения квадрата:" << endl;
    square.display();
    
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    
    return 0;
}
