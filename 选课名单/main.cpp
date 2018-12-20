#include<bits/stdc++.h>
using namespace std;

struct node
{
    int num;
    char name[101];
    struct node *next;
}*nam[35001];

int b[35001];
int main(void)
{
    int n, m, i, x, shu;
    char w[35];
    memset(b, 0, sizeof(b));
    scanf("%d %d", &n, &m);
    for(i = 1; i <= m; i++)
    {
        nam[i] = new struct node;
        nam[i]-> next = NULL;
    }
    for(i = 0; i < n; i++)
    {
        scanf("%s %d", w, &x);
        while(x--)
        {
            scanf("%d", &shu);
            b[shu]++;
            struct node *p = nam[shu];
            struct node *q;
            q = (struct node *)malloc(sizeof(struct node));
            strcpy(q-> name, w);
            q-> next = NULL;
            while(p-> next != NULL)
            {
                if(strcmp(q-> name, p-> next-> name) < 0)
                {
                    break;
                }
                p = p-> next;
            }
            q-> next = p-> next;
            p-> next = q;

        }
    }

    for(i = 1; i <= m; i++)
    {
        printf("%d %d\n", i, b[i]);
        struct node *p = nam[i]-> next;
        while(p)
        {
            printf("%s\n", p-> name);
            p = p-> next;
        }
    }
    return 0;
}


