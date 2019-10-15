/*

 number of coprime of n using sieve only

*/

#include<bits/stdc++.h>
using namespace std;
#define FasterIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

const int MX=10000000;

int co[MX+5], p[MX+5];

void coprime()
{
    for(int i=1; i<=MX; i++) co[i]=i;

    for(int i=2; i<=MX; i++)
    {
        if(!p[i])
        {
            for(int j=i; j<=MX; p[j]=1, j+=i)
            {
                co[j] = ( co[j] / i ) * (i-1);
            }
        }
    }
}
int main()
{
    FasterIO;

    coprime();

    return 0;
}



/*

 number of coprime of n using sieve and prime factorization

*/

#include<bits/stdc++.h>
using namespace std;
#define FasterIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

const int MX=10000000;

int mark[MX+5],co[MX+5];

vector<int>pm;

void sieve()
{
    for(int i=2; i*i<=MX; i++)
    {
        if(mark[i]==0)
        {
            for(int j=i+i;j<=MX;j+=i) mark[j]=1;
        }
    }

    for(int i=2; i<=MX; i++) if(!mark[i]) pm.push_back(i);
}

int co_fact(int x)
{
    int xx=x;
    for(int i=0; pm[i]*pm[i]<=x; i++)
    {
        if(x%pm[i]==0)
        {
            xx/=pm[i]; xx*=(pm[i]-1);

            while(x%pm[i]==0) x/=pm[i];
        }
    }
    if(x>=2)
    {
        xx/=x; xx*=(x-1);
    }
    return xx;
}
int main()
{
    ll tc,n,i,j;

    sieve();

    for(int i=1; i<=MX; i++) co[i]=co_fact(i);

    return 0;
}
