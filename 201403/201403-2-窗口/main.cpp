#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Window {
    int n, x1, y1, x2, y2;
    Window() {}
    Window(int n, int x1, int y1, int x2, int y2)
    {
        this->n = n;
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
};

struct MouseClick
{
    int x, y;
    MouseClick(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

stack<Window> windows;
vector<MouseClick> mouseClicks;

void clickAWindow(int windowsNumber)
{
    stack<Window> newWindowsList;
    Window target;
    while (!windows.empty())
    {
        Window w = windows.top();
        if (w.n == windowsNumber)
        {
            target = w;
        }
        else
        {
            newWindowsList.push(w);
        }
        windows.pop();
    }
    while (!newWindowsList.empty()) {
        Window _w = newWindowsList.top();
        newWindowsList.pop();
        windows.push(_w);
    }
    windows.push(target);
}

int searchWindowByAxis(MouseClick m)
{
    stack<Window> iterQ = windows;
    int wNum = -1;
    bool isFound = false;
    while (!iterQ.empty())
    {
        Window w = iterQ.top();
        if (w.x1 <= m.x && w.x2 >= m.x && w.y1 <= m.y && w.y2 >= m.y)
        {
            return w.n;
        }
        else
        {
            iterQ.pop();
        }
    }
    return isFound ? wNum : -1;
}

int main()
{
    int N, M;
    cin >> N >> M;
    // 接下来 N 行按照从最下层到最顶层的顺序给出 N 个窗口的位置。 每行包含四个非负整数 x1, y1, x2, y2,表示该窗口的一对顶点坐标分别为 (x1, y1) 和 (x2, y2)。保证 x1 < x2,y1 2。
    int x1, y1, x2, y2;

    for (int i = 1; i <= N; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        Window w(i, x1, y1, x2, y2);
        windows.push(w);
    }
    int x, y;
    // 接下来 M 行每行包含两个非负整数 x, y,表示一次鼠标点击的坐标。
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        MouseClick c(x,y);
        mouseClicks.push_back(c);
    }

    for (int i = 0; i < M; i++)
    {
        MouseClick c = mouseClicks[i];
        int w = searchWindowByAxis(c);
        if (w == -1) {
            cout << "IGNORED" << endl;
        } else {
            clickAWindow(w);
            cout << w << endl;
        }
    }

    return 0;
}