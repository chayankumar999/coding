/*
    *****Convex Hull Trick*****
    problem: codeforces/319/C
    description: given height of n trees a[i] and cost of charging chain saw b[i]. you have to cut n trees with minimum cost, a[1]=1 and b[n]=0;
    each time u can cut one unit of the height of a tree by saw. and u can charged saw by b[i] where the ith tree where we already cut tree i;
    the saw is initialy charged.
    idea:    if somehow we can cut the nth tree after that all the remaining tree can be cut with free cost as b[n]=0; for ith tree the minimum
    cost will be f[i]=f[j]+a[i]*b[j] , the cost for cutting the nth tree will be the final answer.
*/

//min query increasing slope
//or max query decreasing slope

#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

typedef long long ll;
typedef pair<ll,ll> pL;

const int MX=200000;
const ll inf=1e9;
double interP[MX];     //intersection point of corresponding line
pL st[MX];             //lines will be stored here in sorted order
int top;

double intersect(pL a, pL b)
{
    return (b.ss-a.ss+0.0)/(a.ff-b.ff);
}
void insert(pL candidate)
{
    while(top>0 && intersect(st[top-1],st[top])>= intersect(st[top-1],candidate)) top--;
    st[++top]=candidate;
    interP[top]=intersect(st[top-1],candidate);
}
ll Q(ll x)
{
    int up=upper_bound(interP+1,interP+top+1,x)-interP-1;
    return st[up].ff*(x)+st[up].ss;
}

//for minimam candidate = {inf,0}, for maximum candidate = {-inf,0}

void init(pL candidate={inf,0}, double base = -inf)
{
    top=0;
    st[0]=candidate;
    interP[0]=base;
    insert({0,0});    //inserting {0,dp[0]}
}
ll a[MX],b[MX];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    ll ans=0;
    init();             //Initial set up
    //y = m * x + c, for insert send {m,c}
    for(int i=1;i<=n;i++)
    {
        ans=Q(a[i]);        //query on point a[i]
        insert({b[i],ans}); //insert {b[i],dp[i]}
    }
    cout<<ans<<endl;        //printing dp[n-1]
    return 0;
}
