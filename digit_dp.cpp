// Type 1

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, x) memset(a, x, sizeof(a))

string s;  int sz;
ll dp[20][150][2];

ll call(int p, int sm, int  f)
{
    if(p==sz)         return sm;
    if(~dp[p][sm][f]) return dp[p][sm][f];
    ll ret=0;
    if(f)
    {
        for(int i=0; i<10; i++)
        {
            ret+=call(p+1, sm+i, f);
        }
    }
    else
    {
        for(int i=0; i<s[p]-'0'; i++)
        {
            ret+=call(p+1, sm+i, 1);
        }
        ret+=call(p+1, sm+s[p]-'0', 0);
    }
    return dp[p][sm][f]=ret;
}
void Tostring(ll x)
{
    s = "";
    while(x)
    {
        s+=(x%10 + '0'); x/=10;
    }
    reverse(s.begin(), s.end());
    sz = s.size();
}
int main()
{
    ll a, b, r, tc;
    cin>>tc;
    while(tc--)
    {
        cin>>a>>b;

        mem(dp, -1);
        Tostring(b);
        r = call(0, 0, 0);

        if(a-1>0)
        {
            mem(dp, -1);
            Tostring(a-1);
            r -= call(0, 0, 0);
        }
        cout<<r<<endl;
    }
    return 0;
}




//Type 2
// https://codeforces.com/contest/1245/problem/F


#include<bits/stdc++.h>
using namespace std;
#define FasterIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long long ll;
#define mem(a,x) memset(a,x,sizeof(a))

bitset<32>L, R;
ll dp[32][2][2][2][2];

/*
Problem: number of pair L<=a<=R, L<=b<=R so that aXORb = a+b
here xor of L1 and R1 = L1+R1;
sm1 and s1 check that if L1 is less than R.
sm2 and s2 check that if R1 is less than R.
lg1 and l1 check that if L1 is greater than L.
lg2 and l2 check that if R1 is greater than L.

*/
ll call(int p, int sm1, int sm2, int lg1, int lg2)
{
    if(p<0) return 1;

    if(~dp[p][sm1][sm2][lg1][lg2]) return dp[p][sm1][sm2][lg1][lg2];

    ll ret=0;
    for(int i=0; i<2; i++)
    {
        if(lg1==false && i<L[p]) continue;
        if(sm1==false && i>R[p]) continue;
        for(int j=0; j<2; j++)
        {
            if(lg2==false && j<L[p]) continue;
            if(sm2==false && j>R[p]) continue;
            if(i&j)                  continue;
            bool s1=sm1|(i<R[p]);
            bool s2=sm2|(j<R[p]);
            bool l1=lg1|(i>L[p]);
            bool l2=lg2|(j>L[p]);
            ret+=call(p-1, s1, s2, l1, l2);
        }
    }
    return dp[p][sm1][sm2][lg1][lg2]=ret;
}
int main()
{
    FasterIO;

    int tc;
    cin>>tc;
    while(tc--)
    {
        mem(dp, -1);
        int l, r;
        cin>>l>>r;
        L=bitset<32>(l);
        R=bitset<32>(r);
        cout<<call(31, 0, 0, 0, 0)<<endl;
    }
    return 0;
}
