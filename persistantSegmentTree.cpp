//Spoj De-Query

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define MX 1000005
#define sc(a) scanf("%d",&a)
struct node
{
    int lft,rgt,v;
    node()
    {
        lft=rgt=v=0;
    }
};
node T[MX];
int root[MX];
int av,b[10*MX];
void update(int pre, int cur, int lw, int hg, int id, int vv)
{
    if(lw==hg)
    {
        T[cur].v=T[pre].v+vv;
        return;
    }
    int md=(lw+hg)/2;
    if(id<=md)
    {
        if(!T[cur].lft)
        {
            T[cur].lft=++av;
        }
        T[cur].rgt=T[pre].rgt;
        update(T[pre].lft,T[cur].lft,lw,md,id,vv);
    }
    else
    {
        T[cur].lft=T[pre].lft;
        if(!T[cur].rgt)
        {
            T[cur].rgt=++av;
        }
        update(T[pre].rgt,T[cur].rgt,md+1,hg,id,vv);
    }
    T[cur].v=T[T[cur].lft].v+T[T[cur].rgt].v;
}
int query(int cur, int lw, int hg, int l, int r)
{
    if(l>hg||r<lw)
    {
        return 0;
    }
    if(l<=lw&&r>=hg)
    {
        return T[cur].v;
    }
    int md=(lw+hg)/2;
    int p1=query(T[cur].lft,lw,md,l,r);
    int p2=query(T[cur].rgt,md+1,hg,l,r);
    return p1+p2;
}
int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    ///////////////////////////////////
    int n,i,j,k,q,x,y;
    sc(n);
    for(i=1; i<=n; i++)
    {
        sc(x);
        root[i]=++av;
        if(b[x])
        {
            update(root[i-1],root[i],1,n,b[x],-1);
            update(root[i],root[i],1,n,i,1);
        }
        else
        {
            update(root[i-1],root[i],1,n,i,1);
        }
        b[x]=i;
    }
    sc(q);
    while(q--)
    {
        sc(x);sc(y);
        int ans=query(root[y],1,n,x,y);
        printf("%d\n",ans);
    }
    return 0;
}
