#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Функция для восстановления свойств кучи
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;       // Инициализируем корень как наибольший элемент
    int left = 2 * i + 1;  // Левый дочерний элемент
    int right = 2 * i + 2; // Правый дочерний элемент

    // Если левый дочерний элемент больше корня
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Если правый дочерний элемент больше текущего наибольшего
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Если наибольший элемент не корень, выполняем обмен
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Рекурсивно восстанавливаем кучу
    }
}

// Основная функция сортировки Heapsort
void heapsort(vector<int>& arr) {
    int n = arr.size();

    // Построение кучи (перестановка массива)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Извлечение элементов из кучи
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);     // Перемещаем текущий корень в конец
        heapify(arr, i, 0);       // Восстанавливаем свойства кучи для оставшихся элементов
    }
}

#ifndef TESTING  // Условная компиляция: main() будет включен, только если TESTING не определён
int main() {
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    heapsort(arr);

    cout << "Отсортированный массив:\n";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
#endif
