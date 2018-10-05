#include <bits/stdc++.h>
using namespace std;
#define FasterIO ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define ff first
#define ss second
#define pb push_back
#define mk make_pair

typedef long long ll;
typedef double db;
typedef queue<int> qq;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<pii> vii;

#define sc scanf
#define pf1 printf
#define sc1(x) scanf("%d", &x)
#define sc2(x, y) scanf("%d %d", &x, &y)
#define sc3(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define mem(a) memset(a,0,sizeof(a))
#define mems(a) memset(a,-1,sizeof(a))
#define inf 2e9
#define MOD 23102009
#define MX 1006
#define MX_LG 20
int a[MX][MX];
int sp[MX_LG][MX][MX_LG][MX];
int sum[MX][MX];
int n,m;
// n= row, m=column,a[][]=initial matrix, sum[][]=submatrix sum,
// sp[][][][]=sperse table for submatrix query
void build2DSperseTable()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            sp[0][i][0][j]=a[i][j];
        for(int y=1; (1<<y)<=m; y++)
            for(int j=1; j+(1<<y)-1<=m; j++)
                sp[0][i][y][j]=max(sp[0][i][y-1][j],sp[0][i][y-1][j+(1<<(y-1))]);
    }

    for(int x=1; (1<<x)<=n; x++)
        for(int i=1; i+(1<<x)-1<=n; i++)
            for(int y=0; (1<<y)<=m; y++)
                for(int j=1; j+(1<<y)-1<=m; j++)
                    sp[x][i][y][j]=max(sp[x-1][i][y][j],
                                       sp[x-1][i+(1<<(x-1))][y][j]);
}
int RMQ_MN_MX(int x, int y, int x1, int y1)
{
    int kx=log2(x1-x+1);
    int ky=log2(y1-y+1);
    int tmp1=max(sp[kx][x][ky][y],sp[kx][x][ky][y1-(1<<ky)+1]);
    int tmp2=max(sp[kx][x1-(1<<kx)+1][ky][y],
                 sp[kx][x1-(1<<kx)+1][ky][y1-(1<<ky)+1]);
    return max(tmp1,tmp2);
}
void cal_subSum()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            sum[i][j]+=sum[i][j-1]+a[i][j];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            sum[i][j]+=sum[i-1][j];
}
int subMatrixSum(int x, int y, int x1, int y1)
{
    return sum[x1][y1]+sum[x-1][y-1]-sum[x1][y-1]-sum[x-1][y1];
}
int main()
{
    FasterIO;
    /////////////////////
    int i,j,k,x,y,cs=1,q;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    cal_subSum();
    build2DSperseTable();
    cin>>q;
    while(q--)
    {
        cin>>x>>y;
        int res=inf;
        for(i=1;i<=n-x+1;i++)
        {
            for(j=1;j<=m-y+1;j++)
            {
                int rq=x*y*RMQ_MN_MX(i,j,i+x-1,j+y-1);
                rq-=subMatrixSum(i,j,i+x-1,j+y-1);
                res=min(res,rq);
            }
        }
        cout<<res<<endl;
    }
    return 0;
}

