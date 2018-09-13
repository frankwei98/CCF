#include <bits/stdc++.h>

// Copied from CLIon
using namespace std;


int main() {
    int n, middleNumber = -1;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    auto middlePos = int(arr.size() / 2);
    bool isSize2x = arr.size() % 2 == 0;
    int i = (isSize2x) ? middlePos - 1 : middlePos;
    int theMiddleElement = arr[middlePos];
    while (i >= 0 && middlePos < n && arr[i] == arr[middlePos] && arr[i] == theMiddleElement) {
        --i, ++middlePos;
    }
    if (!(i >= 0 && (arr[i] == theMiddleElement || arr[middlePos] == theMiddleElement))) {
        middleNumber = theMiddleElement;
    }
    cout << middleNumber << endl;
    return 0;

}