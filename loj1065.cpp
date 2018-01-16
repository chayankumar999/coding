#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll m;
void mltple(ll a[2][2], ll b[2][2])
{
    ll ml[2][2];
    for(ll i=0; i<2; i++)
    {
        for(ll j=0; j<2; j++)
        {
            ml[i][j]=0;
            for(ll k=0; k<2; k++)
            {
                ml[i][j]=(ml[i][j] + (a[i][k]*b[k][j] % m))%m;
            }
        }
    }
    for(ll i=0; i<2; i++)
    {
        for(ll j=0; j<2; j++)
        {
            a[i][j]=ml[i][j];
        }
    }
}
void power(ll a[2][2],ll n)
{
    ll b[2][2]= {{1,1},{1,0}};
    if(n==1)
    {
        return;
    }
    else if(n%2==0)
    {
        power(a,n/2);
        mltple(a,a);
    }
    else if(n%2!=0)
    {
        power(a,n-1);
        mltple(a,b);
    }
}

ll mat(ll x, ll y, ll n)
{
    ll a[2][2]= {{1,1},{1,0}};
    power(a,n-1);
    return (y*a[0][0]+x*a[0][1])%m;
}
int main()
{
    ll tc,i,j,k,n,x,y,t=1;
    cin>>tc;
    while(tc--)
    {
        cin>>x>>y>>n>>m;
        ll z=1;
        for(i = 1; i <= m; i++) z *= 10;
        m = z;
        cout<<"Case "<<t++<<": "<<mat(x,y,n)<<endl;;
    }
    return 0;
}
