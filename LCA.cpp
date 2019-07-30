/*
***problem-TALCA(codechef)***
LCA for unrooted tree will be between // here we assume the tree is rooted at 1.
LCA(r, v), LCA(r, u), LCA(u, v) where r is the given root and u and v are corresponding node.
if two are equal and the third is different, then lca will be third one, else they're all equal lca will be that one.
*/
#include <bits/stdc++.h>
using namespace std;
#define FasterIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define vi vector<int>

const int MX=200000;
const int LG=18;

vi g[MX+5];
int lbl[MX+5],sp[MX+5][LG+2];

void dfs(int x, int p)
{
    sp[x][0]=p; lbl[x]=lbl[p]+1;
    for(auto u:g[x])
    {
        if(u==p) continue;
        dfs(u,x);
    }
}
void SPTBL(int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; (1<<j)<=n; j++)
        {
            if(sp[i][j-1]==-1) continue;
            sp[i][j]=sp[sp[i][j-1]][j-1];
        }
    }
}
int lca(int x, int y)
{
    if(lbl[x]<lbl[y]) swap(x,y);
    int dist = lbl[x] - lbl[y] ;
    for(int i=LG; i>=0; i--)
    {
        if((1<<i)<=dist)
        {
            x= sp[x][i];
            dist-= (1<<i);
        }
    }
    if(x==y) return x;
    for(int i=LG; i>=0; i--)
    {
        if(sp[x][i]!=sp[y][i] && sp[x][i]!=-1)
        {
            x=sp[x][i];
            y=sp[y][i];
        }
    }
    return sp[x][0];
}
int main()
{
    FasterIO;
    int n,q;
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    mem(sp,-1);
    dfs(1,0); SPTBL(n);
    cin>>q;
    while(q--)
    {
        int r,x,y;
        cin>>r>>x>>y;
        int lc1=lca(x,y);
        int lc2=lca(r,x);
        int lc3=lca(r,y);
        if(lc1==lc2 && lc2==lc3) cout<<lc1<<endl;
        else if(lc1==lc2)        cout<<lc3<<endl;
        else if(lc2==lc3)        cout<<lc1<<endl;
        else if(lc1==lc3)        cout<<lc2<<endl;
    }
    return 0;
}

