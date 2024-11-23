#include <iostream>
#include <vector>
#include <cassert>
#include "heapsort.cpp" // Подключаем реализацию Heapsort

void test_case_1() {
    std::vector<int> arr = {4, 10, 3, 5, 1};
    heapsort(arr);
    assert((arr == std::vector<int>{1, 3, 4, 5, 10}));
    std::cout << "Test case 1 passed!" << std::endl;
}

void test_case_2() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    heapsort(arr);
    assert((arr == std::vector<int>{1, 2, 3, 4, 5}));
    std::cout << "Test case 2 passed!" << std::endl;
}

void test_case_3() {
    std::vector<int> arr = {5, 4, 3, 2, 1};
    heapsort(arr);
    assert((arr == std::vector<int>{1, 2, 3, 4, 5}));
    std::cout << "Test case 3 passed!" << std::endl;
}

void test_case_4() {
    std::vector<int> arr = {1};
    heapsort(arr);
    assert((arr == std::vector<int>{1}));
    std::cout << "Test case 4 passed!" << std::endl;
}

void test_case_5() {
    std::vector<int> arr = {};
    heapsort(arr);
    assert((arr == std::vector<int>{}));
    std::cout << "Test case 5 passed!" << std::endl;
}

int main() {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();
    test_case_5();

    std::cout << "All test cases passed!" << std::endl;
    return 0;
}
