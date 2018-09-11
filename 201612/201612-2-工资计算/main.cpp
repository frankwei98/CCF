#include <iostream>
#include <map>

using namespace std;

// 够粗暴的解决方案
// Before[x] ==> Taxed[i] 的映射关系
int BeforeTax[] = {0, 3500, 5000, 8000, 12500, 38500, 58500, 83500, 999999};
int Taxed[] = {0, 3500, 4955, 7655, 11255, 30755, 44755, 61005, 999999};
float f[] = {1, 0.97, 0.9, 0.8, 0.75, 0.7, 0.65, 0.55, 0};

int main()
{
    int afterTaxed, i, result;
    cin >> afterTaxed;
    for (i = 0; i < 9; i++)
    {
        bool isEnoughToCut = Taxed[i] <= afterTaxed;
        if (!isEnoughToCut)
        {
            break;
        }
    }
    float withoutTax = (afterTaxed - Taxed[i - 1]) / f[i - 1];
    result = BeforeTax[i - 1] + withoutTax;
    cout << result << endl;
    return 0;
}