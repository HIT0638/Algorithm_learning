#include<iostream>
using namespace std;

//逆序对的数量

/*
整体思路是将原数组进行归并排序
在归并排序的过程中求解逆序对的数量

具体步骤:
1.将数组一分为二 [L,R] -> [L,Mid],[Mid,R]
2.分别将两边的数组进行递归排序
3.归并，将排序好的数组进行归并，并在归并的同时计算逆序对的数量
*/

typedef long long LL;

const int N = 1e5 + 10;

int n;
int q[N],tmp[N];

LL merge_sort(int l,int r){
    if(l >= r)
        return 0;

    int mid = l + r >> 1;

    //递归排序
    LL res = merge_sort(l ,mid) + merge_sort(mid + 1, r);

    //归并
    int k = 0, i = l, j = mid + 1;

    while(i <= mid && j <= r){
        if (q[i] <= q[j])
            tmp[k ++ ] = q[i ++ ];
        else{
            tmp[k ++ ] = q[j ++ ];
            res += mid - i + 1;
        }
    }

    //扫尾
    while (i <= mid) tmp[k ++ ] = q[i ++ ];
    while (j <= r) tmp[k ++ ] = q[j ++ ];

    //物归原主
    for (int i = l, j = 0;i <= r;i ++, j ++)
        q[i] = tmp[j];
        
    return res;
}

int main(){
    
    cin >> n;
    for (int i = 0;i < n ;i ++)
        scanf("%d", &q[i]);

    LL res = merge_sort(0 ,n - 1);

    cout << res << endl;

    system("pause");
    return 0;
}