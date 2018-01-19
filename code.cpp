#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define mk make_pair
#define pb push_back
ll n,i,j,x,y,k,q,a[100005],ans[100005],cnt;
vector< pair< ll, pair<ll,pair<ll,ll> > > >p;
map<ll,ll>mp;
void add(ll nm)
{
    mp[nm]++;
    if(mp[nm]==1)
    {
        cnt++;
    }
}

void sub(ll nm)
{
    mp[nm]--;
    if(mp[nm]==0)
    {
        cnt--;
    }
}
int main()
{

    cin>>n>>q;
    for(i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    k=sqrt(n);
    if(k*k<n)
    {
        k++;
    }
    for(i=0; i<q; i++)
    {
        cin>>x>>y;
        p.pb(mk((x-1)/k,mk(y,mk(x,i))));
    }
    sort(p.begin(),p.end());
    ll L,R,id;
    ll lft=0,rgt=0;
    for(i=0; i<q; i++)
    {
        L=p[i].second.second.first;
        R=p[i].second.first;
        id=p[i].second.second.second;
        while(lft<L)
        {
            sub(a[lft]);
            lft++;
        }
        while(lft>L)
        {
            lft--;
            add(a[lft]);
        }
        while(rgt<=R)
        {
            add(a[rgt]);
            rgt++;
        }
        while(rgt-1>R)
        {
            rgt--;
            sub(a[rgt]);
        }
        ans[id]=cnt;
    }
    for(i=0;i<q;i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}
/*
10 5
1 2 5 1 9 4 2 1 5 9
1 5
2 4
3 8
1 10
5 9
*/
