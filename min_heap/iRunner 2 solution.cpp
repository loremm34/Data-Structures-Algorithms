#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool isHeap(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (2 * i + 1 < n && a[2 * i + 1] < a[i]) {
            return false;
        }
        if (2 * i + 2 < n && a[2 * i + 2] < a[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    fin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }

    if (isHeap(a)) {
        fout << "Yes" << endl;
    }
    else {
        fout << "No" << endl;
    }

    return 0;
}