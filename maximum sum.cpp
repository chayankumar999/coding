#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100][100],a1[100][100],arr[100][100];
int main()
{
    ll n,i,j,k,r,c;
    while(cin>>n)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                {
                    cin>>a[i][j];
                }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                {
                    a1[i][j]=a[i][j]+a1[i-1][j];
                }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                arr[i][j]=arr[i][j-1]+a1[i][j];
            }
        }
        ll maxx=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                for(k=i-1;k>=0;k--)
                {
                    for(r=j-1;r>=0;r--)
                    {
                        ll x=arr[i][j]+arr[k][r]-arr[k][j]-arr[i][r];
                        if(x>maxx)
                        {
                            maxx=x;
                        }
                    }
                }
            }
        }
        cout<<maxx<<endl;

    }
    return 0;
}

