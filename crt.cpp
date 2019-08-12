//LOJ 1319 – Monkey Tradition
//HR – Cheese and Random Toppings
//Complexity: O(n×log(L))

#include<bits/stdc++.h>
using namespace std;
typedef long long    ll;
typedef __int128     ull;
typedef pair<ll,ll>  pL;

ull ext_gcd(ull A, ull B, ull *X, ull *Y)
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
// Works for coprime moduli only
pL CRT( vector<ll> A, vector<ll> M )
{
    if(A.size() != M.size()) return {-1,-1}; /** Invalid input*/

    int n = A.size();

    ll a1 = A[0];
    ll m1 = M[0];
    /** Initially x = a_0 (mod m_0)*/
    /** Merge the solution with remaining equations */
    for ( int i = 1; i < n; i++ ) 
    {
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


/** Works for non-coprime moduli.
for better understanding code see the comments of previous code */
pL chinese_remainder_theorem( vector<int> A, vector<int> M ) {
    if(A.size() != M.size()) return {-1,-1}; /** Invalid input*/
 
    int n = A.size();
 
    ll a1 = A[0];
    ll m1 = M[0];
    for ( int i = 1; i < n; i++ ) {
        ll a2 = A[i];
        ll m2 = M[i];
 
        ll g = __gcd(m1, m2);
        if ( a1 % g != a2 % g ) return {-1,-1}; /** No solution exists*/
 
        ull p, q;
        ext_gcd(m1/g, m2/g, &p, &q);
 
        ll mod = m1 / g * m2; /** LCM of m1 and m2 //for smallest solution*/
 
        ll x = (a1*(m2/g)*q + a2*(m1/g)*p) % mod;
        
        a1 = x;
        if (a1 < 0) a1 += mod;
        m1 = mod;
    }
    return {a1, m1};
}



//Lucas Theorem
// can find NCR(n,r,p) where 1<=R<=N<=1e9 and p is a small prime number
map<pair< pair<ll,ll>, ll>, ll>mp; // for memorization
ll NCR(ll n, ll r, ll p)
{
    if(r<0 || r>n)      return 0;
    if(!r || r==n)      return 1;
    if(n>=p)            return (NCR(n/p,r/p,p)*NCR(n%p,r%p,p))%p;
    if(!mp[{{n,r},p}])  mp[{{n,r},p}]=(NCR(n-1,r-1,p)+NCR(n-1,r,p))%p;
    return mp[{{n,r},p}];
}

int main()
{
    ll tc,n,m,r,cs=0;
    cin>>tc;
    while(tc--)
    {
        cs++;
        mp.clear();
        cin>>n>>r>>m; // m is squrefree
        if(m==1)
        {
            cout<<0<<endl; continue;
        }
        vector<ll>A,M;
        for(int p=2; p*p<=m;p++)
        {
            while(m%p==0)
            {
                M.push_back(p); m/=p;
            }
        }
        if(m>=2) M.push_back(m);

        for(auto p:M)
        {
            A.push_back(NCR(n,r,p));
        }
        ll ncr=CRT(A,M).first;
        cout<<ncr<<endl;
    }
    return 0;
}
