#include <iostream>
#include <map>

using namespace std;
int ball[2][100 + 10];
int out[100 + 10];

class ball
{
  public:
  int pos, ballNumber;
    ball(int p, int bn)
    {
        pos = p;
        ballNumber = bn;
    }
};

int main()
{
    int n, L, t, _pos;
    map<int, int> posmap;

    cin >> n >> L >> t;
    //建立输入输出映射关系
    for (int i = 0; i < n; i++)
    {
        cin >> _pos;
        posmap[_pos] = i;
    }

    int i = 0;
    for (map<int, int>::iterator it = posmap.begin();
         it != posmap.end();
         it++, i++)
    {
        ball[0][i] = it->first;
        ball[1][i] = 1;
    }

    while (t--)
    {
        for (int j = 0; j < n; j++)
        {
            ball[0][j] += ball[1][j];
        }
        for (int j = 0; j < n; j++)
        {
            //左边球碰撞情况
            if (ball[0][j] == 0)
            {
                //ball[0][j] = 0;
                ball[1][j] = 1;
                //右边秋碰撞情况
            }
            else if (ball[0][j] == L)
            {
                //ball[0][j] = n-1;
                ball[1][j] = -1;
                //中间球与下一个球是否碰撞
            }
            else
            {
                if (j < n - 1 && ball[0][j] == ball[0][j + 1])
                {
                    ball[1][j] = -ball[1][j];
                    ball[1][j + 1] = -ball[1][j + 1];
                    j++;
                }
            }
        }
    }

    i = 0;
    for (map<int, int>::iterator it = posmap.begin();
         it != posmap.end(); it++, i++)
    {
        // it->second is the map's element value
        out[it->second] = ball[0][i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << out[i] << " ";
    }

    return 0;
}