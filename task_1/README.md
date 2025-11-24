# task_1

Содержит решения для ДЗ №1 в папке `task_1` (task_1_1..task_1_4).

Как собрать (PowerShell, g++)

Есть вспомогательный скрипт для быстрой сборки всех задач: `build_all.ps1` (находится в этой папке). Запустите его из PowerShell в папке `task_1`:

```powershell
cd "c:\Users\Серафим\Desktop\repository\-2025-1\task_1"
.\build_all.ps1
```

Или собрать одну задачу вручную (пример для `ex1`):

```powershell
cd "c:\Users\Серафим\Desktop\repository\-2025-1\task_1\task_1_1"
g++ -std=c++17 -O2 -Wall -Wextra -o task_1_1.exe main.cpp
.\ex1.exe
```

Если g++ не установлен на Windows, установите MSYS2 + mingw-w64 или используйте Visual Studio (Developer Command Prompt):

MSYS2 (кратко):
1. Скачайте и установите MSYS2 с https://www.msys2.org/
2. Откройте MSYS2 MinGW64 shell и выполните:

```bash
pacman -Syu
pacman -S mingw-w64-x86_64-toolchain
```

3. В PowerShell добавьте в PATH `C:\msys64\mingw64\bin` или запускайте сборку из MinGW64 shell.

Использование Visual Studio (cl):

```cmd
cl /EHsc main.cpp
main.exe
```

Описание файлов:
- `ex1/main.cpp` — реализация `printMatrix` и пример использования.
- `ex2/main.cpp` — генерация случайной матрицы размера rows x cols (значения в [-500,500]). Ввод размеров с консоли.
- `ex3/main.cpp` — транспонирование матрицы (вывод до и после).
- `ex4/main.cpp` — умножение двух матриц (проверка совместимости и вывод результата).

Примечания:
- В каждом исходнике присутствует требуемая шапка с информацией о студенте (пункт 0). Данные заменены на: `Скворцов Серафим Денисович`, группа `M10-137БВ-25`.
