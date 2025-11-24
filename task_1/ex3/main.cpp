#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void printStudentInfo() {
    cout << "Student: Skvorcov Serafim" << endl;
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
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    auto m = randomMatrix(rows, cols);
    cout << "Original matrix:" << endl;
    printMatrix(m);

    auto t = transpose(m);
    cout << "Transposed matrix:" << endl;
    printMatrix(t);

    // ГАРАНТИРОВАННАЯ ПАУЗА
    cout << "\n=== PROGRAM FINISHED ===" << endl;
    cout << "Press any key to exit..." << endl;
    system("pause > nul");
    system("pause");

    return 0;
}
