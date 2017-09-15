#include<bits/stdc++.h>
#include<string>
using namespace std;
#define ll long long
const int N = 1e5 + 100;
ll l[N],n,c,l1;
vector<int>v[10001];
ll sp[10001][101];
ll cost[10001];
void dfs(ll a, ll p)
{
    sp[a][0]=p;
    l[a]=l[p]+1;
    ll sz=v[a].size(),b;
    for(ll i=0; i<sz; i+=2)
    {
        b=v[a][i];
        if(b!=p)
        {
            cost[b]=v[a][i+1]+cost[a];
            dfs(b,a);
        }
    }
}
void sperse_table()
{
    ll i,j;
    for(j=1; j<=l1; j++)
    {
        for(i=2; i<=n; i++)
        {
            if(sp[i][j-1]!=-1)
            {
                sp[i][j]=sp[sp[i][j-1]][j-1];
            }
        }
    }
}
ll ansestor(ll a, ll b)
{
    ll p,i;
    if(l[a]<l[b])
    {
        swap(a,b);
    }
    for(i=l1; i>=0; i--)
    {
        if(l[sp[a][i]]>=l[b])
        {
            a=sp[a][i];
        }
    }
    if(a==b)
    {
        return a;
    }
    for(i=l1; i>=0; i--)
    {
        if(sp[a][i]!=sp[b][i]&&sp[a][i]!=-1)
        {
            a=sp[a][i];
            b=sp[b][i];
        }
    }
    return sp[a][0];
}
int main()
{
    ll tc,i,j,a,b,c,k;
    char s[10];
    scanf("%lld",&tc);
    while(tc--)
    {
        memset(sp,-1,sizeof(sp));
        memset(cost,0,sizeof(cost));
        memset(l,0,sizeof(l));
        scanf("%lld",&n);
        for(i=1; i<n; i++)
        {
            scanf("%lld%lld%lld",&a,&b,&c);
            v[a].push_back(b);
            v[a].push_back(c);
            v[b].push_back(a);
            v[b].push_back(c);
        }
        l1=log2(n);
        dfs(1,-1);

        sperse_table();

        while(scanf("%s",s))
        {
            getchar();
            if(s[1]=='O')
            {
                break;
            }
            if(s[1]=='I')
            {
                scanf("%lld%lld",&a,&b);
                ll r=ansestor(a,b);
                ll cst=cost[a]+cost[b]-2*cost[r];
                printf("%lld\n",cst);
            }
            else
            {
                scanf("%lld%lld%lld",&a,&b,&k);
                ll l2,d,p;
                ll r=ansestor(a,b);
                if(l[a]-l[r]==0)
                {
                    d=l[b]-l[r]+1;
                    d=d-k;
                    for(int i=l1; i>=0; i--)
                    {
                        if(d&(1<<i))
                        {
                            b=sp[b][i];
                        }
                    }
                    printf("%lld\n",b);
                }
                else if(l[b]-l[r]==0)
                {
                    k--;
                    for(int i=l1; i>=0; i--)
                    {
                        if(k&(1<<i))
                        {
                            a=sp[a][i];
                        }
                    }
                    printf("%lld\n",a);
                }
                else
                {
                    d=l[a]-l[r]+1;
                    if(k<=d)
                    {
                        k--;
                        for(int i=l1; i>=0; i--)
                        {
                            if(k&(1<<i))
                            {
                                a=sp[a][i];
                            }
                        }
                        printf("%lld\n",a);
                    }
                    else
                    {
                        k-=d;
                        k=l[b]-k-1;
                        for(int i=l1; i>=0; i--)
                        {
                            if(k&(1<<i))
                            {
                                b=sp[b][i];

                            }
                        }
                        printf("%lld\n",b);
                    }
                }
            }
        }
        printf("\n");
        for(i=1; i<=n; i++)
        {
            v[i].clear();
        }
    }
    return 0;
}

/*
2
15
1 2 2
1 3 3
2 4 4
2 5 5
3 6 6
3 7 7
5 8 8
5 9 9
6 10 10
6 11 11
9 12 12
9 13 13
11 14 14
11 15 15
DIST 1 15
35
KTH 1 15 3
6
DIST 12 15
63
*/
