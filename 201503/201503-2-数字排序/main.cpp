#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

map<int, int> numberToCount;
typedef vector<pair<int, int> > mapInVec;
mapInVec v;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second != b.second ? a.second < b.second : a.first > b.first;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        numberToCount[num] += 1;
    }

    copy(numberToCount.begin(), numberToCount.end(), back_inserter(v));
    sort(v.begin(), v.end(), cmp);

    for (mapInVec::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}