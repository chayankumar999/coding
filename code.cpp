#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define mk make_pair
#define pb push_back
int n,i,j,k,q,a[100005],ans[200005],cnt,nm;
int mp[1000005];
struct st
{
    int x,y,id,sz;
}arr[200005];
bool comp(st r, st s)
{
    if(r.sz<s.sz)
    {
        return true;
    }
    else if(r.sz==s.sz)
    {
        return r.y<s.y;
    }
    return false;
}
int main()
{
    //////////////////////////////////////////////////////////
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    //////////////////////////////////////////////////////////
    scanf("%d",&n);
    //cin>>n;
    for(i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        //cin>>a[i];
    }
    k=sqrt(n);
    //cin>>q;
    scanf("%d",&q);
    for(i=1; i<=q; i++)
    {
        scanf("%d%d",&arr[i].x,&arr[i].y);
        //cin>>arr[i].x>>arr[i].y;
        arr[i].sz=arr[i].x/k;
        arr[i].id=i;
    }
    sort(arr+1,arr+q+1,comp);
    int L,R,id;
    int lft=0,rgt=0;
    for(i=1; i<=q; i++)
    {
        L=arr[i].x;
        R=arr[i].y;
        id=arr[i].id;
        while(lft<L)
        {
            mp[a[lft]]--;
            if(mp[a[lft]]==0)
            {
                cnt--;
            }
            lft++;
        }
        while(lft>L)
        {
            lft--;
            mp[a[lft]]++;
            if(mp[a[lft]]==1)
            {
                cnt++;
            }
        }
        while(rgt<=R)
        {
            mp[a[rgt]]++;
            if(mp[a[rgt]]==1)
            {
                cnt++;
            }
            rgt++;
        }
        while(rgt-1>R)
        {
            rgt--;
            mp[a[rgt]]--;
            if(mp[a[rgt]]==0)
            {
                cnt--;
            }
        }
        ans[id]=cnt;
    }
    for(i=1; i<=q; i++)
    {
        printf("%d\n",ans[i]);
        //cout<<ans[i]<<endl;
    }
    return 0;
}
/*
bool operator<(const st &z)const
    {
        if(sz<z.sz)
        {
            return true;
        }
        else if(sz==z.sz)
        {
            if(y<z.y)
            {
                return true;
            }
            else if(y==z.y)
            {
                return (x<z.x);
            }
        }
        return false;
    }
    */
