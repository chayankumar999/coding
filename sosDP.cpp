// Special pairs // hackerearth
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int MX=1500005;
const ll mod=1e9;
const ll inf=1e18;
#define FasterIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
int d[MX],dp[MX][22],f[MX];
int main()
{

    FasterIO;
    int i,j,k,n,m,x,y,tc;
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>d[i];
            f[d[i]]++;
        }
        for(int msk=0;msk<(1LL<<20);msk++) // dp calculation part
        {
            dp[msk][0]=f[msk];
            if(msk&1)dp[msk][0]+=f[msk^1];
            for(i=1;i<=20;i++)
            {
                dp[msk][i]=dp[msk][i-1];
                if(msk&(1LL<<i))
                    dp[msk][i]+=dp[msk^(1LL<<i)][i-1];
            }
        }

        /*
         dp[mask][20] contains value of all subset (let call x be a subset of mask)
         for which mask&x==x
        */
        int ans=0;
        for(i=0;i<n;i++) // result calculation part
        {
            ans+=dp[(1LL<<20)-1-d[i]][20];
            /*((1<<20)-1)-d[i] || ((1<<20)-1)^d[i] is given such a mask value
            which contain a position 1 for which position d[i] contain 0*/
            /*dp[(1LL<<20)-1-d[i]][20] contains value of all subset
            (let call x be a subset of mask 1<<20-1) for which x&d[i]==0*/
            f[d[i]]=0;
        }
        cout<<ans<<endl;
    }
    return 0;
}
