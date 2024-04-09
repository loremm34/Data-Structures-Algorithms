#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> roads(m);
    for (int i = 0; i < m; i++) {
        cin >> roads[i].first >> roads[i].second;
    }

    DSU dsu(n);
    vector<int> ans(m, -1);

    for (int i = m - 1; i >= 0; i--) {
        int u = roads[i].first;
        int v = roads[i].second;

        if (dsu.find(u) != dsu.find(v)) {
            ans[i] = i + 1;
            dsu.unite(u, v);
        }
    }

    for (int i = 0; i < m; i++) {
        if (ans[i] != -1) {
            cout << ans[i] << endl;
            break;
        }
    }

    return 0;
}