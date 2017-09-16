#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1000007
ll lps[mx];
string s,s1;
ll i,j,k,l,l1,c;
void lps_array()
{
    i=0;
    j=1;
    while(j<l1)
    {
        if(s1[i]==s1[j])
        {
            i++;
            lps[j]=i;
            j++;
        }
        else
        {
            if(i==0)
            {
                lps[j]=i;
                j++;
            }
            else
            {
                i=lps[i-1];
            }
        }
    }
}
ll kmp_search()
{
    i=0,j=0;
    while(i<l)
    {
        if(s[i]==s1[j])
        {
            i++;
            j++;
            if(j==l1)
            {
                c++;
                j=lps[j-1];
            }
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                i++;
            }
        }
    }
    return c;
}
int main()
{
    cin>>s>>s1;
    l=s.size();
    l1=s1.size();
    lps_array();
    ll r=kmp_search();
    cout<<r<<endl;
//    for(i=0;i<l1;i++)
//    {
//        cout<<lps[i]<<" ";
//    }
    return 0;
}
