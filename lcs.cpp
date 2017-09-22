#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1001][1001];
int main()
{
    char s[1001],s1[1001];
    ll n,i,j,m,t=1,l,l1;
    while(gets(s))
    {
        gets(s1);
        memset(a,0,sizeof(a));
        l=strlen(s);
        l1=strlen(s1);
        if(strlen(s)==0||strlen(s1)==0)
        {
            cout<<"0"<<endl;
            continue;
        }
        for(i=0; i<l; i++)
        {
            for(j=0; j<l1; j++)
            {
                if(s[i]==s1[j])
                {
                    a[i+1][j+1]=a[i][j]+1;
                }
                else
                {
                    a[i+1][j+1]=max(a[i+1][j],a[i][j+1]);
                }
            }
        }
        cout<<a[l][l1]<<endl;
    }
    return 0;
}

