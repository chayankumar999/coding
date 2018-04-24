#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lg(x) 32-__builtin_clz(x)-1
#define pb push_back
#define mk make_pair
const int N = 1e5 + 100;
ll l[N],n,c;
ll sp[10001][101];
ll cost[10001];
vector< pair<ll, ll> >v[10001];
void dfs(ll a, ll p)
{
    sp[a][0]=p;
    l[a]=l[p]+1;
    ll sz=v[a].size();
    for(ll i=0; i<sz; i++)
    {
        ll b=v[a][i].first;
        if(b!=p)
        {
            cost[b]=v[a][i].second+cost[a];
            dfs(b,a);
        }
    }
}
void sperse_table()
{
    ll i,j;
    for(j=1; j<=lg(n); j++)
    {
        for(i=2; i<=n; i++)
        {
            if(sp[i][j-1]!=-1)
            {
                sp[i][j]=sp[sp[i][j-1]][j-1];
            }
        }
    }
}
ll ansestor(ll a, ll b)
{
    ll p,i;
    if(l[a]<l[b])
    {
        swap(a,b);
    }
    ll dist = l[a] - l[b] ;
    for(int i=18; i>=0; i--)
    {
        int x= (1<<(i));
        if(x<=dist)
        {
            a= sp[a][i];
            dist-= x;
        }
    }
    if(a==b)
    {
        return a;
    }
    for(i=lg(n); i>=0; i--)
    {
        if(sp[a][i]!=sp[b][i]&&sp[a][i]!=-1)
        {
            a=sp[a][i];
            b=sp[b][i];
        }
    }
    return sp[a][0];
}
int main()
{
    ll tc,i,j,a,b,c,k;
    string s;
    cin>>tc;
    while(tc--)
    {
        memset(sp,-1,sizeof(sp));
        memset(cost,0,sizeof(cost));
        memset(l,0,sizeof(l));
        cin>>n;
        for(i=1; i<n; i++)
        {
            cin>>a>>b>>c;
            v[a].pb(mk(b,c));
            v[b].pb(mk(a,c));
        }
        dfs(1,-1);
        sperse_table();

        while(cin>>s)
        {
            if(s=="DONE")
            {
                break;
            }
            if(s=="DIST")
            {
                cin>>a>>b;
                ll r=ansestor(a,b);
                ll cst=cost[a]+cost[b]-2*cost[r];
                cout<<cst<<endl;
            }
            else
            {
                cin>>a>>b>>k;
                ll l2,d,p;
                ll r=ansestor(a,b);
                if(l[a]-l[r]==0)
                {
                    d=l[b]-l[r]+1;
                    d=d-k;
                    for(int i=lg(n); i>=0; i--)
                    {
                        if(d&(1<<i))
                        {
                            b=sp[b][i];
                        }
                    }
                    cout<<b<<endl;
                }
                else if(l[b]-l[r]==0)
                {
                    k--;
                    for(int i=lg(n); i>=0; i--)
                    {
                        if(k&(1<<i))
                        {
                            a=sp[a][i];
                        }
                    }
                    cout<<a<<endl;
                }
                else
                {
                    d=l[a]-l[r]+1;
                    if(k<=d)
                    {
                        k--;
                        for(int i=lg(n); i>=0; i--)
                        {
                            if(k&(1<<i))
                            {
                                a=sp[a][i];
                            }
                        }
                        cout<<a<<endl;
                    }
                    else
                    {
                        k-=d;
                        k=(l[b]-l[r])-k;
                        for(int i=lg(n); i>=0; i--)
                        {
                            if(k&(1<<i))
                            {
                                b=sp[b][i];
                            }
                        }
                        cout<<b<<endl;
                    }
                }
            }
        }
        cout<<endl;
        for(i=1; i<=n; i++)
        {
            v[i].clear();
        }
    }
    return 0;
}

/*
2
15
1 2 2
1 3 3
2 4 4
2 5 5
3 6 6
3 7 7
5 8 8
5 9 9
6 10 10
6 11 11
9 12 12
9 13 13
11 14 14
11 15 15
DIST 1 15
KTH 1 15 3
DIST 12 15

ans::

35
6
63
*/
