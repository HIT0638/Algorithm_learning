#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n;
int q[N], tmp[N];  //q[]为原数组， tmp为临时储存数组

void merge_sort(int q[], int l, int r){
    if(l >= r)
        return ;
    
    int mid = l + r >> 1;   //>> 1 代表二进制向右移动一位，意味着除2取整

    merge_sort(q, l, mid);  merge_sort(q, mid + 1, r);  //分别对两边进行递归排序

    //以下进行归并
    int k = 0, i = l, j = mid + 1;  //选中两边起始数字

    //对两边数据进行比较、排序和储存
    while(i <= mid && j <= r){
        if(q[i] <= q[j])
            tmp[k ++ ] = q[i ++ ];
        else 
            tmp[k ++ ] = q[j ++ ];
    }

    //对某一边剩下数据进行放入
    while(i <= mid)
        tmp[k ++ ] = q[i ++ ];
    while(j <= r)
        tmp[k ++ ] = q[j ++ ];

    //将排序好的数组替换回去
    for(int i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i ++)
        scanf("%d", &q[i]);

    merge_sort(q, 0, n - 1);

    for (int i = 0; i < n; i ++)    
        printf("%d", q[i]);

    system("pause");
    
    return 0;
}


/*
1.确定分界点
2.分别递归排序左右两边
    *
         
    *
3.归并，将左右两个有序序列合二为一
*/