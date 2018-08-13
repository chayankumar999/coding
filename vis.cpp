#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MX 100005
#define pb push_back
#define ff first
#define ss second
#define mk make_pair
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
set<int>st[MX];
set<int>::iterator it;
int p[MX],rs[MX];
int main()
{
    int i,j,k,x,y,z,n,m,tst,a,b;
    while(sc2(n,m)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            p[i]=rs[i]=i;
            st[i].clear();
            st[i].insert(i);
        }
        while(m--)
        {
            sc(tst);
            if(tst==1)
            {
                sc2(x,y);
                a=p[x];
                b=p[y];
                if(st[a].size()<st[b].size())
                {
                    swap(a,b);
                }
                if(a!=b)
                {
                    for(it=st[b].begin();it!=st[b].end();it++)
                    {
                        p[*it]=a;
                        rs[a]+=*it;
                        st[a].insert(*it);
                    }
                }
            }
            else if(tst==2)
            {
                sc2(x,y);
                a=p[x];
                b=p[y];
                if(a!=b)
                {
                    p[x]=b;
                    rs[a]-=x;
                    rs[b]+=x;
                    st[a].erase(x);
                    st[b].insert(x);
                }
            }
            else
            {
                sc(x);
                a=p[x];
                printf("%d %d\n",st[a].size(),rs[a]);
            }
        }
    }
    return 0;
}
