#include <bits/stdc++.h>
using namespace std;
#define FasterIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define vi vector<int>

const int MX=200000;
const int LG=18;

int sp[MX+5][LG+2];

void SPTBL(int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; (1<<j)<=n; j++)
        {
            if(sp[i][j-1]==-1) continue;
            sp[i][j]=sp[sp[i][j-1]][j-1];
        }
    }
}

int main()
{
    FasterIO;
    int n,q;
    SPTBL(n);
    return 0;
}
