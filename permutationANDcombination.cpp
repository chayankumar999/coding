#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const ll MX=1000005;
ll bigmod(ll a, ll b)
{
    if(!b)return 1;
    else if(b&1) return (a*bigmod(a,b-1))%mod;
    else{ll r=bigmod(a,b/2);return (r*r)%mod;}
}
ll fct[MX];
ll NCR(ll n, ll r)
{
    ll res=bigmod(fct[n-r],mod-2);
    res=(res*(bigmod(fct[r],mod-2)))%mod;
    //nCr=n!/(r!*(n-r)!)
    return ((fct[n]*res)%mod);
}
void FCT()
{
    fct[0]=1;
    for(int i=1;i<MX;i++)
    {
        fct[i]=(fct[i-1]*i)%mod;
    }
}
int main()
{
    ll i,j,k,n,m,tc,x,y;
    FCT();
    cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
        cout<<NCR(n,m)<<endl;
    }
    return 0;
}
