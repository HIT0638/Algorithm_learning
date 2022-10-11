// 利用分治的思想

#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

void quick_sort(int q[], int l, int r){
    if (l >= r) 
        return;  //当完成排序时程序结束

    int x = q[(l + r) / 2]; int i = l - 1; int j = r + 1;  //选好标兵， 以及左右起始点

    while(i < j){
        do i++; while(q[i] < x);    //从左至右遇到第一个大于等于标兵的数时停止
        do j--; while(q[j] > x);    //从右至左遇到第一个小于等于标兵的数时停止
        if (i < j) swap(q[i], q[j]);    //交换两个数的位置
    }

    quick_sort(q, l , j);   //继续分治
    quick_sort(q, j + 1, r);    //继续分治
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++)
         printf("%d ", q[i]);

    system("pause");
    return 0;
}