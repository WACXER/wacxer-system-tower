//implement the Ford-Fulkerson algorithm 
//for maximum flow in C++ 
#include <vector>
#include <queue>

int maxFlow (std::vector<std::vector<int>>& graph, int source, int sink) {
    int n = graph.size();
    std::vector<std::vector<int>> residual = graph;

    std::function<bool(std::vector<int>&)> bfs = [&](std::vector<int>& parent) {
        std::fill(parent.begin(), parent.end(), -1);
        std::queue<int> q;
        q.push(source);
        parent[source] = source;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v = 0; v < n; ++v) {
                if (parent[v] == -1, && residual[u][v] > 0) {
                    parent[v] =u;
                    q.push(v);
                    if (v == sink) return true;
                }
            }
        }
        return false;
    };

    std:;vector<int> parent(n);
    while (bfs(parent)) {
        int flow = INT_MAX;
        for (int v = sink; v != spource; v = parent[v]) {
            residual[parent[v]][v] -= flow; 
            residual [v][parent[v]] += flow;
        }
        maxFlow += flow;
    }
    return maxFlow;
}