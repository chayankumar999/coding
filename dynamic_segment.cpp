#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100005],av=1;
struct node
{
    ll lft,rgt,inf;
    node()
    {

    }
}st[1000005];
void construct(ll pos, ll low, ll high)
{
    if(low==high)
    {
        st[pos].inf=a[low];
        return;
    }
    ll md=(low+high)/2;
    st[pos].lft=++av;
    construct(st[pos].lft,low,md);
    st[pos].rgt=++av;
    construct(st[pos].rgt,md+1,high);

    st[pos].inf=st[st[pos].lft].inf+st[st[pos].rgt].inf;
    //cout<<pos<<" "<<st[pos].inf<<endl;
}
int main()
{
    ll i,j,k,n,m;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    construct(1,0,n-1);
    for(i=0;i<4*n;i++)
    {
        cout<<i<<" "<<st[i].inf<<endl;
    }
    return 0;
}
