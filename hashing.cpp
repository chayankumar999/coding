#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX=100000;
const ll mod=1e9+7;
const ll mod1=999999937;
const ll mod2=998244353;

ll pw[MX],h[MX],rh[MX];
int main()
{

    ll base=29; pw[0]=1;
    for(int i=1;i<MX;i++) pw[i]=(pw[i-1]*base)%mod;

    string s;

    cin>>s;

    ll H=0,RH;
    int n=s.size()-1;

    for(int i=0;i<=n;i++)
    {
        H=(H*base+s[i])%mod;
        h[i]=H;
    }
    H=0;
    for(int i=n;i>=0;i--)
    {
        H=(H*base+s[i])%mod;
        rh[i]=H;
    }
    bool flag=false;
    for(int i=0;i<=n;i++)
    {
        H=(h[n]-(h[i]*pw[n-i])%mod+mod)%mod;
        H=((H*pw[i+1])%mod+h[i])%mod;
        RH=(rh[0]-(rh[i+1]*pw[i+1])%mod+mod)%mod;
        RH=((RH*pw[n-i])%mod+rh[i+1])%mod;
        if(H==RH && H!=h[n]) flag=true;
    }
    bool is=false;
    if((n+1)&1) s[n/2]=s[0];
    for(int i=0;i<(n+1)/2;i++)
    {
        if(s[i]!=s[i+1]) is=true;
    }
    if(!is)         cout<<"Impossible"<<endl;
    else if(flag)   cout<<1<<endl;
    else            cout<<2<<endl;
    return 0;
}
