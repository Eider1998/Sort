#include<bits/stdc++.h>
using namespace std;

int a[10001];

void Shell_sort(int a[], int n)
{
    int i, j, dk, k, tmp;

    k = 2;
    dk = n / 2;
    while(dk >= 1)
    {
        for(i = dk; i < n; i++)
        {
            tmp = a[i];
            j = i - dk;
            while(j >= 0 && a[j] > tmp)
            {
                a[j + dk] = a[j];
                j -= dk;
            }

            a[j + dk] = tmp;
        }
        k++;
        k *= k;

        if(dk == n / 2 || dk == 1)
        {
            for(i = 0; i < n; i++)
            {
                printf("%d%c", a[i], i == n - 1?'\n':' ');
            }
        }
        dk = n / k;
    }
}

int main(void)
{
    int i, n;

    while(~scanf("%d", &n))
    {
        for(i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }

        Shell_sort(a, n);
    }

    return 0;
}
