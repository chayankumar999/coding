#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
vector< pair<int, pair<int, int> > >p;
vector<int>v[1001];
ll cost[1001][1001];
ll bos[10001];
ll F_boss(ll a)
{
    if(bos[a]==a)
    {
        return a;
    }
    else
    {
        return bos[a]=F_boss(bos[a]);
    }
}
void mst()
{
    ll i;
    for(i=0; i<m; i++)
    {
        ll c=p[i].first;
        ll a=p[i].second.first;
        ll b=p[i].second.second;
        ll x=F_boss(a);
        ll y=F_boss(b);
        //cout<<x<<" "<<y<<endl;
        if(x!=y)
        {
            v[a].push_back(b);
            v[a].push_back(c);
            v[b].push_back(a);
            v[b].push_back(c);
            bos[x]=y;
            cost[a][b]=c;
            cost[b][a]=c;
        }
    }
}
int main()
{
    ll a,b,c,i,j;
    cin>>n>>m;
    for(i=0; i<m; i++)
    {
        cin>>a>>b>>c;
        p.push_back(make_pair(c,make_pair(a,b)));
    }
    sort(p.begin(),p.end());
    for(i=1; i<=n; i++)
    {
        bos[i]=i;
    }
    mst();

    return 0;
}
