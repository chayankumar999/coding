#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define uint unsigned long long
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define mx 505
#define inf 1e18
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define ssc(s) scanf("%s",s)
#define mem(a) memset(a,0,sizeof(a))
#define mems(a) memset(a,-1,sizeof(a))
bool vis[mx][mx];
int g[mx][mx];
int dx[6]= {1,-1,-1,-2,-2,-3};
int dy[6]= {-2,-2,-3,-1,1,-1};
int sprague(int x, int y,int n)
{
    set<int>st;
    set<int>::iterator it;
    if(vis[x][y])
    {
        return g[x][y];
    }
    for(int i=0; i<6; i++)
    {
        int adx=x+dx[i];
        int ady=y+dy[i];
        if(adx>0&&ady>0&&adx<=n&&ady<=n)
        {
            st.insert(sprague(adx,ady,n));
        }
    }
    vis[x][y]=true;
    int r=0;
    for(it=st.begin(); it!=st.end(); it++)
    {
        if(*it!=r)
        {
            break;
        }
        r++;
    }
    return g[x][y]=r;
}
void grundy(int n)
{
    vis[1][1]=vis[1][2]=vis[2][1]=vis[2][2]=true;
    for(int i=n; i>=1; i--)
    {
        for(int j=n; j>=1; j--)
        {
            if(!vis[i][j])
            {
                int r=sprague(i,j,n);
            }
        }
    }
}
int main()
{
    int r,tc,k,cs=1,x,y,c,i,j,z,n;
    grundy(mx-2);
    sc(tc);
    while(tc--)
    {
        sc(n);
        z=0;
        for(i=0;i<n;i++)
        {
            sc2(x,y);
            z^=g[++x][++y];
        }
        printf("Case %d: ",cs++);
        if(z)
        {
            printf("Alice\n");
        }
        else
        {
            printf("Bob\n");
        }
    }
    return  0;
}

