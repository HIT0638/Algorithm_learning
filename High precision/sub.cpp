#include <iostream>
#include <vector>
using namespace std;

//高精度减法
//两个 正整数 相减

//因为减法有方向性，所以首先判断大小
//判断是否有 A >= B
bool cmp(vector<int> &A, vector<int> &B)
{   
    //首先判断位数是否相同
    if (A.size() != B.size())
        //如果不相同，则判断并返回 
        return A.size() > B.size();
    else 
    {   
        //如果位数相同，则从最高位开始判断并返回
        for (int i = A.size() - 1 ; i >= 0 ; i --)
            if (A[i] != B[i])
                return A[i] > B[i];
    }
    //若两数相同，则也返回true
    return true;
}

vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;

    //用 t 记录各位相减情况 , 并判断是否借位
    for (int i = 0, t = 0 ; i < A.size() ; i ++)
    {
        t = A[i] - t;
        if (i < B.size()) 
            t -= B[i];
        //(t + 10) % t 
        //无论该位是否借位，均可返回正确值
        C.push_back((t + 10) % 10);
        if (t < 0)
            t = 1;
        else 
            t = 0;
    }

    //因为储存方式是从低位到高位
    //因此需要删除前导零
    //避免输出类似 "003" 的情况
    while(C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}

int main()
{
    string a , b;
    vector<int> A, B;

    cin >> a >> b;

    for (int i = a.size() - 1 ; i >= 0 ; i --) A.push_back(a[i] - '0');
    for (int i = b.size() - 1 ; i >= 0 ; i --) B.push_back(b[i] - '0');

    if (cmp(A, B))
    {
        auto C = sub(A , B);
        for (int i = C.size() - 1 ; i >= 0 ; i --) 
            cout << C[i] ;
    }
    else 
    {
        auto C = sub(B , A);
        printf("-");
        for (int i = C.size() - 1 ; i >= 0 ; i --)
            cout << C[i] ;
    }

    system("pause");
    return 0;
}