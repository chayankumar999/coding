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
