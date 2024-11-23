import unittest
from ford_fulkerson import FordFulkerson

class TestFordFulkerson(unittest.TestCase):
    def test_case_1(self):
        ff = FordFulkerson(6)
        edges = [
            (0, 1, 16),
            (0, 2, 13),
            (1, 2, 10),
            (1, 3, 12),
            (2, 1, 4),
            (2, 4, 14),
            (3, 2, 9),
            (3, 5, 20),
            (4, 3, 7),
            (4, 5, 4)
        ]
        for u, v, c in edges:
            ff.add_edge(u, v, c)
        self.assertEqual(ff.max_flow(0, 5), 23)

    def test_case_2(self):
        ff = FordFulkerson(4)
        edges = [
            (0, 1, 1000),
            (1, 2, 1),
            (2, 3, 1000)
        ]
        for u, v, c in edges:
            ff.add_edge(u, v, c)
        self.assertEqual(ff.max_flow(0, 3), 1)

    def test_case_3(self):
        ff = FordFulkerson(2)
        edges = [
            (0, 1, 10)
        ]
        for u, v, c in edges:
            ff.add_edge(u, v, c)
        self.assertEqual(ff.max_flow(0, 1), 10)

if __name__ == "__main__":
    unittest.main()
