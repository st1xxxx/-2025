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
    cout << "Task: 3" << endl;
    cout << endl;
}


void printVector(const vector<int>& vec) {
    cout << "My vector has " << vec.size() << " of these elements: ";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << "[" << i << "] -> " << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << endl;
}

void printVector(const vector<string>& vec) {
    cout << "My vector has " << vec.size() << " of these elements: ";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << "[" << i << "] -> " << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << endl;
}

void printVector(const vector<double>& vec) {
    cout << "My vector has " << vec.size() << " of these elements: ";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << "[" << i << "] -> " << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << endl;
}

void printVector(const vector<char>& vec) {
    cout << "My vector has " << vec.size() << " of these elements: ";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << "[" << i << "] -> " << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << endl;
}

int main() {
    printStudentInfo();
    
    
    vector<int> intVec = {1, 2, 3, 4, 5};
    vector<string> strVec = {"apple", "banana", "cherry"};
    vector<double> doubleVec = {1.1, 2.2, 3.3, 4.4};
    vector<char> charVec = {'A', 'B', 'C', 'D'};
    
    cout << "Integer vector:" << endl;
    printVector(intVec);
    
    cout << "\nString vector:" << endl;
    printVector(strVec);
    
    cout << "\nDouble vector:" << endl;
    printVector(doubleVec);
    
    cout << "\nChar vector:" << endl;
    printVector(charVec);
    
    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    
    return 0;
}
