//computable number//codeforces

//complexity O(n*2^n)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int MX=5000005;
const ll mod=1e9;
const ll inf=1e18;
#define FasterIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
int d[MX],dp[MX],f[MX];
int main()
{

    FasterIO;
    int i,j,k,n,m,x,y,tc;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>d[i];
        f[d[i]]++;
    }
    for(int msk=0; msk<(1LL<<22); msk++)
    {
        dp[msk]=f[msk];
    }
    for(i=0;i<=22;i++)
    {
        for(int msk=0;msk<(1LL<<22);msk++)
        {
            if(msk&(1LL<<i))
                dp[msk]+=dp[msk^(1LL<<i)];
        }
    }
    for(i=0; i<n; i++)
    {
        x=((1LL<<22)-1)^d[i];
        if(dp[x]==0)
        {
            cout<<"-1 ";
            continue;
        }
        int msk=x;
        for(j=22; j>=0; j--)
        {
            if((msk&(1<<j))&&dp[msk^(1LL<<j)])
            {
                msk=msk^(1LL<<j);
            }
        }
        cout<<msk<<" ";
    }
    cout<<endl;
    return 0;
}
