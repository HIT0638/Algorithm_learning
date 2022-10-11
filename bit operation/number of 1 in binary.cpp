#include <iostream>
using namespace std;

// x & 1 相当于
//判断二进制下 x 的最末位是 0 还是 1 
//从而判断 X 的奇偶

//因为相当于每一位与 1 的各位作 '与' 
//而 1 是 0000...0001
//除了最末位能判断 ，其他位均只能为 0

//可同理判断 lowbit 中取到最后一位 1 的原理

int lowbit(int x)
{
    //& 是 c++ 中的位运算符
    return x & -x;

    //x & -x 相当于 X & (~x + 1)
}

int main()
{   
    //输入多少个数
    int n;
    cin >> n;

    while( n -- )
    {
        int x;
        cin >> x;

        int res = 0;
        while(x) x -= lowbit(x) , res ++; //每次减去x二进制形式的最后一位1 ，直到没有

        cout << res << ' '; 
    }

    system("pause");
    return 0;
}