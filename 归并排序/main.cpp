#include<bits/stdc++.h>
using namespace std;

int temp[100001], a[100001];
long long sum = 0;

void mergesort(int a[], int s1, int e1, int s2, int e2)
{
     int p = 0;
     int p1 = s1;
     int p2 = s2;

     while(p1 <= e1 && p2 <= e2)
     {
         if(a[p1] <= a[p2])
         {
             temp[p++] = a[p1++];
         }

         else
         {
             temp[p++] = a[p2++];
             sum += (e1 - p1 + 1);
         }
     }

     while(p1 <= e1)
     {
         temp[p++] = a[p1++];
     }

     while(p2 <= e2)
     {
         temp[p++] = a[p2++];
     }
     int i;

     for(i = s1; i <= e2; i++)
     {
         a[i] = temp[i - s1];
     }
}

void guisort(int a[], int l, int r)
{
    int mid;
    while(l >= r)
    {
        return ;
    }
    if(l < r)
    {
        mid = (l + r) / 2;
        guisort(a, l, mid);
        guisort(a, mid + 1, r);
        mergesort(a, l, mid, mid + 1, r);
    }
}

int main(void)
{
    int n, i;
    sum = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    guisort(a, 0, n - 1);
    printf("%lld\n", sum);
    return 0;
}
