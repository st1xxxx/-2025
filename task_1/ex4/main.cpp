#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void printStudentInfo() {
    cout << "Студент: Скворцов Серафим Денисович" << endl;
    cout << "Группа: M10-137БВ-25" << endl;
    cout << "Задача: 4" << endl;
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

bool multiply(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C) {
    if (A.empty() || B.empty()) return false;
    size_t r1 = A.size();
    size_t c1 = A[0].size();
    size_t r2 = B.size();
    size_t c2 = B[0].size();
    if (c1 != r2) return false;
    C.assign(r1, vector<int>(c2, 0));
    for (size_t i = 0; i < r1; ++i)
        for (size_t k = 0; k < c1; ++k)
            for (size_t j = 0; j < c2; ++j)
                C[i][j] += A[i][k] * B[k][j];
    return true;
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    printStudentInfo();

    int r1, c1, r2, c2;
    cout << "Enter rows and cols for matrix A (two integers): ";
    if (!(cin >> r1 >> c1)) return 0;
    cout << "Enter rows and cols for matrix B (two integers): ";
    if (!(cin >> r2 >> c2)) return 0;

    // Basic validation to avoid negative/zero sizes and unreasonable allocations
    const int MAX_DIM = 1000; // safety cap to avoid huge allocations
    if (r1 <= 0 || c1 <= 0 || r2 <= 0 || c2 <= 0) {
        cout << "Error: rows and cols must be positive integers." << endl;
        return 1;
    }
    if (r1 > MAX_DIM || c1 > MAX_DIM || r2 > MAX_DIM || c2 > MAX_DIM) {
        cout << "Error: dimensions too large (max " << MAX_DIM << ")." << endl;
        return 1;
    }

    if (c1 != r2) {
        cout << "Matrices cannot be multiplied: A.columns != B.rows" << endl;
        return 1;
    }

    vector<vector<int>> A, B;
    try {
        A = randomMatrix(r1, c1);
        B = randomMatrix(r2, c2);
    } catch (const std::bad_alloc&) {
        cout << "Error: not enough memory to allocate matrices with given sizes." << endl;
        return 1;
    }

    cout << "Matrix A:" << endl;
    printMatrix(A);
    cout << "Matrix B:" << endl;
    printMatrix(B);

    vector<vector<int>> C;
    if (multiply(A, B, C)) {
        cout << "Product A * B:" << endl;
        printMatrix(C);
    } else {
        cout << "Matrices cannot be multiplied: A.columns != B.rows" << endl;
    }

    return 0;
}
