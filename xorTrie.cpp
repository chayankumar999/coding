#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define MX 100005
#define inf 1e9
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define mem(a) memset(a,0,sizeof(a))
#define mems(a) memset(a,-1,sizeof(a))
#define mod 1000000007
int trie[70*MX][2],sz;
void add(int x)
{
    int p=0;
    bool z;
    for(int i=30;i>=0;i--)
    {
        z=x&(1<<i);
        if(!trie[p][z])trie[p][z]=++sz;
        p=trie[p][z];
    }
}
int query(int x)
{
    int p=0,ret=0;
    bool z;
    for(int i=30;i>=0;i--)
    {
        z=x&(1<<i);
        if(trie[p][z^1]){ret|=(1<<i);p=trie[p][z^1];}
        else p=trie[p][z];
    }
    return ret;
}
int main()
{
    int tc,cs=1,i,j,k,n,x,xr,ans;
    sc(tc);
    while(tc--)
    {
        mem(trie);sz=0;add(0);
        sc(n);
        ans=xr=0;
        for(i=0;i<n;i++)
        {
            sc(x);
            xr^=x;
            ans=max(ans,query(xr));
            add(xr);
        }
        printf("%d\n",ans);
    }
    return 0;
}

