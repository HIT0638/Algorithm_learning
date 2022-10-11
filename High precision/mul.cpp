#include <iostream>
#include <vector>
using namespace std;

//高精度乘法
//高精度核心思想不变
//与人工计算不同的是
//将需要将一个乘数当成整体，另一个乘数逐位相乘

vector<int> mul(vector<int> &A , int b)
{
    vector<int> C;

    int t = 0; //记录进位
    for (int i = 0 ; i < A.size() || t; i ++)
    {
        if (i < A.size()) 
            t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }

    while (C.size() > 1 && C.back() == 0)
        C.pop_back();


    return C;
}


int main()
{
    string a;
    int b;

    cin >> a >> b;

    vector<int> A;

    for (int i = a.size() - 1 ; i >= 0 ;i --) 
        A.push_back(a[i] - '0');

    auto C = mul(A, b);

    for (int i = C.size() - 1 ; i >= 0 ; i --)
        cout << C[i];

    system("pause");
    return 0;
}