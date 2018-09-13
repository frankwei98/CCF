#include <iostream>

using namespace std;

enum Trend {
    UP = 1,
    PLAIN = 0,
    DOWN = -1
};

int arr[1001];

Trend getTrend(int diff) {
    return diff > 0 ? UP : DOWN;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int counter = 0;
    Trend currentTrend = PLAIN;
    for (int i = 1; i < n; ++i) {
        int diffWithYesterday = arr[i] - arr[i - 1];
        Trend nowTrend = getTrend(diffWithYesterday);
        if (nowTrend != currentTrend && currentTrend != PLAIN) {
            counter++;
        }
        currentTrend = nowTrend;
    }

    cout << counter << endl;

    return 0;
}

