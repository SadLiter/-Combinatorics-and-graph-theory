import random
import time
import unittest

def heapify(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and arr[left] > arr[largest]:
        largest = left

    if right < n and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def heapsort(arr):
    n = len(arr)

    # Построение максимальной кучи
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # Извлечение элементов из кучи
    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)

class TestHeapsort(unittest.TestCase):
    def test_empty_array(self):
        arr = []
        heapsort(arr)
        self.assertEqual(arr, [])

    def test_single_element(self):
        arr = [1]
        heapsort(arr)
        self.assertEqual(arr, [1])

    def test_sorted_array(self):
        arr = [1, 2, 3, 4, 5]
        heapsort(arr)
        self.assertEqual(arr, [1, 2, 3, 4, 5])

    def test_reverse_sorted_array(self):
        arr = [5, 4, 3, 2, 1]
        heapsort(arr)
        self.assertEqual(arr, [1, 2, 3, 4, 5])

    def test_random_array(self):
        arr = [random.randint(0, 1000) for _ in range(1000)]
        expected = sorted(arr)
        heapsort(arr)
        self.assertEqual(arr, expected)

    def test_duplicates(self):
        arr = [5, 3, 8, 3, 9, 1, 5]
        heapsort(arr)
        self.assertEqual(arr, [1, 3, 3, 5, 5, 8, 9])

if __name__ == "__main__":

    # Измерение времени выполнения
    data = [random.randint(0, 1000000) for _ in range(1000000)]
    start_time = time.time()
    heapsort(data)
    end_time = time.time()
    print(f"Время выполнения heapsort для 100000 элементов: {end_time - start_time} секунд")

    # Запуск тестов
    unittest.main()