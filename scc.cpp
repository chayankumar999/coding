#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define mx 100005
#define sc(a) scanf("%d",&a)
#define mem(a) memset(a,0,sizeof(a))
vector<int>G[mx],RG[mx];
int vis[mx];
stack<int>st;
void Reset(int n)
{
    for(int i=0; i<=n; i++)
    {
        G[i].clear();
        RG[i].clear();
        vis[i]=0;
    }
}
void dfs(int x)
{
    vis[x]=1;
    for(int i=0; i<G[x].size(); i++)
    {
        if(!vis[G[x][i]])
        {
            dfs(G[x][i]);
        }
    }
    st.push(x);
}
void dfs1(int x)
{
    vis[x]=1;
    for(int i=0; i<RG[x].size(); i++)
    {
        if(!vis[RG[x][i]])
        {
            dfs1(RG[x][i]);
        }
    }
}
int show_scc()
{
    int c=0;
    while(!st.empty())
    {
        int x=st.top();
        st.pop();
        if(!vis[x])
        {
            dfs1(x);
            c++;
        }
    }
    return c;
}
int main()
{
    int a,b,r,tc,n,k,cs=1,x,y,c,i,sz;
    int L,R;
    sc(tc);
    while(tc--)
    {
        sc(n);sc(k);
        Reset(n);
        c=1;
        for(i=0; i<k; i++)
        {
            sc(a);sc(b);
            G[a].pb(b);
            RG[b].pb(a);
        }
        for(i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                dfs(i);
            }
        }
        mem(vis);
        printf("Case %d: %d\n",cs++,show_scc());
    }
    return  0;
}

