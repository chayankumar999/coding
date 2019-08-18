// complexity O(V^2*E)
// problem: LightOj -> Power Transmission 1155
#include<bits/stdc++.h>
using namespace std;
#define FasterIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long     ll;
typedef pair<int,int> pi;
#define ff first
#define ss second
const int MX=100000;
const int inf=1e9;

struct DinicMaxflow
{
    struct edge
    {
        int a, b, cap, flow ;
        edge(int _a, int _b, int _c, int _d)
        {
            a = _a, b = _b, cap = _c, flow = _d;
        }
    } ;

    int n, s, t, level [ MX ] , ptr [ MX ] ;
    vector < edge > e ;
    vector < int > g [ MX ] ;
    queue<int>q;

    void add_edge ( int a, int b, int cap )
    {
        edge e1 = edge( a, b, cap, 0 ) ;
        edge e2 = edge( b, a, 0 , 0 ) ; // egde capacity will be cap for bidirectional edge
        // if multiple edge occurs all edge should be considered
        g [ a ] . push_back ( ( int ) e. size ( ) ) ;
        e. push_back ( e1 ) ;
        g [ b ] . push_back ( ( int ) e. size ( ) ) ;
        e. push_back ( e2 ) ;
    }
    bool bfs ( )
    {
        memset ( level, -1 , sizeof level ) ;
        level [ s ] = 0 ;    q.push(s);
        while( !q.empty() )
        {
            int u = q.front();
            q.pop();
            for(int i=0; i<g[u].size(); i++)
            {
                int id = g[u][i];
                int v = e[id].b;
                if ( level [ v ] == - 1 && e [ id ] . flow < e [ id ] . cap )
                {
                    level[v] = level[u]+1;
                    q.push(v);
                }
            }
        }
        return level [ t ] != - 1 ;
    }
    int dfs ( int u, int flow )
    {
        if ( ! flow )  return 0 ;
        if ( u == t )  return flow ;
        for ( ; ptr [ u ] < ( int ) g [ u ] . size ( ) ; ++ ptr [ u ] )
        {
            int id = g [ u ] [ ptr [ u ] ] ;
            int v = e [ id ] . b ;
            if ( level [ v ] != level [ u ] + 1 )  continue ;
            int mxflow = dfs ( v, min ( flow, e [ id ] . cap - e [ id ] . flow ) ) ;
            if ( mxflow )
            {
                e [ id ] . flow += mxflow ;
                e [ id ^ 1 ] . flow -= mxflow ;
                return mxflow ;
            }
        }
        return 0 ;
    }
    int MaxFlow ( )
    {
        int flow = 0 ;
        while(bfs())
        {
            memset ( ptr, 0 , sizeof ptr ) ;
            while ( int mxflow = dfs ( s, inf ) )
            {
                flow += mxflow ;
                if(mxflow == 0)break;
            }
        }
        return flow ;
    }

    void init( int _n, int _s, int _t )
    {
        n = _n; s = _s; t = _t;
        for(int i=0; i<e.size(); i++) e[i].flow=0;
    }
    void RESET()
    {
        e.clear();
        for(int i=0; i<=n; i++) g[i].clear();
    }
};

int main()
{
    FasterIO;
    int tc,cs=1;
    cin>>tc;
    while(tc--)
    {
        int n,m;
        cin>>n;
        DMF.RESET();
        DMF.init(2*n+2,0,2*n+1);
        for(int i=1; i<=n; i++)
        {
            int cap;
            cin>>cap;
            DMF.add_edge(i,i+n,cap);
        }
        cin>>m;
        for(int i=1; i<=m; i++)
        {
            int u,v,cap;
            cin>>u>>v>>cap;
            DMF.add_edge(u+n,v,cap);
        }
        int st,ed;
        cin>>st>>ed;
        for(int i=1; i<=st; i++)
        {
            int x;
            cin>>x;
            DMF.add_edge(0,x,inf);
        }
        for(int i=1; i<=ed; i++)
        {
            int x;
            cin>>x;
            DMF.add_edge(x+n,2*n+1,inf);
        }
        int ans=DMF.MaxFlow();
        cout<<"Case "<<cs++<<": "<<ans<<"\n";
    }
    return 0;
}
