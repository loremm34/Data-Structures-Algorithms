#include <fstream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const long long maxNumber = numeric_limits<long long>::max();

long long dijkstra(int  start, int point, const vector<vector<pair<long long, long long>>>& graph) {
    vector<long long> distance(graph.size(), maxNumber);
    distance[start] = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        long long w = pq.top().first;
        long long u = pq.top().second;
        pq.pop();


        if (u == point) break;
        if (w > distance[u]) continue;

        for (const auto& edge : graph[u]) {
            long long v = edge.first;
            long long weight = edge.second;

            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push(make_pair(distance[v], v));
            }
        }
    }

    return distance[point];
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m;
    fin >> n >> m;

    vector<vector<pair<long long, long long>>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        fin >> u >> v >> w;

        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    fout << dijkstra(1, n, graph);

    return 0;
}