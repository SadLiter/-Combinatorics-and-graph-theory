def heapify(arr, n, i):
    largest = i       # Инициализируем наибольший элемент как корень
    left = 2 * i + 1  # левый = 2*i + 1
    right = 2 * i + 2 # правый = 2*i + 2

    # Проверяем, существует ли левый дочерний элемент и больше ли он корня
    if left < n and arr[left] > arr[largest]:
        largest = left

    # Проверяем, существует ли правый дочерний элемент и больше ли он текущего наибольшего
    if right < n and arr[right] > arr[largest]:
        largest = right

    # Если наибольший элемент не корень
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # обмен

        # Рекурсивно применяем heapify к поддереву
        heapify(arr, n, largest)

def heapsort(arr):
    n = len(arr)

    # Построение максимальной кучи
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # Один за другим извлекаем элементы из кучи
    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]   # обмен
        heapify(arr, i, 0)

# Пример использования
if __name__ == "__main__":
    data = [12, 11, 13, 5, 6, 7]
    print("Исходный массив:", data)
    heapsort(data)
    print("Отсортированный массив:", data)