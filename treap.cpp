#include <bits/stdc++.h>
using namespace std;

#define FasterIO ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define ff first
#define ss second

typedef pair<int, int> pi;

#define inf 1e9
#define MX 1000000+5

int T[MX], lft[MX], rgt[MX], sz[MX], prio[MX], a[MX], av;

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
pi splits(int x, int s)//splitBySize
{
    if(!x) return {0, 0};
    if(!s) return {0, x};
    else if(sz[x]<=s) return {x, 0};
    else if(sz[lft[x]]>=s)
    {
        pi ret=splits(lft[x], s);
        lft[x]=ret.ss;
        update(x);
        return {ret.ff, x};
    }
    else
    {
        pi ret=splits(rgt[x], s-sz[lft[x]]-1);
        rgt[x]=ret.ff;
        update(x);
        return {x, ret.ss};
    }
}
pi splitv(int x, int v)//splitByValue
{
    if(!x) return {0, 0};
    if(T[x]<=v)
    {
        pi ret=splitv(rgt[x], v);
        rgt[x]=ret.ff;
        update(x);
        return {x, ret.ss};
    }
    else
    {
        pi ret=splitv(lft[x], v);
        lft[x]=ret.ss;
        update(x);
        return {ret.ff, x};
    }
}
int join(int l, int r)//joinTwoBst
{
    if(!l||!r)return l?l:r;
    if(prio[l]>prio[r])
    {
        rgt[l]=join(rgt[l], r);
        update(l);
        return l;
    }
    else
    {
        lft[r]=join(l, lft[r]);
        update(r);
        return r;
    }
}

int main()
{
    int tc, n, m, x, y;
    cin>>tc;
    while(tc--)
    {
        cin>>n; av=1;
        x=newNode(1);
        for(int i=2; i<=n; i++)
        {
            y=newNode(i);
            x=join(x, y);
        }
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        for(int i=n; i>=1; i--)
        {
            y=i-a[i];
            pi ret=splits(x, y);
            pi ret1=splits(ret.ff, y-1);
            x=join(ret1.ff, ret.ss);
            a[i]=T[ret1.ss];
        }
        for(int i=1; i<=n; i++)
        {
            cout<<a[i];
            if(i<n) cout<<' ';
            else    cout<<endl;
        }
    }
    return 0;
}


---------------------------------------------
// reverse range between a to b with lazy  //
---------------------------------------------




//problem: UVA - 11922 - Permutation Transformer


#include <bits/stdc++.h>
using namespace std;

#define FasterIO ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define ff first
#define ss second

typedef pair<int, int> pi;

#define inf 1e9
#define MX 1000000+5


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

pi splits(int x, int s)//splitBySize
{
    if(lazy[x]) propagate(x);
    if(!x) return {0,0};
    if(!s) return {0,x};
    else if(sz[x]<=s) return {x,0};
    else if(sz[lft[x]]>=s)
    {
        pi ret=splits(lft[x],s);
        lft[x]=ret.ss;
        update(x);
        return {ret.ff,x};
    }
    else
    {
        pi ret=splits(rgt[x],s-sz[lft[x]]-1);
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
            pi ret=splits(x,b);
            pi ret1=splits(ret.ff,a-1);
            lazy[ret1.ss]^=1;
            x=join(ret1.ff,ret.ss);
            x=join(x, ret1.ss);
        }
        for(i=n;i>=1;i--)
        {
            pi ret=splits(x, i-1);
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




// problem: UVA - 1402 Robotic Sort

#include <bits/stdc++.h>
using namespace std;

#define FasterIO ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define ff first
#define ss second

typedef pair<int, int> pi;
typedef pair<int, pi > pii;
typedef pair<int, pii>p4;

#define inf 1e9
#define MX 1000000+5

int lft[MX], rgt[MX], sz[MX], prio[MX], lazy[MX], av, n;

pi T[MX],T1[MX];

int newNode(int x, int c)//createNewNode
{
    T[av]=T1[av]={x, c};
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

pi splits(int x, int s)//splitBySize
{
    if(lazy[x]) propagate(x);
    if(!x) return {0,0};
    if(!s) return {0,x};
    else if(sz[x]<=s) return {x,0};
    else if(sz[lft[x]]>=s)
    {
        pi ret=splits(lft[x],s);
        lft[x]=ret.ss;
        T1[x]=min(T1[lft[x]], T[x]);
        T1[x]=min(T1[rgt[x]], T1[x]);
        update(x);
        return {ret.ff,x};
    }
    else
    {
        pi ret=splits(rgt[x],s-sz[lft[x]]-1);
        rgt[x]=ret.ff;
        T1[x]=min(T1[lft[x]], T[x]);
        T1[x]=min(T1[rgt[x]], T1[x]);
        update(x);
        return {x,ret.ss};
    }
}

p4 Q(int x, int s) // find the minimum value between 1 to md
{
    if(lazy[x]) propagate(x);
    if(!x) return {0,{0, {inf, n}}};
    if(!s) return {0,{x, {inf, n}}};
    if(sz[x]<=s) return {x,{0, T1[x]}};
    else if(sz[lft[x]]>=s)
    {
        p4 ret=Q(lft[x],s);
        lft[x]=ret.ss.ff;
        T1[x]=min(T1[lft[x]], T[x]);
        T1[x]=min(T1[rgt[x]], T1[x]);
        update(x);
        return {ret.ff,{x, min(T1[ret.ff], ret.ss.ss)}};
    }
    else
    {
        p4 ret=Q(rgt[x],s-sz[lft[x]]-1);
        rgt[x]=ret.ff;
        T1[x]=min(T1[lft[x]], T[x]);
        T1[x]=min(T1[rgt[x]], T1[x]);
        update(x);
        return {x,{ret.ss.ff, min(T1[x], ret.ss.ss)}};
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
        T1[l]=min(T1[l], T1[r]);
        update(l);
        return l;
    }
    else
    {
        lft[r]=join(l,lft[r]);
        T1[r]=min(T1[l], T1[r]);
        update(r);
        return r;
    }
}

int main()
{
    int x, y;
    while(cin>>n && n)
    {
        vector<pi>v(n); av=1;

        cin>>v[0].ff; v[0].ss=0;
        x=newNode(v[0].ff, 0); T1[0]={inf, n};

        for(int i=1; i<n; i++)
        {
            cin>>v[i].ff; v[i].ss=i;
            y=newNode(v[i].ff, v[i].ss);
            x=join(x,y);
        }
        sort(v.begin(), v.end());
        for(int i=0; i<n; i++)
        {
            int lo=1, hi=n-i+1, rs=-1;
            while(lo<=hi)
            {
                int md=(lo+hi)/2;
                p4 ret=Q(x, md);
                x=join(ret.ff, ret.ss.ff);
                if(ret.ss.ss<=v[i])
                {
                    rs=md; hi=md-1;
                }
                else lo=md+1;
            }
            if(rs==1)
            {
                x=splits(x,rs).ss;
                cout<<rs+i;
                if(i<n-1) cout<<' ';
                else    cout<<endl;
                continue;
            }
            pi ret=splits(x,rs);
            pi ret1=splits(ret.ff,rs-1);
            lazy[ret1.ff]^=1;
            x=join(ret1.ff,ret.ss);
            cout<<rs+i;
            if(i<n-1) cout<<' ';
            else    cout<<endl;
        }
    }
    return 0;
}
