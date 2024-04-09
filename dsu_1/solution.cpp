#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

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
     ifstream fin("input.txt");
     ofstream fout("output.txt");
     int n, q;
     fin >> n >> q;

     DSU dsu(n);

     vector<vector<int>> roads(2, vector<int>(q + 1));

     roads[0][0] = roads[1][0] = INT_MIN;

     for (int i = 0; i < q; i++) {
         fin >> roads[0][i] >> roads[1][i];
     }

     dsu.size.resize(n + 1, -1);
     dsu.size[0] = INT_MIN;

     int count = n;

     if (q == 0) {
        fout << 0 << endl;
        return 0;
     }

     for (int i = 0; i < q; i++) {
         if (count == 1) {
             fout << count << endl;
             continue;
         }
         if (dsu.size[roads[0][i]] != -1 && dsu.size[roads[1][i]] != -1 && dsu.find(roads[0][i]) == dsu.find(roads[1][i])) {
             fout << count << endl;
         }
         else {
            dsu.unite(roads[0][i], roads[1][i]);
            fout << --count << endl;
            }
        }

    return 0;
}