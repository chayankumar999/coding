/*
 codechef long Aprill 2019

 problem name: Mininum XOR over Tree

*/


#include<bits/stdc++.h>
using namespace std;
#define FasterIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;
typedef double db;

#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define ff first
#define ss second
#define mk make_pair
#define pi pair<int,int>

const int MX=200005;
const int mod=1e9+7;
const int inf=1e9;
struct node
{
    int vl;
    int in[2];
};

node T[25*MX],T1[25*MX];
int w[MX],root[MX],root1[MX],dis[MX],disv[MX],sz[MX];
int av,av1,c,com;
vector<int>g[MX];
unordered_map<int,int>mp,mp1;
inline void CLEAR(int n)
{
    for(int i=0; i<=n; i++)
    {
        g[i].clear();
    }
    av=av1=c=com=0;
}
inline void add(int pre, int cur, int x)
{
    bool z;
    for(int i=20; i>=0; i--)
    {
        z=x&(1<<i);
        if(!T[cur].in[z])
        {
            T[cur].in[z]=++av;
            T[T[cur].in[z]].vl=T[T[cur].in[z]].in[0]=T[T[cur].in[z]].in[1]=0;
        }

        T[T[cur].in[z]].vl=1+T[T[pre].in[z]].vl;

        T[cur].in[1^z]=T[pre].in[1^z];

        cur=T[cur].in[z];
        pre=T[pre].in[z];
    }
}
inline void add1(int pre, int cur, int x)
{
    bool z;
    for(int i=20; i>=0; i--)
    {
        z=x&(1<<i);
        if(!T1[cur].in[z])
        {
            T1[cur].in[z]=++av1;
            T1[T1[cur].in[z]].vl=T1[T1[cur].in[z]].in[0]=T1[T1[cur].in[z]].in[1]=0;
        }

        T1[T1[cur].in[z]].vl=1+T1[T1[pre].in[z]].vl;

        T1[cur].in[1^z]=T1[pre].in[1^z];

        cur=T1[cur].in[z];
        pre=T1[pre].in[z];
    }
}
inline int Q(int pre, int cur, int x)
{
    bool z;
    int mx=0;
    for(int i=20; i>=0; i--)
    {
        z=x&(1<<i);
        int d=T[T[cur].in[1^z]].vl-T[T[pre].in[1^z]].vl;
        if(d)
        {
            mx|=(1<<i);
            cur=T[cur].in[1^z];
            pre=T[pre].in[1^z];
        }
        else
        {
            cur=T[cur].in[z];
            pre=T[pre].in[z];
        }
    }
    return mx;
}
inline int Q1(int pre, int cur, int x)
{
    bool z;
    int mx=0;
    for(int i=20; i>=0; i--)
    {
        z=x&(1<<i);
        int d=T1[T1[cur].in[1^z]].vl-T1[T1[pre].in[1^z]].vl;
        if(d)
        {
            mx|=(1<<i);
            cur=T1[cur].in[1^z];
            pre=T1[pre].in[1^z];
        }
        else
        {
            cur=T1[cur].in[z];
            pre=T1[pre].in[z];
        }
    }
    return mx;
}
inline void dfs(int x, int p)
{
    dis[x]=++c;
    disv[c]=x;
    sz[x]=1;
    for(auto u:g[x])
    {
        if(u==p)
            continue;
        dfs(u,x);
        sz[x]+=sz[u];
    }
}
int main()
{
    FasterIO;
    int i,j,x,y,n,m,q,tc;
    int mxv=1;
    for(i=1; i<=20; i++)
    {
        mxv*=2;
    }
    mxv-=1;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>q;
        CLEAR(n);
        for(i=1; i<=n; i++)
        {
            cin>>w[i];
        }
        for(i=1; i<n; i++)
        {
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        dfs(1,1);
        vector<pi>E;
        vector<pi> v;
        E.push_back({0,0});
        v.push_back({0,0});
        for(i=1; i<=n; i++)
        {
            E.push_back({w[i],dis[i]});
            v.push_back({i,disv[i]});
        }
        sort(E.begin(),E.end());
        root[0]=0;
        root1[0]=0;
        mp.clear();
        mp1.clear();
        for(i=1; i<=n; i++)
        {
            if(!mp[E[i].ff]) mp1[E[i].ff]=i;
            mp[E[i].ff]++;
            root[i]=++av;
            root1[i]=++av1;
            T[av].vl=T[av].in[0]=T[av].in[1]=0;
            T1[av].vl=T1[av].in[0]=T1[av].in[1]=0;
            add(root[i-1],root[i],w[v[i].ss]);
            add1(root1[i-1],root1[i],disv[E[i].ss]);
        }

        int vertex,k;
        vertex=k=0;
        while(q--)
        {
            cin>>x>>y;
            vertex^=x;
            k^=y;
            if(sz[vertex]<=40)
            {
                int M=0,V=inf;
                for(i=dis[vertex]; i<=dis[vertex]+sz[vertex]-1; i++)
                {
                    int X=k^w[disv[i]];
                    if(X>M)
                    {
                        M=X;
                        V=disv[i];
                    }
                    else if(X==M)
                    {
                        V=min(V,disv[i]);
                    }
                }

                vertex=V;
                k=M;
            }
            else
            {
                int r=Q(root[dis[vertex]-1],root[dis[vertex]+sz[vertex]-1],k);
                if(mp[r^k]<=30)
                {
                    int V=inf;
                    for(i=mp1[r^k];i<E.size();i++)
                    {
                        if(E[i].ff!=(r^k))break;
                        if(E[i].ss>=dis[vertex] && E[i].ss<=dis[vertex]+sz[vertex]-1)
                        {
                            V=min(V,disv[E[i].ss]);
                        }
                        else if(E[i].ss>=dis[vertex]+sz[vertex])break;
                    }
                    vertex=V;
                }
                else
                {
                    int lo=lower_bound(E.begin(),E.end(),mk(r^k,dis[vertex]))-E.begin();
                    int hi=lower_bound(E.begin(),E.end(),mk(r^k,dis[vertex]+sz[vertex]))-E.begin();
                    lo--;
                    hi--;
                    vertex=Q1(root1[lo],root1[hi],mxv);
                    vertex^=mxv;
                }
                k=r;
            }
            cout<<vertex<<" "<<k<<"\n";
        }
    }
    return 0;
}
