#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
/*
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

//less_equal used for multiset where st.order_of_key(x) gives the lower_bound of x

// it will not work for erase element. so for erase element better to use ordered set as pair

*/

#define FasterIO ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main()
{
    ordered_set st;
    int x=*st.find_by_order(4);
    //find 4th element in orderd set
    int y=st.order_of_key(4);
    //number of element less than 4 in orderd set
    if (st.find(4) != st.end())
        st.erase(st.find(4));
    //delete 4 if exist in orderd set
    return 0;
}

