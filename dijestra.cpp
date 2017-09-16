#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define ull unsigned long long
#define mx 1000007
#define inf 1000007
vector<int>v[501];
priority_queue< pair< int, int > >pq;
ll cost[501];
ll n,m,i,j,c;
void mem()
{
    for(i=1;i<=n;i++)
    {
        cost[i]=inf;
    }
}
void dijestra(ll p)
{
    pq.push(make_pair(0,p));
    cost[p]=0;
    while(!pq.empty())
    {
        ll s=pq.top().second;
        pq.pop();
        ll sz=v[s].size();
        for(i=0;i<sz;i+=2)
        {
            ll c=v[s][i];
            ll adj=v[s][i+1];
            if(cost[adj]>cost[s]+c)
            {
                cost[adj]=cost[s]+c;
                pq.push(make_pair(c,adj));
            }
        }
    }
}
int main()
{
    ll c,x,y;
    cin>>n>>m;
    mem();
    for(i=0;i<m;i++)
    {
        cin>>c>>x>>y;
        v[x].push_back(c);
        v[x].push_back(y);
        v[y].push_back(c);
        v[y].push_back(x);
    }
    dijestra(1);
    cout<<cost[n]<<endl;
    return 0;
}
/*
8 11
2 1 3
3 1 2
5 2 3
6 2 5
1 3 4
4 4 5
7 4 7
10 4 6
4 4 8
9 6 8
8 7 8
*/
