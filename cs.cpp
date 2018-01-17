#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll id1[1000],tak[10000],n;
void bacK(ll id)
{
    ll i;
    if(id==n+1)
    {
        for(i=1;i<=n;i++)
        {
            cout<<id1[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(tak[i]==0)
        {
            tak[i]=1;
            id1[id]=i;
            bacK(id+1);
            tak[i]=0;
        }
    }
}
int main()
{
    ll i,j,k,l;
    cin>>n;
    bacK(1);
    return 0;
}
