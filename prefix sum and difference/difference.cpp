#include <iostream>
using namespace std;

//差分
//前缀和的逆运算

//a 数组是 b 的前缀和
//b 数组是 a 的差分

const int N = 100010;

int n , m;
int a[N] , b[N];

void insert(int l, int r , int c)
{
    b[l] += c;
    b[r + 1] -= c;
}

int main()
{
    scanf("%d%d" , &n, &m);

    for (int i = 1 ; i <= n ; i ++)
        scanf("%d", &a[i]);

    for (int i = 1 ; i <= n ; i ++)
        insert(i , i , a[i]);

    while(m --)
    {
        int l , r , c;
        scanf("%d%d%d" , &l ,&r ,&c);

        insert(l , r, c);
    }

    for (int i = 1 ; i <= n ; i ++)
        b[i] += b[i - 1];

    for (int i = 1 ; i <= n ; i ++)
        printf("%d " , b[i]);

    system("pause");
    return 0;
}