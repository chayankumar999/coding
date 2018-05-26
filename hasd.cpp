#include<bits/stdc++.h>
using namespace std;
#define db double
#define ll long long int
#define m 99999989
ll bigmod(ll b, ll p)
{
    if(p==0)
    {
        return 1;
    }
    if(p%2==0)
    {
        ll r=bigmod(b,p/2);
        return (r%m*r%m)%m;
    }
    else
    {
        return (b%m*bigmod(b,p-1)%m)%m;
    }
}

ll modInv(ll a)
{
    return bigmod(a,m-2);
}
string s;
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ////////////////////////////////////////////////
    ll tc,i,j,k,b=2,b1=3,b2=5,md,md1,md2,nxt,nxt1,nxt2;
    ll hs,hs1,bh,bh1,hs2,bh2,c,sz;
    cin>>tc;
    while(tc--)
    {
        cin>>s;
        hs=hs1=bh=bh1=hs2=bh2=0LL;
        c=0;
        sz=s.size();
        for(i=0; i<sz; i++)
        {
            hs=(hs+((bigmod(b,i)%m)*(s[i]-'a'+1))%m)%m;
            hs1=(hs1+((bigmod(b1,i)%m)*(s[i]-'a'+1))%m)%m;
            hs2=(hs2+((bigmod(b2,i)%m)*(s[i]-'a'+1))%m)%m;
        }
        j=0;
        for(i=sz-1; i>=0; i--)
        {
            bh=(bh+((bigmod(b,j)%m)*(s[i]-'a'+1))%m)%m;
            bh1=(bh1+((bigmod(b1,j)%m)*(s[i]-'a'+1))%m)%m;
            bh2=(bh2+((bigmod(b2,j)%m)*(s[i]-'a'+1))%m)%m;
            j++;
        }
        md=modInv(b)%m;
        md1=modInv(b1)%m;
        md2=modInv(b2)%m;
        nxt=bigmod(b,sz-1)%m;
        nxt1=bigmod(b1,sz-1)%m;
        nxt2=bigmod(b2,sz-1)%m;
        for(i=0; i<sz; i++)
        {
            hs=(hs-(s[i]-'a'+1)%m+m)%m;
            hs1=(hs1-(s[i]-'a'+1)%m+m)%m;
            hs2=(hs2-(s[i]-'a'+1)%m+m)%m;

            hs=(hs%m*md%m)%m;
            hs1=(hs1%m*md1%m)%m;
            hs2=(hs2%m*md2%m)%m;

            hs=(hs+((s[i]-'a'+1)%m*nxt%m)%m)%m;
            hs1=(hs1+((s[i]-'a'+1)%m*nxt1%m)%m)%m;
            hs2=(hs2+((s[i]-'a'+1)%m*nxt2%m)%m)%m;

            bh=(bh-((s[i]-'a'+1)%m*nxt%m)%m+m)%m;
            bh1=(bh1-((s[i]-'a'+1)%m*nxt1%m)%m+m)%m;
            bh2=(bh2-((s[i]-'a'+1)%m*nxt2%m)%m+m)%m;

            bh=(bh%m*b%m)%m;
            bh1=(bh1%m*b1%m)%m;
            bh2=(bh2%m*b2%m)%m;

            bh=(bh+(s[i]-'a'+1))%m;
            bh1=(bh1+(s[i]-'a'+1))%m;
            bh2=(bh2+(s[i]-'a'+1))%m;
            if(hs==bh&&hs1==bh1&&hs2==bh2)
            {
                c++;
            }
        }
        printf("%lld\n",c);
    }
    return 0;
}
