#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

class FordFulkerson {
private:
    int n; // Количество вершин
    vector<vector<int>> capacity; // Матрица пропускных способностей
    vector<vector<int>> adj;      // Список смежности для графа

public:
    FordFulkerson(int n) : n(n), capacity(n, vector<int>(n, 0)), adj(n) {}

    void add_edge(int u, int v, int cap) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v] += cap; // Поддержка нескольких рёбер между вершинами
    }

    int bfs(int source, int sink, vector<int>& parent) {
        fill(parent.begin(), parent.end(), -1);
        parent[source] = source;
        queue<pair<int, int>> q;
        q.push({source, INT_MAX});

        while (!q.empty()) {
            int current = q.front().first;
            int flow = q.front().second;
            q.pop();

            for (int next : adj[current]) {
                if (parent[next] == -1 && capacity[current][next] > 0) {
                    parent[next] = current;
                    int new_flow = min(flow, capacity[current][next]);
                    if (next == sink) {
                        return new_flow;
                    }
                    q.push({next, new_flow});
                }
            }
        }
        return 0;
    }

    int max_flow(int source, int sink) {
        int flow = 0;
        vector<int> parent(n);
        int new_flow;

        while (new_flow = bfs(source, sink, parent)) {
            flow += new_flow;
            int current = sink;
            while (current != source) {
                int prev = parent[current];
                capacity[prev][current] -= new_flow;
                capacity[current][prev] += new_flow;
                current = prev;
            }
        }
        return flow;
    }
};

#ifndef TESTING // Условная компиляция для отключения main()
int main() {
    int n, m;
    cin >> n >> m; // Чтение количества вершин и рёбер
    FordFulkerson ff(n);

    for (int i = 0; i < m; ++i) {
        int u, v, capacity;
        cin >> u >> v >> capacity;
        ff.add_edge(u, v, capacity);
    }

    int source, sink;
    cin >> source >> sink; // Чтение истока и стока

    cout << "Max Flow: " << ff.max_flow(source, sink) << endl;

    return 0;
}
#endif
