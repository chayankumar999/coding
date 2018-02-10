#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define mk make_pair
ll mxx=100000007;
ll seg[1000005];
ll a[200005],n,gv;
void Set()
{
    for(int i=0; i<4*n; i++)
    {
        seg[i]=0;
    }
}
void construct(ll low, ll high, ll pos)
{
    if(low==high)
    {
        seg[pos]=a[low];
        return;
    }
    ll md=(low+high)/2;
    construct(low,md,2*pos+1);
    construct(md+1,high,2*pos+2);
    seg[pos]=seg[2*pos+1]+seg[2*pos+2];
}
ll query(ll x, ll y, ll low, ll high, ll pos)
{
    if(x<=low&&y>=high)
    {
        return seg[pos];
    }
    else if(x>high||y<low)
    {
        return 0;
    }
    ll md=(low+high)/2;
    return query(x,y,low,md,2*pos+1)+query(x,y,md+1,high,2*pos+2);
}
void update(ll low, ll high, ll x, ll y,ll pos)
{
    if(low==high&&low==x)
    {
        gv=seg[pos];
        seg[pos]+=y;
        return;
    }
    ll md=(low+high)/2;
    if(x<=md)
    {
        ll d=seg[pos]-seg[2*pos+1];
        update(low,md,x,y,2*pos+1);
        ll d1=seg[pos]-seg[2*pos+1];
        seg[pos]+=d-d1;
    }
    else
    {
        ll d=seg[pos]-seg[2*pos+2];
        update(md+1,high,x,y,2*pos+2);
        ll d1=seg[pos]-seg[2*pos+2];
        seg[pos]+=d-d1;
    }
}
int main()
{
    ///////////////////////////////////////////////////
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ///////////////////////////////////////////////////
    ll i,j,k,x,y,q,r,p,val,t=1,tc;
    scanf("%lld",&tc);
    while(tc--)
    {
        Set();
        //cin>>n>>q;
        scanf("%lld%lld",&n,&q);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        construct(0,n-1,0);
        printf("Case %lld:\n",t++);
        for(i=0;i<q;i++)
        {
            scanf("%lld",&p);
            if(p==1)
            {
                scanf("%lld",&x);
                y=-a[x];
                a[x]=0;
                gv=0;
                update(0,n-1,x,y,0);
                printf("%lld\n",gv);}
            else if(p==2)
            {
                scanf("%lld%lld",&x,&y);
                a[x]+=y;
                update(0,n-1,x,y,0);
            }
            else
            {
                scanf("%lld%lld",&x,&y);
                r=query(x,y,0,n-1,0);
                printf("%lld\n",r);
            }
        }
    }
    return 0;
}
