#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 12345678
ll n;
ll a[100005],sp[100001][50];
void memSet()
{
    for(ll i=0; i<=n+1; i++)
    {
        for(ll j=0; j<=log2(n)+1; j++)
        {
            sp[i][j]=1234567;
        }
    }
}
int main()
{
    ll i,j,k,l,m,tc,t=1;
    scanf("%lld",&tc);
    while(tc--)
    {
        scanf("%lld%lld",&n,&m);
        memSet();
        for(i=1; i<=n; i++)
        {
            scanf("%lld",&a[i]);
            sp[i][0]=a[i];
        }
        for(i=1; i<=log2(n); i++)
        {
            k=pow(2,i-1);
            for(j=1; j<=n; j++)
            {
                if(k+j>=n)
                {
                    sp[j][i]=min(sp[j][i-1],sp[n][i-1]);
                    continue;
                }
                sp[j][i]=min(sp[j][i-1],sp[j+k][i-1]);
            }
        }
        printf("Case %lld:\n",t++);
        for(i=0; i<m; i++)
        {
            ll x,y;
            scanf("%lld%lld",&x,&y);
            ll d1=y;
            ll d=y-x+1;
            y=log2(d);
            d=d1-pow(2,y)+1;
            ll mnm=min(sp[x][y],sp[d][y]);
            printf("%lld\n",mnm);
        }
    }
    return 0;
}
