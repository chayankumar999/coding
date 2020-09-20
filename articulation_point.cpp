/*
Problem: Ant Network (Light Oj)
Problem Link: http://lightoj.com/volume_showproblem.php?problem=1308
*/

#include<bits/stdc++.h>
using namespace std;

const int MX=100000;
typedef unsigned long long ll;

vector<int>g[MX];

int AP[MX], ap, cn;

int low[MX], dis[MX], vis[MX], Time;

void dfs(int u, int p)
{
    low[u]=dis[u]=++Time;

    int child=0;

    for(auto v:g[u])
    {
        if(v==p) continue;

        if(low[v]==0)
        {
            child++;

            dfs(v, u);

            if(u!=0 && dis[u]<=low[v] || u==0 && child>1) AP[u]=ap=1;

            low[u]=min(low[u], low[v]);
        }
        else
        {
            low[u]=min(low[u], dis[v]);
        }
    }
}

set<int>st;

void dfs2(int u)
{
    if(vis[u]) return;

    vis[u]=1; cn++;

    for(auto v:g[u])
    {
        if(AP[v])
        {
            st.insert(v); continue;
        }

        dfs2(v);
    }
}

void RESET(int n)
{
    Time=0, ap=0;
    for(int i=0; i<n; i++) g[i].clear(), AP[i]=vis[i]=low[i]=dis[i]=0;
}

int main()
{
    int tc, cs=1;

    scanf("%d", &tc);

    while(tc--)
    {
        int n, m; scanf("%d%d", &n, &m);

        RESET(n);

        for(int i=0; i<m; i++)
        {
            int x, y; scanf("%d%d", &x, &y);
            g[x].push_back(y), g[y].push_back(x);
        }

        dfs(0, -1);

        ll way=1; int ans=0;

        if(ap==0) ans=2, way=(1LL*n*(n-1))/2;
        else
        {
            for(int i=0; i<n; i++)
            {
                if(AP[i] || vis[i]) continue;

                st.clear(); cn=0;
                dfs2(i);
                if(st.size()<=1) way*=cn, ans++;
            }
        }
        printf("Case %d: %d %llu\n", cs++, ans, way);
    }
    return 0;
}
