#include <iostream>
#include <vector>

using namespace std;

struct Teacher
{
    int w, s, c, e;
    Teacher(int w, int s, int c)
    {
        this->w = w;
        this->s = s;
        this->c = c;
        this->e = s + c;
    }
};

vector<Teacher> teachers;
vector<int> keys;
int N, K;


void returnKey(int time, vector<Teacher> arrt1, int arr[], vector<int> key)
{
    //清空放置要归还钥匙的集合
    key.clear();
    //判断这个时间是否有需要归还钥匙的老师
    for (int i = 0; i < arrt1.size(); i++)
    {
        if (arrt1[i].e == time)
        {
            key.push_back(arrt1[i].w);
        }
    }
    if (key.empty())
    {
        //没有钥匙则不归还
        return;
    }
    else
    {
        //将要归还的钥匙从大到小排序
        for (int i = 0; i < key.size() - 1; i++)
        {
            for (int j = 0; j < key.size() - 1 - i; j++)
            {
                if (key[j] > key[j + 1])
                {
                    int temp = key[(j)];
                    key[j] = key[j + 1];
                    key[j + 1] = temp;
                }
            }
        }
        //归还钥匙
        for (int i = 0, j = 0; i < N; i++)
        {
            if (arr[i] == 0)
            {
                arr[i] = key[j];
                if (key.size() - 1 == j)
                {
                    break;
                }
                else
                {
                    j++;
                }
            }
        }
    }
}

void borrowKey(int time, vector<Teacher> arrt1, int arr[])
{
    for (int i = 0; i < arrt1.size(); i++)
    {
        //判断在当前时间能够使用钥匙的老师
        if (time == arrt1[i].s)
        {
            //取走钥匙
            for (int j = 0; j < N; j++)
            {
                if (arrt1[i].w == arr[j])
                {
                    arr[j] = 0;
                    break;
                }
            }
        }
    }
}

int maxTime(vector<Teacher> arrt1)
{
    int temp = 0;
    for (int i = 0; i < arrt1.size(); i++)
    {
        if (arrt1[i].e > temp)
        {
            temp = arrt1[i].e;
        }
    }
    return temp;
}


int main(int argc, char const *argv[])
{
    // 输入格式
    // 　　输入的第一行包含两个整数N, K。
    cin >> N >> K;
    int time = 1;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = i + 1;
    }
    // 　　接下来K行，每行三个整数w, s, c，
    // 分别表示一位老师要使用的钥匙编号、开始上课的时间和上课的时长。
    // 可能有多位老师使用同一把钥匙，但是老师使用钥匙的时间不会重叠。
    for (int i = 0; i < K; i++)
    {
        int w, s, c;
        cin >> w >> s >> c;
        teachers.push_back(Teacher(w, s, c));
    }

    //结束条件是当前时间大于最后一个老师上完课的时间
    while (time <= maxTime(teachers))
    {
        returnKey(time, teachers, arr, keys);
        borrowKey(time, teachers, arr);
        time++;
    }
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 　　保证输入数据满足输入格式，你不用检查数据合法性。
    // 输出格式
    // 　　输出一行，包含N个整数，相邻整数间用一个空格分隔，依次表示每个挂钩上挂的钥匙编号。
    // 样例输入
    // 5 2
    // 4 3 3
    // 2 2 7
    // 样例输出
    // 1 4 3 2 5
    // 样例说明
    // 　　第一位老师从时刻3开始使用4号教室的钥匙，使用3单位时间，所以在时刻6还钥匙。第二位老师从时刻2开始使用钥匙，使用7单位时间，所以在时刻9还钥匙。
    // 　　每个关键时刻后的钥匙状态如下（X表示空）：
    // 　　时刻2后为1X345；
    // 　　时刻3后为1X3X5；
    // 　　时刻6后为143X5；
    // 　　时刻9后为14325。
    return 0;
}
