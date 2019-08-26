#include<bits/stdc++.h>
using namespace std;
#define MX 1000000

int T[4*MX], a[MX];

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

int Q(int p, int l, int h, int x, int y)
{
    if(l>y || h<x)   return -INT_MAX;
    if(l>=x && h<=y) return T[p];
    int m=(l+h)/2;
    return max(Q(2*p, l, m, x, y),Q(2*p+1, m+1, h, x, y));
}

void B(int l, int h, int p)
{
    if(l==h)
    {
        T[p]=a[l]; return;
    }
    int m=(l+h)/2;
    B(2*p, l, m);
    B(2*p+1, m+1, h);
    T[p]=max(T[2*p], T[2*p+1]);
}
int main()
{
    int n=10;

    B(1, 1, n);

    up(1, 1, n, x, vl);

    int mx=Q(1, 1, n, 1, n);

    cout<<mx<<endl;
    return 0;
}
