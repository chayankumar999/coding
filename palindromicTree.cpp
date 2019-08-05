/**************************************************************************************
    Palindrome tree. Useful structure to deal with palindromes in strings. O(N)
    This code counts number of palindrome substrings of the string.
    Based on problem 1750 from informatics.mccme.ru:
    http://informatics.mccme.ru/moodle/mod/statements/view.php?chapterid=1750
    https://www.spoj.com/problems/NUMOFPAL
**************************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mem(a,x) memset(a,x,sizeof(x))

const int MX=200000;

struct Node
{
    int len;
    int link;
    int num;    // cnnt of differennt palindrome
    int occur;  // cnt of same palindromes
    int nxt[26];
};

Node T[MX];
int len;   // string length
string s;
int node;  // node 1 - root with len -1, node 2 - root with len 0
int suff;  // max suffix palindrome

int New()
{
    node++;
    T[node].len=T[node].link=0;
    T[node].num=T[node].occur=0;
    mem(T[node].nxt,0);
    return node;
}
bool add(int pos)
{
    int cur=suff, curlen=0;
    int let=s[pos]-'a';

    while(true)   //Finding maximum length palindromic suffix
    {
        curlen=T[cur].len;
        if(pos-1-curlen>=0 && s[pos-1-curlen]==s[pos]) break;
        cur=T[cur].link;
    }
    if(T[cur].nxt[let]) //Existing node
    {
        suff=T[cur].nxt[let];
        return false;
    }
    suff = New();
    T[node].len=T[cur].len+2;
    T[cur].nxt[let]=node;
    if(T[node].len==1) //Single character, connected with root
    {
        T[node].link=2;
        T[node].num=1;
        return true;
    }
    while(true)    //Finding suffix link
    {
        cur=T[cur].link;
        curlen=T[cur].len;
        if(pos-1-curlen>=0 && s[pos-1-curlen]==s[pos])
        {
            T[node].link=T[cur].nxt[let];
            break;
        }
    }
    T[node].num=1+T[T[node].link].num;
    return true;
}
void initTree()
{
    node=suff=2;
    T[1].len=-1, T[2].len=0;
    T[1].link=1, T[2].link=1;
    mem(T[1].nxt,0);
    mem(T[2].nxt,0);
}

ll totalpalindrome=0;
void buildTree()
{
    initTree();
    for(int i=0;i<len;i++)
    {
        add(i); T[suff].occur++;
        totalpalindrome+=T[suff].num;
    }
}
ll countPalindromes()
{
    ll cnt=0;
    for(int i=node;i>2;i--)
    {
        T[T[i].link].occur+=T[i].occur;
        cnt+=T[i].occur;
    }
    return cnt;
}

int main()
{

    cin>>s;
    len=s.size();
    buildTree();
    cout<<totalpalindrome<<endl;
    //cout<<countPalindromes()<<endl;
    return 0;
}
