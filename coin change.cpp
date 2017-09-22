#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[30001][5];
ll a[5]= {1,5,10,25,50};
ll way(ll n, ll i)
{
    if(i>4||n<0 )
        return 0;
    if(n==0)
        return 1;
    if( dp[n][i] != -1 ) return dp[n][i];
    dp[n][i]=way(n-a[i],i)+way(n,i+1);
    return dp[n][i];
}
int main()
{
    ll n,r;
    memset(dp,-1,sizeof(dp));
    while(scanf("%lld",&n)==1)
    {
        r=way(n,0);
        printf("%lld\n",r);
    }
    return 0;
}

