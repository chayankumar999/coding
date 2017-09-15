#include<bits/stdc++.h>
using namespace std;
#define MX 10000007
#define ll long long
#define base 29
#define mod 1000000007
#define ull unsigned long long
string s,s1;
ull pw[MX],hf,hb,h;
int main()
{
    ll tc,i,j,n,k,m,c,l,t;
    char ch,ch1;
    pw[0]=1;
    for(i=1; i<=MX; i++)
    {
        pw[i]=pw[i-1]*base;
    }
    cin>>tc;
    t=1;
    while(tc--)
    {
        cin>>s;
        l=s.size();
        cout<<"Case "<<t++<<":"<<endl;
        hf=0;
        hb=0;
        h=0;
        for(i=0; i<l; i++)
        {
            h=h*base+s[i]-96;
        }
        hf=h;
        h=0;
        for(i=l-1; i>=0; i--)
        {
            h=h*base+s[i]-96;
        }
        hb=h;
        cin>>n;
        for(i=0; i<n; i++)
        {
            cin>>ch>>ch1>>k;
            if(ch=='L')
            {
                h=0;
                for(j=0;j<k;j++)
                {
                    h=h*base+ch1-96;
                    hb=hb*base+ch1-96;
                }
                hf=h*pw[l]+hf;
                l+=k;
                //cout<<hf<<" "<<hb<<endl;
                if(hf==hb)
                {
                    cout<<"Yes"<<endl;
                }
                else
                {
                    cout<<"No"<<endl;
                }
            }
            else
            {
                h=0;
                for(j=0;j<k;j++)
                {
                    h=h*base+ch1-96;
                    hf=hf*base+ch1-96;
                }
                hb=h*pw[l]+hb;
                l+=k;
                //cout<<hf<<" "<<hb<<endl;
                if(hf==hb)
                {
                    cout<<"Yes"<<endl;
                }
                else
                {
                    cout<<"No"<<endl;
                }
            }
        }
    }
    return 0;
}
