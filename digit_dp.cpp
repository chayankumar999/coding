#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(a) memset(a,-1,sizeof(a))
#define ss(a) scanf("%lld",&a)
#define mx 1000005
ll dp[20][150][2];
string st;
ll sz;
ll digit(ll sm, ll pos, ll  flg)
{
    if(pos==sz)
    {
        return sm;
    }
    if(dp[pos][sm][flg]!=-1)
    {
        return dp[pos][sm][flg];
    }
    ll s=0;
    if(flg==1)
    {
        for(ll i=0; i<10; i++)
        {
            s+=digit(sm+i,pos+1,flg);
        }
    }
    else
    {
        for(ll i=0; i<st[pos]-'0'; i++)
        {
            s+=digit(sm+i,pos+1,1);
        }
        s+=digit(sm+st[pos]-'0',pos+1,0);
    }
    return dp[pos][sm][flg]=s;
}
void Tostring(ll x)
{
    st="";
    while(x)
    {
        st+=(x%10+'0');
        x/=10;
    }
    reverse(st.begin(),st.end());
    sz=st.size();
}
int main()
{
    ll a,b,r,tc;
    cin>>tc;
    while(tc--)
    {
        cin>>a>>b;
        if(a>b)
        {
            swap(a,b);
        }
        mem(dp);
        Tostring(b);
        r=digit(0,0,0);
        mem(dp);
        if(a-1>0)
        {
            Tostring(a-1);
            r-=digit(0,0,0);
        }
        cout<<r<<endl;
    }
    return 0;
}
