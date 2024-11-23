import collections

class Edge:
    """Класс для представления ребра графа."""
    def __init__(self, to, capacity):
        self.to = to
        self.capacity = capacity
        self.flow = 0
        self.rev = None

class Dinic:
    """Класс для реализации алгоритма Диница."""
    def __init__(self, n):
        self.n = n
        self.graph = [[] for _ in range(n)]
    
    def add_edge(self, u, v, capacity):
        """Добавляет ребро с пропускной способностью."""
        forward = Edge(v, capacity)
        backward = Edge(u, 0)
        forward.rev = backward
        backward.rev = forward
        self.graph[u].append(forward)
        self.graph[v].append(backward)
    
    def bfs(self, s, t):
        """Построение уровневого графа (обход в ширину)."""
        self.level = [-1] * self.n
        self.level[s] = 0
        queue = collections.deque([s])
        while queue:
            u = queue.popleft()
            for edge in self.graph[u]:
                if edge.capacity - edge.flow > 0 and self.level[edge.to] == -1:
                    self.level[edge.to] = self.level[u] + 1
                    queue.append(edge.to)
        return self.level[t] != -1
    
    def dfs(self, u, t, flow):
        """Поиск блокирующего потока (обход в глубину)."""
        if u == t:
            return flow
        for edge in self.ptr[u]:
            if edge.capacity - edge.flow > 0 and self.level[edge.to] == self.level[u] + 1:
                pushed = self.dfs(edge.to, t, min(flow, edge.capacity - edge.flow))
                if pushed > 0:
                    edge.flow += pushed
                    edge.rev.flow -= pushed
                    return pushed
        return 0
    
    def max_flow(self, s, t):
        """Вычисление максимального потока."""
        flow = 0
        while self.bfs(s, t):
            self.ptr = [iter(self.graph[u]) for u in range(self.n)]
            while True:
                pushed = self.dfs(s, t, float('inf'))
                if pushed == 0:
                    break
                flow += pushed
        return flow

def main():
    """Пример использования алгоритма Диница."""
    n, m = map(int, input().split())  # Количество вершин и рёбер
    dinic = Dinic(n)
    for _ in range(m):
        u, v, c = map(int, input().split())
        dinic.add_edge(u, v, c)
    s, t = map(int, input().split())  # Исток и сток
    print("Максимальный поток:", dinic.max_flow(s, t))

if __name__ == "__main__":
    main()
