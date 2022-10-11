#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n,m;
int q[N];

int main(){
     scanf("%d %d",&n ,&m);
     for (int i = 0;i < n;i ++){
        scanf("%d" ,&q[i] );
     }

    while(m --){
        int x;
        scanf("%d" ,&x );

        int l = 0, r = n - 1;
        while(l < r){
            int mid = l + r >> 1;
            if (q[mid] >= x) r = mid;
            else 
                l = mid + 1;
        }

        if (q[l] != x) cout << "-1 -1" << endl;
        else{
            cout << l << ' ';
            int l = 0, r = n - 1;
            while(l < r){
                int mid = l + r + 1 >> 1;
                if (q[mid] <= x) l = mid;
                else 
                    r = mid - 1;
            }

            cout << r << endl;
        }
    }

    system("pause");
    return 0;
}



//两个二分模板
    //1. mid 无 + 1, 取左边界
int bsearch(int l, int r,int x){
    int l = 0, r = n - 1;

    while (l < r){
        int mid = l + r >> 1;

        if (q[mid] >= x) r = mid;
        else l = mid + 1;
    }

    if (q[l] != x) cout<< "-1 -1";
    else
        cout << l << endl;

    return r;
}

    //2. mid 有 + 1, 取右边界, + 1 是为了防止死循环
int bsearch(int l, int r ,int x){
    int l = 0,r = n - 1;

    while (l < r){
        int mid = l + r + 1 >> 1;

        if (q[mid] <= x) l = mid;
        else
            r = mid - 1;
    }

    if (q[r] != x) cout << "-1 -1";
    else    
        cout << r << endl;

    return r;
}