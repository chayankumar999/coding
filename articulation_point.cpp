#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define pi 2*acos(0.0)
#define pf(a) printf("%lld\n",a)
#define sc(a) scanf("%lld",&a)
#define scn(a,b) scanf("%lld%lld",&a,&b)
#define pf1(t,a) printf("Case %lld: %lld\n",t,a)
#define mem(a) memset(a,0,sizeof (a))
#define mems(a) memset(a,-1,sizeof(a))
vector<ll>v[20005];
ll ans[10005],vis;
ll low[10005],dis[100005],n,m,c,p;
void dfs(ll x,ll p)
{
    ll sz=v[x].size();
    low[x]=dis[x]=++c;
    for(int i=0; i<sz; i++)
    {
        ll adx=v[x][i];
        if(adx==p)
        {
            continue;
        }
        if(adx==1)//for root check
        {
            vis++;
        }
        if(low[adx]==0)
        {
            dfs(adx,x);
            if(dis[x]<=low[adx])
            {
                ans[x]=1;
            }
            low[x]=min(low[x],low[adx]);
        }
        else
        {
            low[x]=min(low[x],dis[adx]);
        }
    }
}
int main()
{
    ll i,j,k,l,x,y,tc,t=1;
    scanf("%lld",&tc);
    while(tc--)
    {
        scanf("%lld%lld",&n,&m);
        for(i=0; i<m; i++)
        {
            scanf("%lld%lld",&x,&y);
            if(x==y)
                continue;
            v[x].pb(y);
            v[y].pb(x);
        }
        c=0;
        vis=1;
        dfs(1,0);
        c=0;
        if(vis<v[1].size())//for root check
        {
            c++;
        }
        for(i=2; i<=n; i++)
        {
            if(ans[i]==1)
            {
                c++;
            }
        }
        printf("Case %lld: %lld\n",t++,c);
        mem(low);
        mem(dis);
        mem(ans);
        for(i=1; i<=n; i++)
        {
            v[i].clear();
        }
    }
    return 0;
}

