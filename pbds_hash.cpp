#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

/*

// for unsigned __int128

typedef unsigned __int128 ull;
struct chash {
    int operator()(ull x) const { return x^(x<<32)^(x>>64)^(x>>96); }
};
gp_hash_table<ull,int,chash> table;

*/



//Defeating Anti-Hash tests

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};
gp_hash_table<int, int, chash> table;



/*

//better hash function for integers

struct chash {
    const int RANDOM = (long long)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now().time_since_epoch().count();
    static unsigned long long hash_f(unsigned long long x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
    int operator()(int x) const { return hash_f(x)^RANDOM; }

};

OR

unsigned hash_f(unsigned x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}
struct chash {
    int operator()(int x) const { return hash_f(x); }
};

gp_hash_table<ll, int, chash> mp[NM][NM];


*/

/*
//for pair

struct chash {
    int operator()(pii x) const { return x.first* 31 + x.second; }
};
gp_hash_table<pii, int, chash> table;

*/
int main(int argc, char const *argv[])
{
    //ALL kind of map operations

	table[100] = 50000;
	if(table.find(100)!=table.end()) cout<<table[100]<<endl;
	table.clear();
	cout<<table.size()<<endl;

	return 0;
}


//Almost Pattern Matching
//DUET IUPC 2019
#include <bits/stdc++.h>
using namespace std;
#pragma GCC opimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")//com error
#pragma GCC opimize("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define FasterIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
typedef unsigned __int128 ull;
const int MX=262144;
const int MXP=18;
struct chash {
    int operator()(ull x) const { return (x^(x>>64)); }
};
gp_hash_table<ull,int,chash> table[20];

ull pw[MX+10],h[MX+10];

int main()
{
    FasterIO;
    int tc,cs=1,n,q;

    ull base=29; pw[0]=1;
    for(int i=1;i<=MX; i++)
    {
        pw[i]=(pw[i-1]*base);
    }

    cin>>tc;
    while(tc--)
    {
        for(int i=0;i<20;i++)table[i].clear();
        string s,p;

        cin>>s; n=s.size();

        ull H=0;
        for(int i=0;i<n;i++)
        {
            H=(H*base+s[i]);
            h[i]=H;
        }
        for(int r=0;(1<<r) <=n;r++){

            for(int i =0; i+(1<<r) <=n ;i++){
                int j = i + (1<<r) - 1;
                table[r][h[j] - (i?h[i-1] * pw[1<<r]:0)]++;
            }
        }

        cout<<"Case "<<cs++<<":\n";
        cin>>q;
        while(q--)
        {
            cin>>p; n=p.size();
            H=0;
            for(int i=0;i<n;i++)
            {
                H=(H*base+p[i]);
            }

            ll cnt=0;

            int lg = round(log2(n));
            if(table[lg].find(H)!=table[lg].end()) cnt+=table[lg][H];

            for(int i=0;i<n;i++)
            {
                for(int j=0;j<16;j++)
                {
                    if(p[i]-'a'==j) continue;
                    ull hh=(H-(p[i]-('a'+j))*pw[n-i-1]);
                    if(table[lg].find(hh)!=table[lg].end())
                    {
                        cnt+=table[lg][hh];
                    }
                }
            }
            cout<<cnt<<"\n";
        }
    }
    return 0;
}


