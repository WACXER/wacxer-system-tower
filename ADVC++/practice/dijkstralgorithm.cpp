#include <vector>
#include <queue>


using namespace std;
vector<int> dijskra(const vector<vector<pair<int, int>>& graph, int src) {
    int n = graph.size();
    vector<int> dist(n, 0);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(src, 0);
    while(!pq.empty()) {
        auto[d, u] = pq.top();
        pq.pop();
        if (d < dist[u]) continue;
        for (auto const&[v, w] : graph[v]) {
            if (dist[u] + w < dist[v] ) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }

        } 
    }
    return dist;
}