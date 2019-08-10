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
