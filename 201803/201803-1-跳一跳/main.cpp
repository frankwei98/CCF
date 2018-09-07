#include <iostream>
#include <vector>
using namespace std;

vector<int> numbers;
int point = 0, lastNumber = 1, lastAddedPoint = 0;
// 问题描述
// 　　近来，跳一跳这款小游戏风靡全国，受到不少玩家的喜爱。
// 　　简化后的跳一跳规则如下：玩家每次从当前方块跳到下一个方块，如果没有跳到下一个方块上则游戏结束。
// 　　如果跳到了方块上，但没有跳到方块的中心则获得1分；
//    跳到方块中心时，若上一次的得分为1分或这是本局游戏的第一次跳跃则此次得分为2分，
//    否则此次得分比上一次得分多两分（即连续跳到方块中心时，总得分将+2，+4，+6，+8...）。
// 　　现在给出一个人跳一跳的全过程，请你求出他本局游戏的得分（按照题目描述的规则）。

int main()
{
    // 输入格式
    // 　　输入包含多个数字，用空格分隔，每个数字都是1，2，0之一，
    // 1表示此次跳跃跳到了方块上但是没有跳到中心，2表示此次跳跃跳到了方块上并且跳到了方块中心，0表示此次跳跃没有跳到方块上（此时游戏结束）。
    // 样例输入
    // 1 1 2 2 2 1 1 2 2 0
    for (int i = 0; i < 30; i++)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            break;
        }
        else if (x == 1)
        {
            point += 1;
            lastAddedPoint = 1;
            lastNumber = 1;
        }
        else
        {
            // x == 2 no doki
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
        }
    }

    cout << point << endl;
    return 0;
}