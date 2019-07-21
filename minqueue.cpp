// codeforces.com/contest/1195/problem/E
// Find the min/max element from a matrix/array in O(n) time using dequeue

#include <bits/stdc++.h>
using namespace std;
#define FasterIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;

#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vL vector<ll>
#define pi pair<int,int>
#define pL pair<ll,ll>
#define pii pair<int,pi>
#define pLL pair<ll,pL>
#define vp vector<pi>

const int MX=3000+5;
const int inf=1e9;
const ll mod=998244353;
ll g[MX*MX],h[MX][MX],mn[MX][MX];
ll n,m,a,b,x,y,z;
void buildH()
{
    for(int i=1;i<MX*MX;i++) g[i]=(g[i-1]*x+y)%z;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            h[i][j]=g[(i-1)*m+j-1];
        }
    }
}
int main()
{
    FasterIO;

    cin>>n>>m>>a>>b>>g[0]>>x>>y>>z;
    buildH();
    for(int j=1;j<=m;j++)
    {
        deque<pL>dq;
        for(int i=1;i<=n;i++)
        {
            while(!dq.empty() && dq.back().ss >= h[i][j]) dq.pop_back();
            dq.push_back({i,h[i][j]});
            while(!dq.empty() && dq.front().ff<i-a+1) dq.pop_front();
            if(i-a+1 > 0) mn[i-a+1][j]=dq.front().ss;
        }
    }
    ll sm=0;
    for(int i=1;i<=n-a+1;i++)
    {
        deque<pL>dq;
        for(int j=1;j<=m;j++)
        {
            while(!dq.empty() && dq.back().ss >= mn[i][j]) dq.pop_back();
            dq.push_back({j,mn[i][j]});
            while(!dq.empty() && dq.front().ff < j-b+1) dq.pop_front();
            if(j-b+1 > 0) sm += dq.front().ss;
        }
    }
    cout<<sm<<endl;
    return 0;
}

