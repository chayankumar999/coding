/*
    *****Convex Hull Trick*****
    problem: codeforces/319/C
    description: given height of n trees a[i] and cost of charging chain saw b[i]. you have to cut n trees with minimum cost, a[1]=1 and b[n]=0;
    each time u can cut one unit of the height of a tree by saw. and u can charged saw by b[i] where the ith tree where we already cut tree i;
    the saw is initialy charged.
    idea:    if somehow we can cut the nth tree after that all the remaining tree can be cut with free cost as b[n]=0; for ith tree the minimum
    cost will be f[i]=f[j]+a[i]*b[j] , the cost for cutting the nth tree will be the final answer.
*/

#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

typedef long long ll;
typedef pair<ll,ll> pL;

const int MX=200000;

double intersect(pL a, pL b)
{
    return (b.ss-a.ss+0.0)/(a.ff-b.ff);
}
//void insert(pL candidate, pL *st, double *interP, int &top)
//{
//    while(top>0 && intersect(st[top-1],st[top])>= intersect(st[top-1],candidate)) top--;
//    st[++top]=candidate;
//    interP[top]=intersect(st[top-1],candidate);
//}
//ll Q(ll x, pL *st, double *interP, int top)
//{
//    int up=upper_bound(interP+1,interP+top+1,x)-interP-1;
//    return st[up].ff*(x)+st[up].ss;
//}
//void init(pL candidate, double base, pL *st, double *interP, int &top)
//{
//    top=0;
//    st[0]=candidate;
//    interP[0]=base;
//}
ll a[MX],b[MX];
double interP[MX];
pL st[MX];

int main()
{
    int n,top;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    top=0;         st[0]={b[1],0};  //initialize
    interP[0]=0;   ll ans=0;
    // we assume tree height a[i] as x, b[i] as m and ans as c for line equation y=mx+c
    // line 57-59 is insertion, 54-55 query
    for(int i=2;i<=n;i++)
    {
        int up=upper_bound(interP+1,interP+top+1,a[i])-interP-1;
        ans=st[up].ff*a[i]+st[up].ss;
        pL candidate={b[i],ans};
        while(top>0 && intersect(st[top-1],st[top])>= intersect(st[top-1],candidate)) top--;
        st[++top]=candidate;
        interP[top]=intersect(st[top-1],candidate);
    }
    cout<<ans<<endl;
    return 0;
}
