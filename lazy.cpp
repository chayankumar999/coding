#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(a) memset(a,0,sizeof(a))
#define mx 1000000005
ll T[500005],lazy[500005];
void propagate(int p, int l, int h)
{
    T[p]+=(h-l+1)*lazy[p];
    if(l!=h)
    {
        lazy[2*p]+=lazy[p];
        lazy[2*p+1]+=lazy[p];
    }
    lazy[p]=0;
}
void up(int p, int l, int h, int x, int y, ll vl)
{
    if(lazy[p]!=0) propagate(p, l, h);
    if(x>h || y<l) return;
    if(l>=x && h<=y)
    {
        T[p]+=(h-l+1)*vl;
        if(l!=h)
        {
            lazy[2*p+1]+=vl;
            lazy[2*p+2]+=vl;
        }
        return;
    }
    int m=(l+h)/2;
    up(2*p, l, m, x, y, vl);
    up(2*p+1, m+1, h, x, y, vl);
    T[p]=T[2*p]+T[2*p+1];
}
long long Q(int p, int l, int h, int x, int y)
{
    if(x>h || y<l)   return 0;
    if(lazy[p]!=0)   propagate(p, l, h);
    if(l>=x && h<=y) return T[p];
    int m=(l+h)/2;
    return Q(2*p, l, m, x, y)+Q(2*p+1, m+1, h, x, y);
}
//void B(int p, int l, int h)
//{
//    if(l==h)
//    {
//        T[p]=a[l]; return;
//    }
//    int m=(l+h)/2;
//    B(p,l,m);
//    B(p,m+1,h);
//    T[p]=T[2*p]+T[2*p+1];
//}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    /////////////////////////////////////////
    ll tc,n,m,x,y,t,p,v,i,j;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
        for(i=0;i<m;i++)
        {
            cin>>p;
            if(p==0)
            {
                cin>>x>>y>>v;
                up(1,1,n,x,y,v);
            }
            else if(p==1)
            {
                cin>>x>>y;
                cout<<Q(1,1,n,x,y)<<endl;
            }
        }
        mem(lazy);
        mem(tree);
    }
    return 0;
}
