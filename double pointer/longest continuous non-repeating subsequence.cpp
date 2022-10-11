#include <iostream>
using namespace std;

const int N = 100010;
/* 
双指针算法的优势
 能将诸如
    for (int i = 0 ; i < n ; i ++)
        for (int j = 0 ; j < n ; i ++)
 的 O(n^2) 的复杂度简化为 O(n) 的复杂度
 */

int n;
// s[k] 数组记录目前 [ j , i ] 范围内数字 k 出现的个数
// 用来判断是否出现重复数字
int a[N] ,s[N];


int main()
{   
    cin >> n;
    for (int i = 0 ; i < n ; i ++ )
        cin >> a[i];
    
    // res 指目前最长连续不重复子序列长度
    int res = 0;

    for (int i = 0, j = 0 ; i < n ; i ++ )
    {
        s[a[i]] ++;
        //判断如果出现重复数字, 则更改子序列起点 j 
        //直到找到新的起点
        while (s[a[i]] > 1)
        {
            s[a[j]] --;
            j ++;
        }

        res = max(res , i - j + 1);
    }

    cout << res << endl;

    system("pause");
    return 0;
}