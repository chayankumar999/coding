#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(a) memset(a,0,sizeof(a))
#define mx 1000000005
ll tree[500005],lazy[500005];
void update(ll pos, ll lw, ll hg, ll x, ll y, ll v)
{
    if(lazy[pos]!=0)
    {
        tree[pos]+=(hg-lw+1)*lazy[pos];
        if(lw!=hg)
        {
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    if(x>hg || y<lw)
    {
        return;
    }
    if(lw>=x && hg<=y)
    {
        tree[pos]+=(hg-lw+1)*v;
        if(lw!=hg)
        {
            lazy[2*pos+1]+=v;
            lazy[2*pos+2]+=v;
        }
        return;
    }
    ll md=(lw+hg)/2;
    update(2*pos+1, lw, md, x, y, v);
    update(2*pos+2, md+1, hg, x, y, v);
    tree[pos]=tree[2*pos+1]+tree[2*pos+2];
}
ll query(ll pos, ll lw, ll hg, ll x, ll y)
{
    if(x>hg || y<lw)
    {
        return 0;
    }
    if(lazy[pos]!=0)
    {
        tree[pos]+=(hg-lw+1)*lazy[pos];
        if(lw!=hg)
        {
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    if(lw>=x && hg<=y)
    {
        return tree[pos];
    }
    ll md=(lw+hg)/2;
    ll p=query(2*pos+1, lw, md, x, y);
    ll q=query(2*pos+2, md+1, hg, x, y);
    return p+q;
}
//void build(ll pos, ll lw, ll hg)
//{
//    if(lw==hg)
//    {
//        tree[pos]=a[lw];
//        return;
//    }
//    ll md=(lw+hg)/2;
//    build(pos,lw,md);
//    build(pos,md+1,hg);
//    tree[pos]=tree[2*pos+1]+tree[2*pos+2];
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
                update(0,0,n-1,--x,--y,v);
            }
            else if(p==1)
            {
                cin>>x>>y;
                cout<<query(0,0,n-1,--x,--y)<<endl;
            }
        }
        mem(lazy);
        mem(tree);
    }
    return 0;
}
