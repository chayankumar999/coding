//Codeforces E: Xeniya and Tree
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MX 100005
#define pb push_back
#define inf 1e9
vector<int>g[MX];
int centroid[MX],lvl[MX],par[MX],dist[20][MX],
SubTree[MX],ans[MX],sz;
void dfs(int u, int p)
{
    SubTree[u]=1;
    for(int i=0;i<g[u].size();i++)
    {
        int x=g[u][i];
        if(x==p||centroid[x])continue;
        dfs(x,u);
        SubTree[u]+=SubTree[x];
    }

}
int getCenter(int u, int p)
{
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==p||centroid[v])continue;
        if(SubTree[v]>sz/2)
        {
            return getCenter(v,u);
        }
    }
    return u;
}
void calculateDist(int u, int p, int cnt, int lv)
{
    dist[lv][u]=cnt;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==p||centroid[v])continue;
        calculateDist(v,u,cnt+1,lv);
    }
}
void deCompose(int u, int p, int lv)
{
    dfs(u,p);
    sz=SubTree[u];
    int center=getCenter(u,-1);
    calculateDist(center,-1,0,lv);
    centroid[center]=1;
    lvl[center]=lv;
    par[center]=p;
    for(int i=0;i<g[center].size();i++)
    {
        int v=g[center][i];
        if(v==p||centroid[v])continue;
        deCompose(v,center,lv+1);
    }
}
void update(int u)
{
    ans[u]=0;
    int v=u;
    while(v!=-1)
    {
        int lv=lvl[v];
        ans[v]=min(ans[v],dist[lv][u]);
        v=par[v];
    }
}
int query(int u)
{
    int v=u,mn=ans[u];
    while(v!=-1)
    {
        int lv=lvl[v];
        mn=min(mn,dist[lv][u]+ans[v]);
        v=par[v];
    }
    return mn;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //////////////////////////////////////
    int n,m,x,y,i,j,k,tst;
    cin>>n>>m;
    for(i=0;i<n-1;i++)
    {
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    for(i=0;i<=n;i++)
    {
        ans[i]=inf;
    }
    deCompose(1,-1,0);
    update(1);
    while(m--)
    {
        cin>>tst>>x;
        if(tst==1)
        {
            update(x);
        }
        else
        {
            cout<<query(x)<<endl;
        }
    }
    return 0;
}
