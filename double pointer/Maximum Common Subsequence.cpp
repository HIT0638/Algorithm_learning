#include <iostream>
#include <vector>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];

// 求出最大公共子序列
void ag_01()
{   
    vector<int> c;

    cin >> n >> m;
    for (int i = 0; i < n; i ++ )
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i ++ )
        scanf("%d", &b[i]);

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {
            c.push_back(a[i]);
            i ++;
        }
        else if (a[i] < b[j])
        {
            i ++;
        }

        j ++;
    }

    for (int k = 0; k < c.size(); k ++ )
        cout << c[k] << ' ';
}

int main()
{
    ag_01();

    system("pause");
    return 0;
}