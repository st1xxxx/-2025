#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <limits> // Добавляем этот заголовок
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void printStudentInfo() {
    cout << "Студент: Скворцов Серафим Денисович" << endl;
    cout << "Группа: M10-137БВ-25" << endl;
    cout << "Задача: 2" << endl;
    cout << endl;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            cout << element << '\t';
        }
        cout << endl;
    }
}

vector<vector<int>> randomMatrix(int rows, int cols, int minv = -500, int maxv = 500) {
    std::mt19937 rng(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<int> dist(minv, maxv);
    vector<vector<int>> m(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            m[i][j] = dist(rng);
        }
    }
    return m;
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    printStudentInfo();

    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    auto m = randomMatrix(rows, cols);
    cout << "Generated matrix:" << endl;
    printMatrix(m);

    // ИСПРАВЛЕННАЯ ЧАСТЬ:
    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер
    cin.get(); 

    return 0;
}
