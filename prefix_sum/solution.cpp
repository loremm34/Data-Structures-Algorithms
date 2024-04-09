#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int len; 
vector<long long> a; 
vector<long long> b; 

void add(int i, int x) {
    b[i / len] += x; 
    a[i] += x; 
}

long long find_sum(int l, int r) {
    long long sum = 0; 
    for (int i = l; i < r; ) {
        if (i % len == 0 && i + len <= r) { 
            sum += b[i / len];
            i += len; 
        }
        else { 
            sum += a[i]; 
            i++; 
        }
    }
    return sum;
}

int main() {
    int n; 
    cin >> n;
    a.resize(n); 
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int q; 
    cin >> q;

    len = (int)sqrt(n + .0) + 1;
    b.resize(len); 
    for (int i = 0; i < n; ++i) {
        b[i / len] += a[i]; 
    }

 
    for (int i = 0; i < q; ++i) {
        string type; 
        cin >> type;
        if (type == "Add") { 
            int idx, val; 
            cin >> idx >> val;
            add(idx, val); 
        }
        else if (type == "FindSum") { 
            int l, r; 
            cin >> l >> r;
            cout << find_sum(l, r) << "\n"; 
        }
    }
    return 0;
}