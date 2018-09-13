#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define MX 100005
struct node
{
    int lft,rgt,v;
    node(){}
};
node T[4*MX];
int root[MX];
int a[MX],av;
void build(int pos, int lw, int hg)
{
    if(lw==hg)
    {
        T[pos].v=a[lw];
        return;
    }
    int md=(lw+hg)/2;
    T[pos].lft=++av;
    T[pos].rgt=++av;
    build(T[pos].lft,lw,md);
    build(T[pos].rgt,md+1,hg);
    T[pos].v=T[T[pos].lft].v+T[T[pos].rgt].v;
}
void upgrade(int pre, int cur, int lw, int hg, int id, int vv)
{
    if(lw==hg)
    {
        T[cur].v=vv;
        return;
    }
    int md=(lw+hg)/2;
    if(id<=md)
    {
        T[cur].lft=++av;
        T[cur].rgt=T[pre].rgt;
        upgrade(T[pre].lft,T[cur].lft,lw,md,id,vv);
    }
    else
    {
        T[cur].lft=T[pre].lft;
        T[cur].rgt=++av;
        upgrade(T[pre].rgt,T[cur].rgt,md+1,hg,id,vv);
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
    int n=5;
    for(int i=1;i<=n;i++)
    {
        a[i-1]=i;
    }
    root[0]=++av;
    build(av,0,n-1);
    root[1]=++av;
    upgrade(root[0],root[1],0,n-1,4,1);
    root[2]=++av;
    upgrade(root[1],root[2],0,n-1,2,10);
    cout << "In version 1 , query(0,4) : ";
    cout << query(root[1], 0, n-1, 0, 4) << endl;

    cout << "In version 2 , query(3,4) : ";
    cout << query(root[2], 0, n-1, 3, 4) << endl;

    cout << "In version 0 , query(0,3) : ";
    cout << query(root[0], 0, n-1, 0, 3) << endl;
    return 0;
}
