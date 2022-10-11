#include <iostream>
using namespace std;

//二分法求数的三次方根

int main()
{
    double x;
    cin >> x;
    
    double l = -10000, r = 1e5; //划分边界

    //确定精度
    while (r - l > 1e-8)
    {
        double mid = (l + r) / 2.0;

        if (mid * mid * mid >= x)
            r = mid ;
        else 
            l = mid;
    }

    printf("%lf \n", l);

    system("pause");

    return 0;
}