#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const ll MX=1000005;

ll bigmod(ll b, ll p)
{
    ll ans = 1;
    for(; p; p>>=1)
    {
        if(p&1) ans = ans * b % mod;
        b = b * b % mod;
    }
    return ans;
}

ll F[MX], IF[MX];

ll nCr(ll n, ll r)
{
    //if(r > n) return 0;
    return IF[r] * IF[n-r] % mod * F[n] % mod;
}

void FCT()
{
    F[0] = IF[0] = 1;
    for(int i = 1; i < MX; i++) F[i] = F[i-1] * i % mod;
    for(int i = 1; i < MX; i++) IF[i] = bigmod(F[i], mod-2);
}

int main()
{
    
    FCT();
    
    ll  n, r, tc;
    
    cin>>tc;
    
    while(tc--)
    {
        cin>>n>>r;
        cout<<nCr(n,r)<<endl;
    }
    
    return 0;
}


----------------------------------------------------------
Binomial Cofficient
----------------------------------------------------------
int NCR(int n, int r)
{
    if(r==0||r==n) return nCr[n][r]=1;
    if(~nCr[n][r]) return nCr[n][r];
    return nCr[n][r]=(NCR(n-1, r-1)+NCR(n-1, r))%mod;
}
----------------------------------------------------------
