# Сортировка "Heapsort" (пирамидальная сортировка)

Этот проект реализует алгоритм пирамидальной сортировки (Heapsort) на Python и C++. Алгоритм используется для упорядочивания массивов с использованием структуры данных "бинарная куча".

---

## Структура проекта

```
Общая папка/
├── heapsort.py           # Реализация Heapsort на Python
├── test_heapsort.py      # Тестирование Heapsort на Python
├── input.txt             # Пример входных данных (опционально)
├── heapsort.cpp          # Реализация Heapsort на C++
├── test_heapsort.cpp     # Тестирование Heapsort на C++
├── README.md             # Описание проекта
```

---

## Используемые файлы

### 1. `heapsort.py` (Python)
Файл содержит реализацию алгоритма Heapsort для сортировки массива.

#### Основные функции:
- **`heapify(arr, n, i)`**  
  Перестраивает поддерево с корнем в индексе `i` для обеспечения свойств бинарной кучи.

- **`heapsort(arr)`**  
  Основная функция для сортировки массива.  
  Последовательно:
  1. Преобразует массив в бинарную кучу.
  2. Извлекает элементы из кучи, формируя отсортированный массив.

#### Пример использования:
```python
from heapsort import heapsort

arr = [4, 10, 3, 5, 1]
heapsort(arr)
print(arr)  # Вывод: [1, 3, 4, 5, 10]
```

---

### 2. `test_heapsort.py` (Python)
Модуль для тестирования реализации Heapsort. Использует библиотеку `unittest`.

#### Основные тесты:
- **Сортировка пустого массива:** Проверяет, что пустой массив остаётся пустым.
- **Сортировка массива из одного элемента:** Проверяет корректность для минимального входа.
- **Сортировка случайного массива:** Проверяет корректность на массиве произвольного размера.
- **Сортировка массива с повторяющимися элементами:** Убедиться, что алгоритм корректно работает с дубликатами.

#### Как запустить:
```bash
python test_heapsort.py
```

Пример вывода:
```plaintext
...
----------------------------------------------------------------------
Ran 4 tests in 0.001s

OK
```

---

### 3. `heapsort.cpp` (C++)
Файл содержит реализацию алгоритма Heapsort для сортировки массива.

#### Основные функции:
- **`heapify(std::vector<int>& arr, int n, int i)`**  
  Перестраивает поддерево с корнем в индексе `i` для обеспечения свойств бинарной кучи.

- **`heapsort(std::vector<int>& arr)`**  
  Основная функция для сортировки массива.  
  Последовательно:
  1. Преобразует массив в бинарную кучу.
  2. Извлекает элементы из кучи, формируя отсортированный массив.

#### Пример использования:
```cpp
#include "heapsort.cpp"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {4, 10, 3, 5, 1};
    heapsort(arr);
    for (int x : arr) {
        cout << x << " ";
    }
    return 0;
}
```

#### Компиляция и запуск:
```bash
g++ -O2 -std=c++17 "heapsort.cpp" -o "heapsort"
./heapsort
```

Пример ввода:
```plaintext
5 3 8 6 2 1
```

Пример вывода:
```plaintext
1 2 3 5 6 8
```

---

### 4. `test_heapsort.cpp` (C++)
Файл для тестирования реализации Heapsort. Использует `assert` для проверки корректности работы.

#### Пример тестов:
```cpp
#include "heapsort.cpp"
#include <cassert>
#include <vector>
#include <iostream>

void test_case_1() {
    std::vector<int> arr = {4, 10, 3, 5, 1};
    heapsort(arr);
    assert((arr == std::vector<int>{1, 3, 4, 5, 10}));
    std::cout << "Test case 1 passed!" << std::endl;
}

int main() {
    test_case_1();
    std::cout << "All test cases passed!" << std::endl;
    return 0;
}
```

#### Компиляция и запуск:
```bash
g++ -O2 -std=c++17 -DTESTING "test_heapsort.cpp" -o "test_heapsort"
./test_heapsort
```

Пример вывода:
```plaintext
Test case 1 passed!
All test cases passed!
```

---

## Как запустить проект

### 1. Запуск Python-версии
Для сортировки массива используйте следующий код:
```python
from heapsort import heapsort

arr = [9, 7, 5, 3, 1]
heapsort(arr)
print(arr)  # Вывод: [1, 3, 5, 7, 9]
```

### 2. Запуск C++-версии
Скомпилируйте `heapsort.cpp`:
```bash
g++ -O2 -std=c++17 "heapsort.cpp" -o "heapsort"
./heapsort
```

---

### 3. Тестирование
#### Для Python:
```bash
python test_heapsort.py
```

#### Для C++:
```bash
g++ -O2 -std=c++17 -DTESTING "test_heapsort.cpp" -o "test_heapsort"
./test_heapsort
```

---

## Пример входных данных

Сохраните массив чисел в файле `input.txt` в одной строке, например:
```plaintext
4 10 3 5 1
```

Запустите программу, чтобы отсортировать массив:
```bash
python heapsort.py < input.txt
```

Пример вывода:
```plaintext
Отсортированный массив: [1, 3, 4, 5, 10]
```

---

## Примечания

- **Временная сложность:** \( O(n \log n) \).
- **Пространственная сложность:** \( O(1) \).
- C++-версия значительно быстрее Python на больших массивах благодаря компиляции и управлению памятью.