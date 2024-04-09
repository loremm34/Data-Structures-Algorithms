#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int n;
int start = 1;
vector<bool> visited;
vector<int> marks;
vector<vector<int>> matrix;

void bfs(int i) {
    queue<int> q;
    q.push(i);
    visited[i] = true;  
    while (!q.empty()) {
        i = q.front();
        q.pop();
        marks[i] = start;
        start++;
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1 && !visited[j]) {  
                q.push(j);
                visited[j] = true;  
            }
        }
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin >> n;
    if (n == 1) {
        fout << 1;
        return 0;
    }

    if (n == 0) {
        fout << 0;
        return 0;
    }

    visited.resize(n, false);  
    marks.resize(n);
    matrix.resize(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {  
            bfs(i);
        }
    }

    for (int i = 0; i < n; i++) {
        fout << marks[i] << " ";
    }

    return 0;
}