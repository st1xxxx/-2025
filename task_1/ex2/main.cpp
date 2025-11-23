#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

void printStudentInfo() {
    cout << "Student: Skvorcov Serafim" << endl;
    cout << "Group: M10-137BV-25" << endl;
    cout << "Task: 2" << endl;
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

vector<vector<int>> randomMatrix(int rows, int cols) {
    srand(time(nullptr)); // Простой генератор случайных чисел
    vector<vector<int>> m(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            m[i][j] = rand() % 1001 - 500; // от -500 до 500
        }
    }
    return m;
}

int main() {
    printStudentInfo();

    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    auto m = randomMatrix(rows, cols);
    cout << "Generated matrix:" << endl;
    printMatrix(m);

    
    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}
