# task_2

Содержит решения для ДЗ №2 в папке `task_2` (task_2_1..task_2_5).

Как собрать (PowerShell, g++)

Есть вспомогательный скрипт для быстрой сборки всех задач: `build_all.ps1` (находится в этой папке). Запустите его из PowerShell в папке `task_2`:

```powershell
cd "C:\Users\Серафим\Desktop\repository\-2025-1\task_2"
.\build_all.ps1
Или собрать одну задачу вручную (пример для task_2_1):

powershell
cd "C:\Users\Серафим\Desktop\repository\-2025-1\task_2\task_2_1"
g++ -std=c++17 -O2 -Wall -Wextra -o task_2_1.exe main.cpp
.\task_2_1.exe
Если g++ не установлен на Windows, установите MSYS2 + mingw-w64 или используйте Visual Studio (Developer Command Prompt):

MSYS2 (кратко):

Скачайте и установите MSYS2 с https://www.msys2.org/

Откройте MSYS2 MinGW64 shell и выполните:

bash
pacman -Syu
pacman -S mingw-w64-x86_64-toolchain
В PowerShell добавьте в PATH C:\msys64\mingw64\bin или запускайте сборку из MinGW64 shell.

Использование Visual Studio (cl):

cmd
cl /EHsc main.cpp
main.exe
Описание файлов:

task_2_1/main.cpp — создание списка группы и успеваемости (map<string, vector<int>>). Ввод студентов с консоли, генерация случайных оценок в диапазоне [2;5].

task_2_2/main.cpp — функции для добавления и удаления элементов из словаря map<string, bool> (водительские права студентов).

task_2_3/main.cpp — перегруженная функция для вывода контейнера vector любого стандартного типа.

task_2_4/main.cpp — перегрузка операции + для последовательного объединения двух векторов.

task_2_5/main.cpp — перегруженная функция для вывода контейнера map для пары любых стандартных типов.

Примечания:

В каждом исходнике присутствует требуемая шапка с информацией о студенте (пункт 0). Данные: Скворцов Серафим Денисович, группа M10-137БВ-25.

Все программы поддерживают русскую кодировку и корректно ожидают ввода перед закрытием.

text