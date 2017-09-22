#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mxx 123456789994;
ll n;
ll a[100001],seg[2000001];
void memset()
{
    int i;
    for(i=0; i<4*n; i++)
    {
        seg[i]=mxx;
        // cout<<seg[i]<<endl;
    }
}
ll mnm_in_range(ll x, ll y, ll low, ll high, ll pos)
{
    if(low >= x &&high <= y)
    {
        return seg[pos];
    }
    if(y<low||x>high)
    {
        return mxx;
    }
    ll md=(low+high)/2;
    return min(mnm_in_range(x,y,low,md,2*pos+1),mnm_in_range(x,y,md+1,high,2*pos+2));
}
//void print()
//{
//    for(ll i=0;i<2*n;i++)
//    {
//        cout<<seg[i]<<" ";
//    }
//    cout<<endl;
//}
void construct_tree(ll low, ll high, ll pos)
{
    if(low==high)
    {
        seg[pos]=a[low];
        //cout<<pos<<" "<<low<<" "<<a[low]<<endl;
        return;
    }
    ll md=(low+high)/2;
    construct_tree(low,md,2*pos+1);
    construct_tree(md+1,high,2*pos+2);
    seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
}
int main()
{
    ll m,i,j,x,y,low,high,pos,tc,t=1;
    cin>>tc;
    while(tc--)
    {
        scanf("%lld%lld",&n,&m);
        memset();
        for(i=0; i<n; i++)
        {
            scanf("%lld",&a[i]);
        }
        construct_tree(0,n-1,0);
        //print();
        printf("Case %lld:\n",t++);
        while(m--)
        {
            scanf("%lld%lld",&x,&y);
            ll r=mnm_in_range(x-1,y-1,0,n-1,0);
            printf("%lld\n",r);
        }
    }
    return 0;
}
