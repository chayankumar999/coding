#include<bits/stdc++.h>
using namespace std;
#define ll long long
int z[100005];
void z_algo(string s)
{
    int sz=s.size();
    int L=0,R=0,k;
    for(int i=1; i<sz; i++)
    {
        if(i>R)
        {
            L=R=i;
            while(R<sz&&s[R-L]==s[R])
            {
                R++;
            }
            z[i]=R-L;
            R--;
        }
        else
        {
            k=i-L;
            if(z[k]<R-i+1)
            {
                z[i]=z[k];
            }
            else
            {
                L=i;
                while(R<sz&&s[R-L]==s[R])
                {
                    R++;
                }
                z[i]=R-L;
                R--;
            }
        }
    }
}
int main()
{
    int i,j,k,l,n,m;
    string s;
    cin>>s;
    z_algo(s);
    for(i=0; i<s.size(); i++)
    {
        cout<<z[i]<<" ";
    }
    cout<<endl;
    return 0;
}
