#include <iostream>

using namespace std;
int matrix[101][101];

int countColored() {
    int counter = 0;
    for (auto &row : matrix) {
        for (int col : row) {
            if (col == 1) {
                counter++;
            }
        }
    }
    return counter;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int col = x1; col < x2; col++) {
            for (int row = y1; row < y2; row++) {
                matrix[row][col] = 1;
            }
        }
    }
    cout << countColored() << endl;
    return 0;
}

