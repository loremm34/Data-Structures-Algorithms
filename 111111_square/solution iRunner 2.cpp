#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    

    ifstream fin("in.txt");
    ofstream fout("out.txt");
    fin >> n >> m;

    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fin >> dp[i][j];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (dp[i][j] == 1) {
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }
    }

    int max = 0;
    int iPos = 0;
    int jPos = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] > max) {
                max = dp[i][j];
                iPos = i;
                jPos = j;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] == max && j < jPos) {
                iPos = i;
                jPos = j;
            }
            else if (dp[i][j] == max && jPos == j && i < iPos) {
                iPos = i;
                jPos = j;
            }
        }
    }

    fout << max << endl;
    fout << jPos - max + 2 << endl;
    fout << iPos - max + 2;
    
}