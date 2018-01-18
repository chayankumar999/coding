#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
ll a[100005],b[100005];
ll i,j,k,x,y,n,m,t=1,tc;
void calculation()
{
    k=sqrt(n);
    if(k*k<n)
    {
        k++;
    }
    if(n%k!=0)
    {
        for(i=(n/k)*k+n%k; i<(n/k+1)*k; i++)
        {
            a[i]=123456789;
        }
    }
    for(i=0; i<k; i++)
    {
        ll mnm=123456789;
        for(j=k*i; j<k*(i+1); j++)
        {
            mnm=min(mnm,a[j]);
        }
        b[i]=mnm;
    }
}
int main()
{
    cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
        for(i=0; i<n; i++)
        {
            cin>>a[i];
        }
        calculation();
        cout<<"Case "<<t++<<":"<<endl;
        ll mnm=123456789;
        for(i=0; i<m; i++)
        {
            cin>>x>>y;
            x--;
            y--;
            if(x/k==y/k)
            {
                mnm=123456789;
                for(j=x; j<=y; j++)
                {
                    mnm=min(mnm,a[j]);
                }
            }
            else
            {
                mnm=123456789;
                for(j=x/k+1; j<y/k; j++)
                {
                    mnm=min(mnm,b[j]);
                }
                for(j=(x/k+1)*k+x%k; j<(x/k+2)*k; j++)
                {
                    mnm=min(mnm,a[j]);
                }
                for(j=(y/k)*k; j<=y; j++)
                {
                    mnm=min(mnm,a[j]);
                }
            }
            cout<<mnm<<endl;
        }
    }
    return 0;
}
