#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <limits>
#include <windows.h>

using namespace std;

void printStudentInfo() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "Студент: Скворцов Серафим Денисович" << endl;
    cout << "Группа: M10-137БВ-25" << endl;
    cout << "Задача: 5" << endl;
    cout << endl;
}


template<typename K, typename V>
void printMap(const map<K, V>& myMap) {
    cout << "My map has " << myMap.size() << " of keys and has these pairs:" << endl;
    for (const auto& pair : myMap) {
        cout << "[" << pair.first << "] -> {" << pair.second << "}" << endl;
    }
}


template<typename K, typename V>
void printMap(const map<K, vector<V>>& myMap) {
    cout << "My map has " << myMap.size() << " of keys and has these pairs:" << endl;
    for (const auto& pair : myMap) {
        cout << "[" << pair.first << "] -> {";
        for (size_t i = 0; i < pair.second.size(); i++) {
            cout << pair.second[i];
            if (i < pair.second.size() - 1) cout << ", ";
        }
        cout << "}" << endl;
    }
}


template<typename K, typename V>
void printMap(const map<vector<K>, V>& myMap) {
    cout << "My map has " << myMap.size() << " of keys and has these pairs:" << endl;
    for (const auto& pair : myMap) {
        cout << "[";
        for (size_t i = 0; i < pair.first.size(); i++) {
            cout << pair.first[i];
            if (i < pair.first.size() - 1) cout << ", ";
        }
        cout << "] -> {" << pair.second << "}" << endl;
    }
}

int main() {
    printStudentInfo();
    
    
    map<string, int> simpleMap = {
        {"apple", 10},
        {"banana", 20},
        {"cherry", 30}
    };
    
    cout << "Map с простыми типами:" << endl;
    printMap(simpleMap);
    
    
    map<string, vector<int>> mapWithVector = {
        {"scores1", {85, 90, 78}},
        {"scores2", {92, 88, 95}},
        {"scores3", {76, 85, 80}}
    };
    
    cout << "\nMap с vector как значением:" << endl;
    printMap(mapWithVector);
    
    
    map<vector<int>, string> mapWithVectorKey = {
        {{1, 2, 3}, "first"},
        {{4, 5}, "second"},
        {{6, 7, 8, 9}, "third"}
    };
    
    cout << "\nMap с vector как ключом:" << endl;
    printMap(mapWithVectorKey);
    
    cout << "\nНажмите Enter для выхода...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    
    return 0;
}


