#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define db double
ll a[501][501];
ll vis[501][501];
ll dx[4]= {1,0,-1,0};
ll dy[4]= {0,1,0,-1};
ll i,j,n,m,f,s;
queue<int>pq;
void bfs(ll p,ll q)
{
    pq.push(p);
    pq.push(q);
    vis[p][q]=0;
    while(!pq.empty())
    {
        f=pq.front();
        pq.pop();
        s=pq.front();
        pq.pop();
        for(i=0; i<4; i++)
        {
            ll adjx=f+dx[i]*a[f][s];
            ll adjy=s+dy[i]*a[f][s];

            if(adjx>0&&adjy>0&&vis[adjx][adjy]<0&&adjx<=n&&adjy<=m)
            {
                pq.push(adjx);
                pq.push(adjy);
                vis[adjx][adjy]=vis[f][s]+1;
            }
            else if(adjx>0&&adjy>0&&vis[adjx][adjy]==0&&adjx==n&&adjy==m)
            {
                pq.push(adjx);
                pq.push(adjy);
                vis[adjx][adjy]=vis[f][s]+1;
            }
        }

    }
}
int main()
{
    string s1[501];
    cin>>n>>m;
    memset(vis,-1,sizeof(vis));
    for(i=0; i<n; i++)
    {
        cin>>s1[i];
        for(j=0; j<m; j++)
        {
            a[i+1][j+1]=s1[i][j]-'0';

            if(a[i+1][j+1]==0)
            {
                vis[i+1][j+1]=0;
            }
        }
    }
    bfs(1,1);
    if(vis[n][m]>0)
    {
        cout<<vis[n][m]<<endl;
    }
    else
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}

