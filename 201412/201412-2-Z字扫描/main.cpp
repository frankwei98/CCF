#include <iostream>

using namespace std;

enum Directions
{
    RIGHT = 1,
    DOWN = 2,
    RIGHTUP = 3,
    LEFTDOWN = 4,
};

int matrix[501][501];

int main()
{
    int sizeOfMatrix;
    cin >> sizeOfMatrix;
    int n = sizeOfMatrix;

    for (int i = 0; i < sizeOfMatrix; i++)
    {
        for (int j = 0; j < sizeOfMatrix; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int row = 0;
    int col = 0;
    int direction = RIGHT;

    while (row != n - 1 || col != n - 1)
    {
        cout << matrix[row][col] << " ";
        switch (direction)
        {
        case RIGHT:
            col++;
            if (row == 0)
                direction = LEFTDOWN;
            else
                direction = RIGHTUP;
            break;
        case RIGHTUP:
            row--;
            col++;
            if (row == 0 && col != n - 1)
                direction = RIGHT;
            else if (col == n - 1)
                direction = DOWN;
            else
                direction = RIGHTUP;
            break;
        case DOWN:
            row++;
            if (col == 0)
                direction = RIGHTUP;
            else
                direction = LEFTDOWN;
            break;
        case LEFTDOWN:
            row++;
            col--;
            if (col == 0 && row != n - 1)
                direction = DOWN;
            else if (row == n - 1)
                direction = RIGHT;
            else
                direction = LEFTDOWN;
            break;
        }
    }
    cout << matrix[n - 1][n - 1] << endl;

    return 0;
}