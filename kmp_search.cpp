#include<bits/stdc++.h>
using namespace std;
#define MX 1000007
struct _KMP
{
    int lps[MX],a[MX],c;
    void LpsArray(string pt)
    {
        int i,j;
        i=0; j=1;
        while(pt[j])
        {
            if(pt[i]==pt[j]) lps[j++]=++i;
            else
                if(i==0) lps[j++]=i;
                else  i=lps[i-1];
        }
    }
    int KmpSearch(string s, string pt)
    {
        int i,j;
        i=j=c=0;
        while(s[i])
        {
            if(s[i]==pt[j]) {
                i++,j++;
                if(j==pt.size()) c++, j=lps[j-1]; }
            else
                if(j!=0) j=lps[j-1];
                else i++;
        }
        return c;
    }

}KMP;
int main()
{
    string s,pt;
    int i,j,k,n,m;
    cin>>s>>pt;
    KMP.LpsArray(pt);
    cout<<"No of substring of s that contain pattern pt is: "<<endl;
    cout<<KMP.KmpSearch(s,pt)<<endl;
    return 0;
}
