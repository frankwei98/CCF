#include <iostream>
#include <algorithm>

using namespace std;

void runLocateStr(string str, string key, int op)
{
    string locstr = str;
    if (op == 0)
    {
        // 如 op 为0，则全部转化为小写来匹配
        transform(str.begin(), str.end(), locstr.begin(), ::tolower);
        transform(key.begin(), key.end(), key.begin(), ::tolower);
    }

    // 如果没到字符串末端则匹配成功
    if (locstr.find(key) != string::npos)
    {
        cout << str << endl;
    }
}

int main(void)
{
    string key, str;
    int op, N;
    cin >> key;
    cin >> op;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> str;
        runLocateStr(str, key, op);
    }

    return 0;
}