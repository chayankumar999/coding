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
ll a[10005];
ll vis[10005];
ll ans[10005];
ll tim[10005][2],n,m,c;
map<pair<ll,ll>,ll>mp;
void dfs(ll x)
{
    vis[x]=1;
    ll sz=v[x].size();
    tim[x][0]=tim[x][1]=++c;
    for(int i=0; i<sz; i++)
    {
        ll adx=v[x][i];
        if(mp[{x,adx}]==0) //for visited edge
        {
            mp[{x,adx}]++;
            mp[{adx,x}]++;
            if(adx==1)//for root check
            {
                vis[adx]++;
            }
            if(vis[adx]==0)
            {
                dfs(adx);
                tim[x][1]=min(tim[x][1],tim[adx][1]);
                if(tim[x][0]<=tim[adx][1]) ans[x]=1;
            }
            else
            {
                tim[x][1]=min(tim[x][1],tim[adx][0]);
            }
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
        dfs(1);
        c=0;
        if(vis[1]<v[1].size())//for root check
        {
            c++;
        }
        for(i=2; i<=n; i++)
        {
            if(ans[i]==1)
                c++;
        }
        printf("Case %lld: %lld\n",t++,c);
        mp.clear();
        mem(vis);
        mem(tim);
        for(i=1; i<=n; i++)
        {
            v[i].clear();
        }
        mem(ans);
    }
    return 0;
}

