#include <iostream>

using namespace std;

bool isOneMoreDay(int year)
{
    return (year % 4 == 0) && (year % 100 != 0);
}

int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    int y, d, m, md;
    cin >> y;
    cin >> d;
    m = 1;
    md = d;
    while (md > months[m])
    {
        md -= months[m];
        // lunar year handle
        if (isOneMoreDay(y) && m == 2) {
            md -= 1;
        }
        m += 1;
    }

    cout << m << endl;
    cout << md << endl;
}
