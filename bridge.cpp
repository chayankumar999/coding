#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define mk make_pair
#define pi 2*acos(0.0)
#define pf(a) printf("%lld\n",a)
#define sc(a) scanf("%lld",&a)
#define scn(a,b) scanf("%lld%lld",&a,&b)
#define pf1(t,a) printf("Case %lld: %lld\n",t,a)
#define mem(a) memset(a,0,sizeof (a))
#define mems(a) memset(a,-1,sizeof(a))
vector<int>v[100005];
int ans[10005],vis[100005];
int low[10005],dis[100005],n,m,c,p;
vector< pair<int,int> >pr;
void dfs(int x,int p)
{
    vis[x]=1;
    int sz=v[x].size();
    low[x]=dis[x]=++c;
    for(int i=0; i<sz; i++)
    {
        int adx=v[x][i];
        if(adx==p)
        {
            continue;
        }
        if(low[adx]==0)
        {
            dfs(adx,x);
            if(dis[x]<low[adx])
            {
                if(x<adx)
                {
                    pr.pb(mk(x,adx));
                }
                else
                {
                    pr.pb(mk(adx,x));
                }
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
    int i,j,k,l,x,y,tc,t=1,z;
    char s[100005];
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d%s",&x,s);
            z=0;
            for(j=1; j<strlen(s)-1; j++)
            {
                z=z*10+(s[j]-'0');
            }
            for(j=0; j<z; j++)
            {
                scanf("%d",&y);
                v[x].pb(y);
                v[y].pb(x);
            }
        }
        c=0;
        for(i=0; i<n; i++)
        {
            if(vis[i]==0)
            {
                dfs(i,i);
            }
        }
        for(i=0; i<=n; i++)
        {
            if(ans[i]==1)
            {
                c++;
            }
        }
        printf("Case %d:\n",t++);
        sort(pr.begin(),pr.end());
        printf("%d critical links\n",pr.size());
        for(i=0; i<pr.size(); i++)
        {
            printf("%d - %d\n",pr[i].first,pr[i].second);
        }
        mem(low);
        mem(dis);
        mem(ans);
        mem(vis);
        pr.clear();
        for(i=0; i<=n; i++)
        {
            v[i].clear();
        }
    }
    return 0;
}

