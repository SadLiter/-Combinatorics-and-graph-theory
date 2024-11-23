#include <iostream>
#include <vector>
#include <cassert>
#include "dinic.cpp" // Подключаем реализацию алгоритма Диница

void test_case_1() {
    // Пример из стандартного учебника
    Dinic dinic(6);
    dinic.add_edge(0, 1, 16);
    dinic.add_edge(0, 2, 13);
    dinic.add_edge(1, 2, 10);
    dinic.add_edge(1, 3, 12);
    dinic.add_edge(2, 4, 14);
    dinic.add_edge(4, 3, 7);
    dinic.add_edge(3, 5, 20);
    dinic.add_edge(4, 5, 4);

    int max_flow = dinic.max_flow(0, 5);
    assert(max_flow == 23);
    std::cout << "Test case 1 passed!" << std::endl;
}

void test_case_2() {
    // Сеть с двумя путями одинаковой пропускной способности
    Dinic dinic(4);
    dinic.add_edge(0, 1, 10);
    dinic.add_edge(0, 2, 10);
    dinic.add_edge(1, 3, 10);
    dinic.add_edge(2, 3, 10);

    int max_flow = dinic.max_flow(0, 3);
    assert(max_flow == 20);
    std::cout << "Test case 2 passed!" << std::endl;
}

void test_case_3() {
    // Сеть с циклом
    Dinic dinic(4);
    dinic.add_edge(0, 1, 10);
    dinic.add_edge(1, 2, 5);
    dinic.add_edge(2, 1, 15);
    dinic.add_edge(2, 3, 10);

    int max_flow = dinic.max_flow(0, 3);
    assert(max_flow == 10);
    std::cout << "Test case 3 passed!" << std::endl;
}

void test_case_4() {
    // Сеть без соединения между истоком и стоком
    Dinic dinic(4);
    dinic.add_edge(0, 1, 10);
    dinic.add_edge(2, 3, 5);

    int max_flow = dinic.max_flow(0, 3);
    assert(max_flow == 0);
    std::cout << "Test case 4 passed!" << std::endl;
}

void test_case_5() {
    // Граф с одним рёбром
    Dinic dinic(2);
    dinic.add_edge(0, 1, 5);

    int max_flow = dinic.max_flow(0, 1);
    assert(max_flow == 5);
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
