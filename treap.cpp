#include <bits/stdc++.h>
using namespace std;

#define FasterIO ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define ff first
#define ss second
#define pb push_back
#define mk make_pair

typedef long long ll;
typedef double db;
typedef queue<int> qq;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<pii> vii;

#define sc scanf
#define pf1 printf
#define sc1(x) scanf("%d", &x)
#define sc2(x, y) scanf("%d %d", &x, &y)
#define sc3(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define mem(a) memset(a,0,sizeof(a))
#define mems(a) memset(a,-1,sizeof(a))
#define inf 1e18
#define MOD 23102009
#define MX 1000006
int T[MX],lft[MX],rgt[MX],sz[MX],prio[MX],av;
int newNode(int x)//createNewNode
{
    T[av]=x;
    lft[av]=rgt[av]=0;
    sz[av]=1;
    prio[av]=rand();
    return av++;
}
void update(int x)//size update of node x
{
    if(x)sz[x]=sz[lft[x]]+sz[rgt[x]]+1;
}
pii splits(int x, int s)//splitBySize
{
    if(!x) return {0,0};
    if(!s) return {0,x};
    else if(sz[x]<=s) return {x,0};
    else if(sz[lft[x]]>=s)
    {
        pii ret=splits(lft[x],s);
        lft[x]=ret.ss;
        update(x);
        return {ret.ff,x};
    }
    else
    {
        pii ret=splits(rgt[x],s-sz[lft[x]]-1);
        rgt[x]=ret.ff;
        update(x);
        return {x,ret.ss};
    }
}
pii splitv(int x, int v)//splitByValue
{
    if(!x)return {0,0};
    if(T[x]<=v)
    {
        pii ret=splitv(rgt[x],v);
        rgt[x]=ret.ff;
        update(x);
        return {x,ret.ss};
    }
    else
    {
        pii ret=splitv(lft[x],v);
        lft[x]=ret.ss;
        update(x);
        return {ret.ff,x};
    }
}
int join(int l, int r)//joinTwoBst
{
    if(!l||!r)return l?l:r;
    if(prio[l]>prio[r])
    {
        rgt[l]=join(rgt[l],r);
        update(l);
        return l;
    }
    else
    {
        lft[r]=join(l,lft[r]);
        update(r);
        return r;
    }
}
int a[MX];
int main()
{
    int tc,i,j,k,n,m,x,y,z;
    cin>>tc;
    while(tc--)
    {
        av=1;
        cin>>n;
        x=newNode(1);
        for(i=2;i<=n;i++)
        {
            y=newNode(i);
            x=join(x,y);
        }
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(i=n;i>=1;i--)
        {
            y=i-a[i];
            pii ret=splits(x,y);
            pii ret1=splits(ret.ff,y-1);
            x=join(ret1.ff,ret.ss);
            a[i]=T[ret1.ss];
        }
        for(i=1;i<=n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



// reverse range between a to b



#include <bits/stdc++.h>
using namespace std;

#define FasterIO ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define ff first
#define ss second
#define pb push_back
#define mk make_pair

typedef long long ll;
typedef double db;
typedef queue<int> qq;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<pii> vii;

#define sc scanf
#define pf1 printf
#define sc1(x) scanf("%d", &x)
#define sc2(x, y) scanf("%d %d", &x, &y)
#define sc3(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define mem(a) memset(a,0,sizeof(a))
#define mems(a) memset(a,-1,sizeof(a))
#define inf 1e18
#define MOD 23102009
#define MX 1000006
int T[MX],lft[MX],rgt[MX],sz[MX],prio[MX],lazy[MX],av;
int newNode(int x)//createNewNode
{
    T[av]=x;
    lft[av]=rgt[av]=0;
    sz[av]=1;
    prio[av]=rand();
    return av++;
}
void propagate(int x) // for reverse a range
{
    swap(lft[x], rgt[x]);
    lazy[lft[x]]^=lazy[x];
    lazy[rgt[x]]^=lazy[x];
    lazy[x]=0;
}

void update(int x)//size update of node x
{
    if(x) sz[x]=sz[lft[x]]+sz[rgt[x]]+1;
}

pii splits(int x, int s)//splitBySize
{
    if(lazy[x]) propagate(x);
    if(!x) return {0,0};
    if(!s) return {0,x};
    else if(sz[x]<=s) return {x,0};
    else if(sz[lft[x]]>=s)
    {
        pii ret=splits(lft[x],s);
        lft[x]=ret.ss;
        update(x);
        return {ret.ff,x};
    }
    else
    {
        pii ret=splits(rgt[x],s-sz[lft[x]]-1);
        rgt[x]=ret.ff;
        update(x);
        return {x,ret.ss};
    }
}

int join(int l, int r)//joinTwoBst
{
    if(lazy[l]) propagate(l);
    if(lazy[r]) propagate(r);
    if(!l||!r)return l?l:r;
    if(prio[l]>prio[r])
    {
        rgt[l]=join(rgt[l],r);
        update(l);
        return l;
    }
    else
    {
        lft[r]=join(l,lft[r]);
        update(r);
        return r;
    }
}

int ans[MX];

int main()
{
    int tc,i,j,k,n,m,x,y,z;
    while(cin>>n>>m)
    {
        av=1;
        x=newNode(1);
        for(i=2;i<=n;i++)
        {
            y=newNode(i);
            x=join(x,y);
        }
        for(int i=1; i<=m; i++)
        {
            int a, b;
            cin>>a>>b;
            pii ret=splits(x,b);
            pii ret1=splits(ret.ff,a-1);
            lazy[ret1.ss]^=1;
            x=join(ret1.ff,ret.ss);
            x=join(x, ret1.ss);
        }
        for(i=n;i>=1;i--)
        {
            pii ret=splits(x, i-1);
            x=ret.ff;
            ans[i]=T[ret.ss];
        }
        for(int i=1; i<=n; i++)
        {
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}

