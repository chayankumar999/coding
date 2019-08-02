/*
********* Knuth Optimization of dp *********
Original Recurrence: dp[i][j] = mini < k < j{dp[i][k] + dp[k][j]} + C[i][j]
Sufficient Condition of Applicability: A[i, j - 1] ≤ A[i, j] ≤ A[i + 1, j]
Knuth Optimization is applicable if C[i][j] satisfies the following 2 conditions:
~quadrangle inequality:  C[a][c]+C[b][d]<=C[a][d]+C[b][c], a<=b<=c<=d
~monotonicity:           C[b][c]<=C[a][d],                 a<=b<=c<=d
*/

// https://www.spoj.com/problems/BRKSTRNG/


#include<bits/stdc++.h>
using namespace std;
#define FasterIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int MX=1000+5;
typedef long long ll;

int dp[MX][MX],knuths[MX][MX],cuts[MX];
int n,m;
void solve()
{
    for(int l=0; l<=m; l++)  // for l cuts where 0<=l<=m
    {
        for(int i=0, j=l+1; j<=m+1; i++, j++) // i=left cut, j=right cut
        {
            if(l==0)
            {
                dp[i][j]=0;
                knuths[i][j]=j;
            }
            else
            {
                dp[i][j]=INT_MAX;
                int cost=cuts[j]-cuts[i];
                for(int k=knuths[i][j-1]; k<=knuths[i+1][j]; k++) // k=intermediate cut between i to j
                {
                    if(dp[i][k]+dp[k][j]+cost < dp[i][j])
                    {
                        dp[i][j]=dp[i][k]+dp[k][j]+cost;
                        knuths[i][j]=k;
                    }
                }
            }
        }
    }
}
int main()
{
    FasterIO;
    while(cin>>n)
    {
        cin>>m;
        cuts[0]=0; cuts[m+1]=n;
        for(int i=1; i<=m; i++)
        {
            cin>>cuts[i];
        }
        solve();
        cout<<dp[0][m+1]<<endl;
    }
    return 0;
}

