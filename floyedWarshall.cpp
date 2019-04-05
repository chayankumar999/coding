#include<bits/stdc++.h>
using namespace std;
#define FasterIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;
typedef double db;

#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vL vector<ll>
#define pi pair<int,int>
#define pL pair<ll,ll>
#define pii pair<int,pi>
#define pLL pair<ll,pL>
#define vp vector<pi>

const int MX=505;
const int mod=1e9+7;
const int inf=1e9;

ll dist[MX][MX];

void floydWarshall (int n)
{
    for(int k=1; k<=n; k++)
    {
        // Pick all vertices as source one by one
        for (int i = 1; i <= n; i++)
        {
            // Pick all vertices as destination for the
            // above picked source
            for (int j = 1; j <= n; j++)
            {
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                if(dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main()
{
    FasterIO;
    int i,j,k,n,x;
    cin>>n;
    for(i=1; i <= n; i++)
    {
        for(j=1; j <= n; j++)
        {
            cin>>dist[i][j];
        }
    }
    floydWarshall(n);
    return 0;
}
