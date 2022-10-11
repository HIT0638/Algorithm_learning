#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n, k;
int q[N];

int quick_choose(int l, int r, int k){
    if (l == r)
        return q[l];

    int x = q[l], i = l - 1, j = r + 1;

    while(i < j){
        do i ++; while(q[i] < x);
        do j --; while(q[j] > x);
        if (i < j) 
            swap(q[i], q[j]);
    }

    int sl = j - l + 1;     //判断位置，简化程序

    if (k <= sl) return quick_choose(l , j , k);

    return quick_choose(j + 1, r, k - sl);
}
int main(){
    cin >> n >> k;
    for (int i = 0; i < n; i ++ )
        scanf("%d", &q[i]);

    cout << quick_choose(0, n - 1, k) << endl;

    system("pause");
    return 0;
}