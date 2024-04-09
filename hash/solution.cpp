#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int m, c, n;

int collision(int x, int i) {
    return ((x % m) + (c * i)) % m;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin >> m >> c >> n;

    vector<int> cells(m, -1);

    int i;
    int number = 0;
    for (int k = 0; k < n; k++) {
        fin >> number;
        i = 0;
        for (int j = 0; j < m; j++) {
            if (cells[collision(number, i)] == -1 || cells[collision(number, i)] == number) {
                cells[collision(number, i)] = number;
                break;
            }
            i++;
        }
    }

    for (int z = 0; z < m; z++) {
        fout << cells[z] << " ";
    }

    return 0;
}