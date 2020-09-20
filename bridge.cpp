/*
Problem: Real Life Traffic (Light Oj)
Problem Link: http://lightoj.com/volume_showproblem.php?problem=1291
*/

#include<bits/stdc++.h>
using namespace std;

const int MX=10005;

vector<int> g[MX];

vector<pair<int, int> > E;

int vis[MX], low[MX], dis[MX];
int f[MX], component[MX], Time;

map<pair<int, int>, int>mp;

void CLEAR(int n)
{
    Time=0; mp.clear(); E.clear();
    for(int i=0;i<=n;i++)
    {
        vis[i]=low[i]=dis[i]=f[i]=0;
        g[i].clear();
    }
}

void dfs(int u, int p)
{
    low[u]=dis[u]=++Time;
    for(auto v:g[u])
    {
        if(v==p) continue;

        if(low[v]==0)
        {
            dfs(v,u);
            if(dis[u]<low[v])
            {
                mp[{u,v}]=mp[{v,u}]=1; E.push_back({u,v});
            }
            low[u]=min(low[u], low[v]);
        }
        else
        {
            low[u]=min(low[u], dis[v]);
        }
    }
}

void dfs2(int u, int id)
{
    vis[u]=1; component[u]=id;
    for(auto v:g[u])
    {
        if(vis[v] ||mp.count({u, v}) )continue;
        dfs2(v, id);
    }
}

int main()
{
    int tc, cs=1; scanf("%d", &tc);
    while(tc--)
    {
        int n, m; scanf("%d%d", &n, &m); CLEAR(n);

        for(int i=1; i<=m; i++)
        {
            int x, y; scanf("%d%d", &x, &y);
            g[x].push_back(y), g[y].push_back(x);
        }

        dfs(0, 0);

        int id=0;
        for(int i=0; i<n; i++)
        {
            if(!vis[i]) dfs2(i, id++);
        }

        for(auto p:E)
        {
            f[component[p.first]]++;
            f[component[p.second]]++;
        }

        int ans=0;
        for(int i=0;i<n;i++) if(f[i]==1) ans++;

        ans=(ans+1)/2;

        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}
