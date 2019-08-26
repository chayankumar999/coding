#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mxx 123456789994;
ll n;

int T[MX];
void up(int p, int l, int h, int x, int vl)
{
    if(l==h)
    {
        T[p]=vl; return;
    }
    int m=(l+h)/2;
    if(x<=m) up(2*p, l, m, x, vl);
    else     up(2*p+1, m+1, h, x, vl);
    T[p]=max(T[2*p],T[2*p+1]);
}
int Q(int cr, int p, int l, int h, int x, int y)
{
    if(l>y || h<x)   return -INT_MAX;
    if(l>=x && h<=y) return T[p];
    int m=(l+h)/2;
    return max(Q(2*p, l, m, x, y),Q(2*p+1, m+1, h, x, y));
}

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
