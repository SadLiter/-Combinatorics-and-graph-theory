#include <iostream>
#include <cassert>
#include "ford_fulkerson.cpp"

void test_case_1() {
    FordFulkerson ff(6);
    ff.add_edge(0, 1, 16);
    ff.add_edge(0, 2, 13);
    ff.add_edge(1, 2, 10);
    ff.add_edge(1, 3, 12);
    ff.add_edge(2, 1, 4);
    ff.add_edge(2, 4, 14);
    ff.add_edge(3, 2, 9);
    ff.add_edge(3, 5, 20);
    ff.add_edge(4, 3, 7);
    ff.add_edge(4, 5, 4);

    assert(ff.max_flow(0, 5) == 23);
    cout << "Test case 1 passed!" << endl;
}

void test_case_2() {
    FordFulkerson ff(4);
    ff.add_edge(0, 1, 1000);
    ff.add_edge(1, 2, 1);
    ff.add_edge(2, 3, 1000);

    assert(ff.max_flow(0, 3) == 1);
    cout << "Test case 2 passed!" << endl;
}

void test_case_3() {
    FordFulkerson ff(2);
    ff.add_edge(0, 1, 10);

    assert(ff.max_flow(0, 1) == 10);
    cout << "Test case 3 passed!" << endl;
}

int main() {
    test_case_1();
    test_case_2();
    test_case_3();

    cout << "All test cases passed!" << endl;
    return 0;
}
