#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <limits> // Добавляем для numeric_limits
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void printStudentInfo() {
    cout << "Студент: Скворцов Серафим Денисович" << endl;
    cout << "Группа: M10-137БВ-25" << endl;
    cout << "Задача: 3" << endl;
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

vector<vector<int>> transpose(const vector<vector<int>>& a) {
    if (a.empty()) return {};
    size_t rows = a.size();
    size_t cols = a[0].size();
    vector<vector<int>> t(cols, vector<int>(rows));
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < cols; ++j)
            t[j][i] = a[i][j];
    return t;
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    printStudentInfo();

    int rows, cols;
    cout << "Enter number of rows: ";
    if (!(cin >> rows)) return 0;
    cout << "Enter number of columns: ";
    if (!(cin >> cols)) return 0;

    auto m = randomMatrix(rows, cols);
    cout << "Original matrix:" << endl;
    printMatrix(m);

    auto t = transpose(m);
    cout << "Transposed matrix:" << endl;
    printMatrix(t);

    // ДОБАВЛЯЕМ ОЖИДАНИЕ ВВОДА
    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
    cin.get(); // Ждем нажатия Enter

    return 0;
}
