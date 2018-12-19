#include<bits/stdc++.h>
using namespace std;

int a[5000001];

int main(void)
{
    int n, i, x;

    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if(x < 100)
        {
            a[x]++;
        }

        else
        {
            a[100]++;
        }
    }

    for(i = 0; i <= 100; i++)
    {
        if(a[i])
        {
            printf("%d %d\n", i, a[i]);
        }
    }

    return 0;
}
