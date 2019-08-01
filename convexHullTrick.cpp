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



///Online update and online query
///everything is fine as long as you want the minimum/maximum

///https://codeforces.com/problemset/problem/1083/E

#include<bits/stdc++.h>
using namespace std;
#define FasterIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
typedef long double float128;
const ll is_query = -(1LL<<62), inf = 1e18;
struct Line
{
    ll m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const
    {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s)  return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};

struct HullDynamic : public multiset<Line> // // will maintain lower hull for minimum/maximum
{
    bool bad(iterator y)
    {
        auto z = next(y);
        if (y == begin())
        {
            if (z == end())       return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return (float128)(x->b - y->b)*(z->m - y->m) >= (float128)(y->b - z->b)*(y->m - x->m);
    }
    void add_line(ll m, ll b)
    {
        //auto y = insert({ -m, -b });   // For minimum
        auto y = insert({ m, b });       // For maximum
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y))
        {
            erase(y); return;
        }
        while (next(y) != end() && bad(next(y)))    erase(next(y));
        while (y != begin() && bad(prev(y)))        erase(prev(y));
    }

    ll getbest(ll x)
    {
        auto l = *lower_bound((Line)
        {
            x, is_query
        });
        //return -(l.m * x + l.b);  // For minimum
        return (l.m * x + l.b);     // For maximum
    }
} st;

const int MX=2000000;
ll x[MX],y[MX],a[MX],dp[MX];
vector<pair<pair<ll,ll>, ll> >v;
int main()
{
    FasterIO;
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        ll x,y,a;
        cin>>x>>y>>a;
        v.push_back({{x,y},a});
    }
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++)
    {
        x[i]=v[i].first.first;
        y[i]=v[i].first.second;
        a[i]=v[i].second;
        a[i]=x[i]*y[i]-a[i];
    }
    st.add_line(0,0);
    for(int i=0; i<n; i++)
    {
        dp[i]=st.getbest(y[i])+a[i];
        st.add_line(-x[i],dp[i]);
    }
    ll ans=0;
    for(int i=0; i<n; i++)
    {
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}
