#include<bits/stdc++.h>
using namespace std;
#define inf 9876543210
#define ll long long
ll a[10001],a1[10002],a2[10001],a3[10001];
void mem()
{
    a1[0]=-inf;
    int i=1;
    for(i=1; i<1000; i++)
    {
        a1[i]=inf;
    }
}
int main()
{
    ll tc,i,j,k,l,x,n,m,h;
    string s;
    cin>>tc;
    getchar();
    while(tc--)
    {
        mem();
        getline(cin,s);
        x=0;
        j=0;
        if(s.size()!=0)
        {
            for(i=0; i<s.size(); i++)
            {
                x=x*10+s[i]-48;
            }
            a[j++]=x;
        }
        while(getline(cin,s)&&s.size()!=0)
        {
            x=0;
            for(i=0; i<s.size(); i++)
            {
                x=x*10+s[i]-48;
            }
            a[j++]=x;
        }
        n=j;
        ll mxx=0;
        for(i=0; i<n; i++)
        {
            x=a[i];
            l=0;
            h=i+1;
            while(l<=h)
            {
                m=(l+h)/2;
                if(a1[m]==x)
                {
                    l=m;
                    break;
                }
                else if(a1[m]>x)
                {
                    h=m-1;
                }
                else
                {
                    l=m+1;
                }
            }
            a1[l]=x;
            a2[i]=l;
            if(mxx<l)
            {
                mxx=l;
            }
        }
        cout<<"Max hits: "<<mxx<<endl;
        i=0;
        for(j=n-1; j>=0; j--)
        {
            if(a2[j]==mxx)
            {
                a3[i++]=a[j];
                mxx--;
            }
            if(mxx==0)
            {
                break;
            }
        }
        for(j=i-1; j>=0; j--)
        {
            cout<<a3[j]<<endl;
        }
        if(tc>0)
        {
            cout<<endl;
        }
    }
    return 0;
}
