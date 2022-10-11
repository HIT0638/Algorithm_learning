#include <iostream>
#include <vector>
using namespace std;

//用数组储存数字的每一位数
//使用小端法，方便进位
//然后模拟人工加法进行程序加法

vector<int> add(vector<int> &A, vector<int> &B)
{
    vector<int> C;

    //判断位数大小
    if (A.size() < B.size())
        return add(B, A);

    //用 t 记录每位相加后的值
    int t = 0;

    for (int i = 0 ; i < A.size() ; i ++)
    {   
        t += A[i];
        if (i < B.size())
            t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    //判断最终位是否需要进位
    if (t) C.push_back(1);

    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;

    cin >> a >> b;

    //将 a , b 用vector 容器储存
    for (int i = a.size() - 1 ; i >= 0 ; i --) A.push_back(a[i] - '0');
    for (int i = b.size() - 1 ; i >= 0 ; i --) B.push_back(b[i] - '0');

    //用 C 储存相加后的数值
    auto C = add(A, B);

    for (int i = C.size() - 1; i >= 0 ; i --) cout << C[i] ;

    system("pauese");
    
    return 0;
}   //DONE
