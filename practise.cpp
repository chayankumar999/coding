#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define db double
#define pi 2*acos(0.0)
#define MAX 100009
ll sum[MAX],b[MAX],a[MAX];
int main()
{
    ll i,j,k,l,r,n,m,x;
    cin>>n>>m;
    ll sq=sqrt(n);
    for(i=0; i<n; i++)
    {
        cin>>a[i];
        b[i/sq]+=a[i];
    }
    while(m--)
    {
        cin>>l>>r>>x;
        l--;
        r--;
        if(x>0)
        {
            ll lb=l/sq;
            ll rb=r/sq;
            for(i=l; i<sq*(lb+1)&&i<=r; i++)
            {
                b[i/sq]+=x;
                a[i]+=x;
            }
            for(i=rb*sq; i<=r; i++)
            {
                b[i/sq]+=x;
                a[i]+=x;
            }
            for(i=lb+1; i<rb; i++)
            {
                sum[i]+=x;
            }
        }
        else
        {
            ll result=0;
            ll lb=l/sq;
            ll rb=r/sq;
            for(i=l; i<sq*(lb+1)&&i<=r; i++)
            {
                result+=a[i]+sum[i/sq];
            }
            for(i=rb*sq; i<=r; i++)
            {
                result+=a[i]+sum[i/sq];
            }
            for(i=lb+1; i<rb; i++)
            {
                result+=b[i]+sum[i]*sq;
            }
            cout<<result<<endl;
        }
    }
    return 0;
}
