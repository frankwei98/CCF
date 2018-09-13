#include <iostream>
#include <map>

using namespace std;
map<int, int> numbersCount;
int n;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        numbersCount[num] += 1;
    }

    int max = 0;
    int ans;

    for (map<int, int>::iterator it = numbersCount.begin();
         it != numbersCount.end(); it++)
    {
        if (it->second > max)
        {
            ans = it->first;
            max = it->second;
        }
    }
    cout << ans << endl;
}