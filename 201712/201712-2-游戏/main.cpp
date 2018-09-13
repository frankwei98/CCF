#include <bits/stdc++.h>

using namespace std;

//
// Created by Frank Wei on 2018/8/29.
//

//    问题描述
//    　　有n个小朋友围成一圈玩游戏，小朋友从1至n编号，2号小朋友坐在1号小朋友的顺时针方向，3号小朋友坐在2号小朋友的顺时针方向，……，1号小朋友坐在n号小朋友的顺时针方向。
//    　　游戏开始，从1号小朋友开始顺时针报数，接下来每个小朋友的报数是上一个小朋友报的数加1。若一个小朋友报的数为k的倍数或其末位数（即数的个位）为k，则该小朋友被淘汰出局，不再参加以后的报数。当游戏中只剩下一个小朋友时，该小朋友获胜。
//    　　例如，当n=5, k=2时：
//    　　1号小朋友报数1；
//    　　2号小朋友报数2淘汰；
//    　　3号小朋友报数3；
//    　　4号小朋友报数4淘汰；
//    　　5号小朋友报数5；
//    　　1号小朋友报数6淘汰；
//    　　3号小朋友报数7；
//    　　5号小朋友报数8淘汰；
//    　　3号小朋友获胜。
//
//    　　给定n和k，请问最后获胜的小朋友编号为多少？
//    输入格式
//    　　输入一行，包括两个整数n和k，意义如题目所述。
//    输出格式
//    　　输出一行，包含一个整数，表示获胜的小朋友编号。

queue<int> circle;
queue<int> nextRoundQueue;


void clear( std::queue<int> &q )
{
    std::queue<int> empty;
    std::swap( q, empty );
}

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        circle.push(i + 1);
    }
    int number = 1;
    while (!circle.empty()) {
        int kid = circle.front();
        circle.pop(); // see you in the next round!

        bool isLastDigitK = number % 10 == k;
        bool canBeDivideByK = number % k == 0;
        if (isLastDigitK || canBeDivideByK) {
        } else {
            nextRoundQueue.push(kid);
        }

        if (circle.empty()) {
            if (nextRoundQueue.size() == 1) {
                printf("%d", nextRoundQueue.front());
                break;
            }
            swap(circle, nextRoundQueue);
            clear(nextRoundQueue);
        }
        number += 1;

    }
}