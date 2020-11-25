//LOJ 1003 Drunk
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
map<string,int>mp;
vector<int>G[mx];
int vis[mx],run[mx];
int flg;
void Reset(int n)
{
    mp.clear();
    for(int i=0; i<=n; i++)
    {
        G[i].clear();
        vis[i]=false;
    }
}
void dfs(int x) // cycle finding dfs
{
    vis[x]=run[x]=true;
    for(int i=0; i<G[x].size(); i++)
    {
        if(vis[G[x][i]]&&run[G[x][i]])
        {
            flg=1;
        }
        if(!vis[G[x][i]])
        {
            dfs(G[x][i]);
        }
    }
    run[x]=false;
}
int main()
{
    int a,b,r,tc,n,k,cs=1,x,y,c,i,sz;
    int L,R;
    string s,s1;
    sc(tc);
    while(tc--)
    {
        sc(n);
        c=1;
        flg=0;
        for(i=0; i<n; i++)
        {
            cin>>s>>s1;
            if(!mp[s])
            {
                mp[s]=c++;
            }
            if(!mp[s1])
            {
                mp[s1]=c++;
            }
            G[mp[s]].pb(mp[s1]);
        }
        for(i=1;i<c;i++)
        {
            if(!vis[i])
            {
                dfs(i);
            }
        }
        printf("Case %d: ",cs++);
        if(flg)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
        }
        Reset(c);
    }
    return  0;
}



// A set of vertex which make a cycle in an undirected graph

#include<bits/stdc++.h>
using namespace std;

const int MX=200000+10;

vector<int>g[MX], cycle;

int A, B, f;
int vis[MX], run[MX], P[MX];

void dfs(int v, int p)
{
    if(f) return;
    vis[v]=run[v]=1, P[v]=p;
    for(auto u:g[v])
    {
        if(f) return;
        if(u!=p && vis[u] && run[u])
        {
            A=u, B=v, f=1; return;
        }
        if(!vis[u]) dfs(u, v);
    }
    run[v]=0;
}


int main()
{
    int n; cin>>n;

    A=B=f=0; cycle.clear();
    for(int i=1; i<=n; i++)
    {
        int x, y; cin>>x>>y;
        g[x].push_back(y), g[y].push_back(x);
    }

    dfs(1, 0);

    for(int i=1; i<=n; i++) vis[i]=0;

    int cn=0;
    while(true)
    {
        if(A==B) break;
        cycle.push_back(B);
        vis[B]=1, B=P[B], cn++;
    }
    cycle.push_back(B), vis[B]=1, cn++;

    cout<<"cycle length = "<<cn<<'\n';
    for(auto u:cycle) cout<<u<<' ';
    cout<<'\n';

    return 0;
}
