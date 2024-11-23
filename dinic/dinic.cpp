#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

// Класс для представления рёбер
struct Edge {
    int to, rev;
    long long capacity, flow;
    Edge(int to, int rev, long long capacity)
        : to(to), rev(rev), capacity(capacity), flow(0) {}
};

class Dinic {
private:
    vector<vector<Edge>> graph;
    vector<int> level;
    vector<int> ptr;
    int n;

public:
    Dinic(int n) : n(n), graph(n), level(n), ptr(n) {}

    void add_edge(int u, int v, long long capacity) {
        graph[u].emplace_back(v, graph[v].size(), capacity);
        graph[v].emplace_back(u, graph[u].size() - 1, 0); // Обратное ребро
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (const Edge& edge : graph[u]) {
                if (edge.capacity - edge.flow > 0 && level[edge.to] == -1) {
                    level[edge.to] = level[u] + 1;
                    q.push(edge.to);
                }
            }
        }
        return level[t] != -1;
    }

    long long dfs(int u, int t, long long pushed) {
        if (u == t || pushed == 0) {
            return pushed;
        }
        for (int& cid = ptr[u]; cid < graph[u].size(); ++cid) {
            Edge& edge = graph[u][cid];
            if (level[edge.to] != level[u] + 1 || edge.capacity - edge.flow <= 0) {
                continue;
            }
            long long tr = dfs(edge.to, t, min(pushed, edge.capacity - edge.flow));
            if (tr > 0) {
                edge.flow += tr;
                graph[edge.to][edge.rev].flow -= tr;
                return tr;
            }
        }
        return 0;
    }

    long long max_flow(int s, int t) {
        long long flow = 0;
        while (bfs(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, t, LLONG_MAX)) {
                flow += pushed;
            }
        }
        return flow;
    }
};

#ifndef TESTING // Условная компиляция для отключения main()
int main() {
    int n, m;
    cin >> n >> m; // Чтение количества вершин и рёбер
    Dinic dinic(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        long long capacity;
        cin >> u >> v >> capacity; // Чтение рёбер
        dinic.add_edge(u, v, capacity);
    }

    int s, t;
    cin >> s >> t; // Чтение истока и стока

    cout << "Maximum Flow: " << dinic.max_flow(s, t) << endl;

    return 0;
}
#endif