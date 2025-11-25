#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

void printStudentInfo() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "Student: Skvortsov Serafim Denisovich" << endl;
    cout << "Group: M10-137BV-25" << endl;
    cout << "Task: 3" << endl;
    cout << endl;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }
}

vector<vector<int>> randomMatrix(int rows, int cols) {
    srand(time(nullptr));
    vector<vector<int>> m(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m[i][j] = rand() % 1001 - 500;
        }
    }
    return m;
}

vector<vector<int>> transpose(const vector<vector<int>>& a) {
    if (a.empty()) return {};
    size_t rows = a.size();
    size_t cols = a[0].size();
    vector<vector<int>> t(cols, vector<int>(rows));
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            t[j][i] = a[i][j];
    return t;
}

int main() {
    printStudentInfo();

    int rows, cols;
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;

    auto m = randomMatrix(rows, cols);
    cout << "Исходная матрица:" << endl;
    printMatrix(m);

    auto t = transpose(m);
    cout << "Транспонированная матрица:" << endl;
    printMatrix(t);

    cout << "\n=== ПРОГРАММА ЗАВЕРШЕНА ===" << endl;
    cout << "Нажмите любую клавишу для выхода..." << endl;
    system("pause > nul");
    system("pause");

    return 0;
}
