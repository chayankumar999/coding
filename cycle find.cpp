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


