//LOJ 1319 – Monkey Tradition
//Complexity: O(n×log(L))

#include<bits/stdc++.h>
using namespace std;
typedef long long    ll;
typedef __int128     ull;
typedef pair<ll,ll>  pL;

ull ext_gcd(ll A, ull B, ull *X, ull *Y)
{
    ull x,x1,x2,y,y1,y2,r,r1,r2,q;
    x1=0; y1=1;     //Xi-1 and Yi-1
    x2=1; y2=0;     //Xi-2 and Yi-2
    for(r2=A, r1=B; r1!=0; r2=r1, r1=r, x2=x1, x1=x, y2=y1, y1=y)
    {
        q=r2/r1;    //Quotient qi
        r=r2%r1;    //Remainder ri
        x=x2-q*x1;
        y=y2-q*y1;
    }
    *X=x2; *Y=y2;     // coefficient of a and b
    return r2;       // gcd
}

/** Return {-1,-1} if invalid input.
    Otherwise, returns {x,L}, where x is the solution unique to mod L
*/
pL CRT( vector<ll> A, vector<ll> M ) {
    if(A.size() != M.size()) return {-1,-1}; /** Invalid input*/

    int n = A.size();

    ll a1 = A[0];
    ll m1 = M[0];
    /** Initially x = a_0 (mod m_0)*/
    /** Merge the solution with remaining equations */
    for ( int i = 1; i < n; i++ ) {
        ll a2 = A[i];
        ll m2 = M[i];

        /** Merge the two equations*/
        ull p, q;
        ext_gcd(m1, m2, &p, &q);

        /** We need to be careful about overflow. the value of p and q becomes large quickly
        and intermediate calculations no longer fit into long long variables. in such case we
        can use __int128 data type to avoid overflow issues*/
        ll x = (a1*m2*q + a2*m1*p) % (m1*m2);

        /** Merged equation*/
        a1 = x;
        m1 = m1 * m2;
    }
    if (a1 < 0) a1 += m1; /** Result is not suppose to be negative*/
    return {a1, m1};
}

int main()
{
    int tc,n,cs=1;
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        vector<ll>p(n),r(n);
        for(int i=0;i<n;i++)
        {
            cin>>p[i]>>r[i];
        }
        pL xx=CRT(r,p);
        cout<<"Case "<<cs++<<": "<<xx.first<<endl;
    }
    return 0;
}
