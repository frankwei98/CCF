#include <iostream>
#include <string>
#include <queue>
using namespace std;
int n, m;
int map[31][31], sign[31][31];
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    int cnt = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            while (map[i][j] == map[i][1 + j])
            {
                j++;
                if (j == m)
                    break;
                cnt++;
                if (cnt >= 3)
                    for (int k = j - cnt + 1; k <= j; k++)
                        sign[i][k] = 1;
            }
            cnt = 1;
        }
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
        {
            while (map[i][j] == map[i + 1][j])
            {
                i++;
                if (i == n)
                    break;
                cnt++;
                if (cnt >= 3)
                    for (int k = i - cnt + 1; k <= i; k++)
                        sign[k][j] = 1;
            }
            cnt = 1;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (sign[i][j])
                map[i][j] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << map[i][j] << " ";
        cout << endl;
    }
    return 0;
}
