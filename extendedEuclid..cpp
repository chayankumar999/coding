/*
**************Extended Euclidean Algorithm****************
It finds: 1)  GCD(a,b). 2) two integers x and y such that, ax+by=gcd(a,b).
Let us add two new variables. R represents remainder and q means quotient.
Let r0 be a and r1 be b. At each step, we will calculate ri. Let qi=floor( R(i−2)/R(i−1) ).
Therefore, Ri=R(i−2) – qi×R(i−1).
We are trying to express GCD(a,b)=ax+by. So the variable x and y will hold the coefficients.
To be exact we will write each row as terms of a and b, i.e, ri=axi+byi.
Initially, (x0,y0)=(1,0) and (x1,y1)=(0,1). But how do we calculate (xi,yi)?
We know that Ri=R(i−2) – qi×R(i−1). We also claimed that Ri=axi+byi. By combining this two we get
ri=(aX(i−2)+bY(i−2))– qi×(aX(i−1)+bY(i−1))
ri=aX(i−2)– qi×aX(i−1)+bY(i−2)–qi×bY(i−1)
ri=a(X(i−2)–qi×X(i−1))+b(Y(i−2)–qi×Y(i−1))
ri=axi+byi
∴xi=X(i−2)–qi×X(i−1) and yi=Y(i−2)–qi×Y(i−1).

NOTE:
* gcd(a,b)  is the smallest positive number of the form ax+by.
*Uniqueness of Solution
Once we find a pair (x,y) using ext_gcd, we can generate infinite pairs of Bezout coefficients
using the formula: (x+k*b/gcd(a,b),y–k*a/gcd(a,b))
Proof:
a(x+k*b/gcd(a,b))+b(y–k*a/gcd(a,b))
=ax+k*a*b/gcd(a,b)+by–k*a*b/gcd(a,b)
=ax+by

*/
// Euclid Problem UVA - 10104

#include<bits/stdc++.h>
using namespace std;
#define FasterIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;

int X,Y;            //coefficient of a and b
int ext_gcd(int A, int B)
{
    int x,x1,x2,y,y1,y2,r,r1,r2,q;
    x1=0; y1=1;     //Xi-1 and Yi-1
    x2=1; y2=0;     //Xi-2 and Yi-2
    for(r2=A, r1=B; r1!=0; r2=r1, r1=r, x2=x1, x1=x, y2=y1, y1=y)
    {
        q=r2/r1;    //Quotient qi
        r=r2%r1;    //Remainder ri
        x=x2-q*x1;
        y=y2-q*y1;
    }
    X=x2; Y=y2;     // coefficient of a and b
    return r2;       // gcd
}
int main()
{

    FasterIO;
    int a,b;
    while(cin>>a>>b)
    {
        int gcd;
        gcd=ext_gcd(a,b);
        cout<<X<<" "<<Y<<" "<<gcd<<endl;
    }
    return 0;
}






/*

***************Linear Diophantine Equation*****************

source: LightOJ 1306 -> Solutions to an Equation

 Given the value of integers A,B and C find a pair of integers (x,y)
 such that it satisfies the equation Ax+By=C.
 
*/

#include<bits/stdc++.h>
using namespace std;
#define FasterIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define ff first
#define ss second
#define mk make_pair
#define pi pair<int,int>
#define vi vector<int>
#define pL pair<ll,ll>
#define vL vector<ll>
#define vp vector<pi>
#define vpL vector<pL>

const int MX=10000000;
const ll inf=1e9;
const ll mod=1e9+7;

ll X,Y;
ll ext_gcd(ll A, ll B)
{
    ll x,x1,x2,y,y1,y2,r,r1,r2,q;
    x1=0; y1=1; x2=1; y2=0;
    for(r2=A, r1=B; r1!=0; r2=r1, r1=r, x2=x1, x1=x, y2=y1, y1=y)
    {
        q=r2/r1;
        r=r2%r1;
        x=x2-q*x1;
        y=y2-q*y1;
    }
    X=x2;  Y=y2;
    return r2;
}

bool linearDiophantine(ll a, ll b, ll c) // return X and Y such that AX+BY+C=0;
{
    ll g = ext_gcd(abs(a), abs(b));
    if (c % g) return false;

    X *= c / g;
    Y *= c / g;
    if (a < 0) X = -X;
    if (b < 0) Y = -Y;
    return true;
}

pL getXY(ll k, ll A, ll B) // Bezout coefficients//valid X, Y
{
    ll gcd=__gcd(A,B);
    return {X+k*B/gcd,Y-k*A/gcd};
}

///Finding the number of solutions in a given interval
ll get_no_of_valid_XY(ll A, ll B, ll C, ll x1, ll x2, ll y1, ll y2)
{
    ll mx=0;

    ll lo=-1e9, hi=1e9, L=1e9, R=-1e9;  // lo, hi, L, R is initialized with max and min k value
    bool f=getXY(lo, A, B).ff<=getXY(hi, A, B).ff;
    while(lo<=hi) // fixed the lower bound of X such that X>=x1
    {
        ll m=(lo+hi)/2;
        pL xx=getXY(m, A, B);
        if(f)
        {
            if(xx.ff>=x1) L=m, hi=m-1;
            else          lo=m+1;
        }
        else
        {
            if(xx.ff<=x2) L=m, hi=m-1;
            else          lo=m+1;
        }
    }

    lo=-1e9, hi=1e9;

    while(lo<=hi)  // fixed the upper bound of X such that X<=x2
    {
        ll m=(lo+hi)/2;
        pL xx=getXY(m, A, B);
        if(f)
        {
            if(xx.ff<=x2) R=m, lo=m+1;
            else          hi=m-1;
        }
        else
        {
            if(xx.ff>=x1) R=m, lo=m+1;
            else          hi=m-1;
        }
    }

    if(max(R-L+1, 0LL)==0 || L==R && (R==1e9 || L==-1e9)) return 0; // no such X between x1 to x2

    ll L1=1e9, R1=-1e9;

    f=getXY(L, A, B).ss<=getXY(R, A, B).ss;

    lo=L, hi=R;
    while(lo<=hi)   // fixed the lower bound of Y such that Y>=y1
    {
        ll m=(lo+hi)/2;
        pL xx=getXY(m, A, B);
        if(f)
        {
            if(xx.ss>=y1) L1=m, hi=m-1;
            else          lo=m+1;
        }
        else
        {
            if(xx.ss<=y2) L1=m, hi=m-1;
            else          lo=m+1;
        }
    }

    lo=L, hi=R;
    while(lo<=hi)  //fixed the upper bound of Y such that Y<=y2
    {
        ll m=(lo+hi)/2;
        pL xx=getXY(m, A, B);
        if(f)
        {
            if(xx.ss<=y2) R1=m, lo=m+1;
            else          hi=m-1;
        }
        else
        {
            if(xx.ss>=y1) R1=m, lo=m+1;
            else          hi=m-1;
        }
    }
    if(max(R1-L1+1, 0LL)==0 || L1==R1 && (R1==1e9 || L1==-1e9)) return 0; // no such Y between y1 to y2
    return max(R1-L1+1, 0LL);
}
int main ()
{

    FasterIO;

    ll A, B, C, x1, y1, x2, y2, tc, cs=1;

    cin>>tc;

    while(tc--)
    {

        cin>>A>>B>>C>>x1>>x2>>y1>>y2;

        cout<<"Case "<<cs++<<": ";
        if(!A && !B) //no of solution for base case to avoid runtime_error
        {
            if(!C) cout<<(x2-x1+1)*(y2-y1+1)<<endl;
            else   cout<<0<<endl;
            continue;
        }
        bool res = linearDiophantine( A, B, -C);
//        cout<<X<<' '<<Y<<endl;
        if ( res == false ) cout<<0<<endl;
        else
        {
            cout<<get_no_of_valid_XY(A, B, C, x1, x2, y1, y2)<<endl;
        }
    }
    return 0;
}
