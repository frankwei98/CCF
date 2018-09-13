#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int numbers[1001];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        // 不分数字为正负数，以 num 的绝对值作为数组下标
        numbers[abs(num)] += 1;
    }

    int counter = 0;
    for (int i = 0; i < 1001; i++)
    {
        // 简单粗暴 出现两次就为一对
        if (numbers[i] == 2)
        {
            counter += 1;
        }
    }

    cout << counter << endl;

    return 0;
}