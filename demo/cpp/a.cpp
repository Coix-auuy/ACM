#include <iostream>  //输入输出流
#include <algorithm> //一些常用算法 min（）max（）
using namespace std;
const int maxn = 100 + 10; // 常数
int A[maxn];
int main()
{
    long long a, b;
    while (cin >> a >> b)
    {
        cout << min(a, b) << "\n";
    }
    return 0;
}
