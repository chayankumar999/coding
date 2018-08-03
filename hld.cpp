#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define sc(a) scanf("%d",&a)
#define mem(a) memset(a,0,sizeof(a))
#define mems(a) memset(a,-1,sizeof(a))
#define N 30005
struct treeNode
{
    int par;
    int depth;
    int sz;
    int pos_segbase;
    int heavy;
} node[N];
int bar[N],T[2*N],a[N],heavy[N];
vector<int>adj[N];
int av;
int dfs(int cur, int pre, int dpt)
{
    node[cur].par=pre;
    node[cur].depth=dpt;
    node[cur].heavy=-1;
    int s=1,h=0;
    for(int i=0; i<adj[cur].size(); i++)
    {
        if(adj[cur][i]!=pre)
        {
            int c=dfs(adj[cur][i],cur,dpt+1);
            if(c>h)
            {
                h=c;
                node[cur].heavy=i;
            }
            s+=c;
        }
    }
    return node[cur].sz=s;
}
int chainNo=0,chainHead[N],chainInd[N];

void hld(int cur, int pre)
{
    if(chainHead[chainNo]==-1)
    {
        chainHead[chainNo]=cur;
    }
    chainInd[cur]=chainNo;
    bar[av]=a[cur];
    node[cur].pos_segbase=av++;
    int ind=node[cur].heavy;
    if(ind>=0)
    {
        hld(adj[cur][ind],cur);
    }
    for(int i=0; i<adj[cur].size(); i++)
    {
        if(ind!=i&&adj[cur][i]!=pre)
        {
            chainNo++;
            hld(adj[cur][i],cur);
        }
    }
}
void build(int n)
{
    for(int i=0;i<n;i++)
    {
        T[i+n]=bar[i];
    }
    for(int i=n-1;i>0;i--)
    {
        T[i]=T[i<<1]+T[i<<1|1];
    }
}
void update(int n, int pos, int v)
{
    pos+=n;
    for(T[pos]=v,pos>>=1;pos>0;pos>>=1)
    {
        T[pos]=T[pos<<1]+T[pos<<1|1];
    }
}
int RMQ(int n, int x, int y)
{
    y++;
    x+=n;y+=n;
    int s=0;
    for(;x<y;x>>=1,y>>=1)
    {
        if(x&1) s+=T[x++];
        if(y&1) s+=T[--y];
    }
    return s;
}

int chain_up(int u, int v, int n)
{
    int chain_u, chain_v, ans = 0;

    while (true)
    {
        chain_u = chainInd[u];
        chain_v = chainInd[v];
        if (chain_u==chain_v)
        {
            if(node[v].depth>node[u].depth)
            {
                swap(u,v);
            }
            ans += RMQ(n,node[v].pos_segbase,node[u].pos_segbase);
            break;
        }
        else
        {
            if (chain_u<chain_v)
            {
                ans += (RMQ(n,node[chainHead[chain_v]].pos_segbase,node[v].pos_segbase));
                v=node[chainHead[chain_v]].par;
            }
            else
            {
                ans += (RMQ(n,node[chainHead[chain_u]].pos_segbase,node[u].pos_segbase));
                u = node[chainHead[chain_u]].par;
            }
        }
    }
    return ans;
}
void maxEdge(int u, int v,int n)
{
    int ans = chain_up(u,v,n);
    printf("%d\n", ans);
}
void Set(int n)
{
    for(int i=0;i<=n;i++)
    {
        chainHead[i]=-1;
        chainInd[i]=0;
        adj[i].clear();
    }
}
int main()
{
    int tc,i,j,n,m,k,x,y,cs=1,q;
    sc(tc);
    while(tc--)
    {
        sc(n);
        Set(n);
        printf("Case %d:\n",cs++);
        for(i=0; i<n; i++)
        {
            sc(a[i]);
        }
        for(i=0; i<n-1; i++)
        {
            sc(x);
            sc(y);
            adj[x].pb(y);
            adj[y].pb(x);
        }
        av=0;
        m=dfs(0,0,0);
        av=0;
        chainNo=0;
        hld(0,0);
        build(n);
        sc(q);
        while(q--)
        {
            sc(k);
            sc(x);
            sc(y);
            if(k)
            {
                update(n,node[x].pos_segbase,y);
            }
            else
            {
                maxEdge(x,y,n);
            }
        }
    }
    return 0;
}
