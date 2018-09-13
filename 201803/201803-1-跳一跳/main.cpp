#include <iostream>
using namespace std;

int point = 0, lastNumber = 1, lastAddedPoint = 0;


int main()
{
    for (int i = 0; i < 30; i++)
    {
        int x;
        cin >> x;
        if (x == 0) {
            break;
        }
        switch (x)
        {
            case 2:
            {
                if (lastNumber == 2)
                {
                    lastAddedPoint += 2;
                }
                else
                {
                    lastAddedPoint = 2;
                }
                point += (lastAddedPoint);
                lastNumber = 2;
                break;
            };
            case 1:
            {
                point += 1;
                lastAddedPoint = 1;
                lastNumber = 1;
                break;
            };
            default: {
            }
        }
    }

    cout << point << endl;
    return 0;
}