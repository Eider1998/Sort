#include<bits/stdc++.h>
using namespace std;

int a[1000001];
void HeapAdjust(int a[], int i, int m)
{
    int t, q;
    t = i;
    while(2 * i <= m)
    {
        if(a[i] < a[2 * i])
        {
            t = 2 * i;
        }

        if(a[t] < a[2 * i + 1] && 2 * i + 1 <= m)
        {
            t = 2 * i + 1;
        }

        if(t == i)
        {
            break;
        }

        if(t != i)
        {
            q = a[t];
            a[t] = a[i];
            a[i] = q;
            i = t;
        }

    }
}

void Heapsort(int a[], int i, int m)
{
    int t;
    while(m >= 1)
    {
        t = a[1];
        a[1] = a[m];
        a[m] = t;
        m--;
        HeapAdjust(a, 1, m);
    }
}

int main(void)
{
    int n, m, i, x;

    scanf("%d %d", &n, &m);
    for(i = 1; i <= m; i++)
    {
        scanf("%d", &a[i]);
    }

    for(i = m / 2; i <= m; i++)
    {
        HeapAdjust(a, i, m);
    }
    Heapsort(a, 1, m);
    for(i = m + 1; i <= n; i++)
    {
        scanf("%d", &x);
        if(x > a[1])
        {
            a[1] = x;
            HeapAdjust(a, 1, m);
            Heapsort(a, 1, m);
        }
    }

    for(i = m; i >= 1; i--)
    {
        printf("%d%c", a[i], i == 1 ?'\n':' ');
    }

    return 0;
}
