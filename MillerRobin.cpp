/*
    if n is prime than, n−1=2s⋅d, with d odd.
    Fermat's little theorem:
    a^(n−1) ≡ 1 mod n
    (a ^ (2^s) d) − 1 ≡ 0 mod n
    (a ^ (2^(s−1) d) + 1 )(a ^ (2^(s−1) d) - 1 ) ≡ 0 mod n
    (a ^ (2^(s−1) d) + 1 ) (a ^ (2^(s−2) d) + 1 )(a ^ (2^(s−2) d) - 1 )≡0modn
    (a^2^(s−1) d + 1)(a^2^(s−2) d + 1)⋯(a^d+1)(a^d−1) ≡ 0 mod n

     we check if either a^d ≡ 1 mod n
     or a^((2^r)d) ≡ −1 mod n
     holds for some 0 ≤ r ≤ s−1 .
*/
#include<bits/stdc++.h>
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;
u64 bigmod(u64 base, u64 p, u64 mod)
{
    u64 r=1;
    base%=mod;
    while(p)
    {
        if(p&1)
        {
            r=(u128) r*base % mod;
        }
        base = (u128) base*base %mod;
        p>>=1;
    }
    return r;
}
bool isComposite(u64 n, u64 a, u64 d, int s)
{
    u64 x = bigmod(a,d,n);
    if(x==1 || x==n-1) return false;
    for(int r=1; r<s ; r++)
    {
        x=(u128) x*x %n;
        if(x==n-1) return false;
    }
    return true;
}
bool millerRobin(u64 n)
{
    if(n<4) return (n==2||n==3);

    int s=0;
    u64 d=n-1;
    while((d&1)==0)
    {
        d>>=1; s++;
    }
    int iter=10;
    for(int i=0; i<iter; i++)
    {
        u64 a=2+rand()%(n-3);
        if(isComposite(n,a,d,s)) return false;
    }
    return true;
}
int main()
{
    int tc,cs=1,i,j,n,q;
    bool is=millerRobin(1e18);
    cout<<is<<endl;
    return 0;
}



