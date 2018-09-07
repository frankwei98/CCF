#include <iostream>

using namespace std;

int matrix[1024][1024];

int main() {
    int n,m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            cout << matrix[j][i];
            if (j != n-1) {
                cout << (" ");
            }
        }
        cout << endl;
    }

    return 0;
}

