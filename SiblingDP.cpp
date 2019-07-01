/*                        //// Sibling DP\\\\
Let’s say, we are at node u and have m edges to preserve. Now, from u, we can divide m to among
leftmost_child_node and right_sibling. But, we have to handle few things. If we give a part of m
to leftmost_child, it doesn’t mean we have preserved the edge connecting u to leftmost_child. It
 just means we have given opportunity to each child nodes to preserve their corresponding edge
with u. After that let’s say we have gone to leftmost_node, then u will become parent_node and
leftmost_node will become u. From u (previously leftmost_node), we will decide if we are preserving
 the edge connecting to parent_node (previously node u) or not? If we preserve the edge, we can then
 again divide m between leftmost_child and right_sibling. Otherwise we will only send m to right_sibling
 to give other siblings the opportunity to preserve their edge connecting to parent. Here, the catch is
that, if we preserve the edge connecting to u and parent_node, then only we will be able to send
leftmost_child some edges to preserve.
*/
/*
        /// problem Statement \\\///LOJ 1252-Maintaining Communities\\\
u have to spliting the tree in such a way that each connected component maintanance cost does not contain
more than m and number of such component will be as minimum as possible
*/
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
#define mk make_pair
#define pi pair<int,int>
#define vi vector<int>

const int MX=111;
const int mod=1e9+7;
const int inf=1e9;

int n,m;
vi g[MX];
int child[MX],nxt[MX];
int cost[MX][MX],dp[MX][MX];

void findSibling(int x, int p)
{
    int parent,flag=1; // flag for left child
    for(auto u:g[x])
    {
        if(u==p) continue;
        if(flag)
        {
            child[x]=u;    //left child
            flag=0;
        }
        else
        {
            nxt[parent]=u; // siblings
        }
        parent=u;
        findSibling(u,x);
    }
}
// parent of a node for the actual tree will always be same.
//so we can ignore the parent state for memorization
int solve(int x, int p, int k)
{
    if(x==-1) return 0;
    if(~dp[x][k]) return dp[x][k];
    int mx=MX;
    int rs=1+solve(child[x],x,m); // create a new subtree as the left child is root
    int rs1=solve(nxt[x],p,k);     // calculate k preservation for siblings of same subtree
    mx=min(mx,rs+rs1);

    int rm=k-cost[x][p];

    // calculation for left child and siblings of same  subtree where
    // preservation is distributed between these two
    for(int i=0;i<=rm;i++)
    {
        mx=min(mx,solve(child[x],x,i)+solve(nxt[x],p,rm-i));
    }
    return dp[x][k]=mx;
}
void CLEAR()
{
    mem(child,-1);
    mem(nxt,-1);
    mem(dp,-1);
    mem(cost,0);
    for(int i=0;i<=n;i++) g[i].clear();
}
int main()
{
    FasterIO;
    int tc,cs=1;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
        CLEAR();
        for(int i=1;i<n;i++)
        {
            int x,y,w;
            cin>>x>>y>>w;
            g[x].push_back(y);
            g[y].push_back(x);
            cost[x][y]=cost[y][x]=w;
        }
        cost[0][1]=cost[1][0]=MX;

        findSibling(1,0);

        int res=solve(1,0,0);

        cout<<"Case "<<cs++<<": "<<res<<"\n";
    }
    return 0;
}

