from collections import defaultdict, deque

class FordFulkerson:
    def __init__(self, n):
        self.n = n  # Количество вершин
        self.graph = defaultdict(list)  # Список смежности для графа
        self.capacity = {}  # Пропускные способности рёбер

    def add_edge(self, u, v, capacity):
        """Добавляет ребро с пропускной способностью."""
        self.graph[u].append(v)
        self.graph[v].append(u)
        self.capacity[(u, v)] = capacity
        self.capacity[(v, u)] = 0  # Обратное ребро с нулевой пропускной способностью

    def bfs(self, source, sink, parent):
        """Поиск пути увеличения потока с использованием BFS."""
        visited = [False] * self.n
        queue = deque([source])
        visited[source] = True
        while queue:
            current = queue.popleft()
            for neighbor in self.graph[current]:
                # Ищем ребро с ненулевой остаточной пропускной способностью
                if not visited[neighbor] and self.capacity[(current, neighbor)] > 0:
                    parent[neighbor] = current
                    if neighbor == sink:
                        return True
                    visited[neighbor] = True
                    queue.append(neighbor)
        return False

    def max_flow(self, source, sink):
        """Вычисляет максимальный поток."""
        flow = 0
        parent = [-1] * self.n
        while self.bfs(source, sink, parent):
            # Найти минимальную пропускную способность вдоль пути увеличения
            path_flow = float('inf')
            current = sink
            while current != source:
                prev = parent[current]
                path_flow = min(path_flow, self.capacity[(prev, current)])
                current = prev

            # Обновить остаточные пропускные способности рёбер
            current = sink
            while current != source:
                prev = parent[current]
                self.capacity[(prev, current)] -= path_flow
                self.capacity[(current, prev)] += path_flow
                current = prev

            flow += path_flow
        return flow

def main():
    """Пример использования алгоритма Форда-Фалкерсона."""
    n, m = map(int, input().split())  # Чтение количества вершин и рёбер
    ff = FordFulkerson(n)
    for _ in range(m):
        u, v, capacity = map(int, input().split())
        ff.add_edge(u, v, capacity)
    source, sink = map(int, input().split())  # Исток и сток
    print("Максимальный поток:", ff.max_flow(source, sink))

if __name__ == "__main__":
    main()
