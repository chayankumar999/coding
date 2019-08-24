/**********************************************************
Aho_Corasick Algorithm

~Applications:

*Find the occurrence of all string from a given set in a text
*Find all strings from a given set in a text
*Finding the lexicographical smallest string of a given length that doesn't match any given strings
*Finding the shortest string containing all given strings
*Finding the lexicographical smallest string of length L containing k strings

**********************************************************/

// problem: Substring Frequency (II) LightOJ - 1427
// http://codeforces.com/contest/963/problem/D

#include<bits/stdc++.h>
using namespace std;
#define MX 250005
#define mem(a,x) memset(a,x,sizeof(a))

const int chr=26;

struct node
{
    int nxt[chr];
    node()
    {
        mem(nxt,-1);
    }
};

node T[MX];
int suffix[MX],indx,len,path[MX];
int val[MX],ed[MX];
//int E[MX], esf[MX]; 
//vector<int>v[MX];   // list of index where an macth is ocurr for the i'th string
struct Aho_Corasick
{
    void init()
    {
        //mem(esf,0); // contain immediate previous suffix which is an endpoint of a given string
        //mem(E,0);   // check if the vertex is a endpoint or not
        len=indx=0;
        mem(T,0);
        mem(suffix,0);
        mem(val,0);
        T[indx]=node();
    }
    void insert(string s, int p)
    {
        int now=0;
        for(int i=0; i<s.size(); i++)
        {
            int id=s[i]-'a';
            if(T[now].nxt[id]==-1)
            {
                T[now].nxt[id]=++indx;
                T[indx]=node();
            }
            now=T[now].nxt[id];
        }
        ed[p]=now;
        //E[now]=p;
    }
    void reverse_link()
    {
        queue<int>q;
        for(int i=0; i<chr; i++)
        {
            if(T[0].nxt[i]!=-1)
            {
                q.push(T[0].nxt[i]);
            }
            else T[0].nxt[i]=0;
        }
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int i=0; i<chr; i++)
            {
                int v=T[u].nxt[i];
                if(v==-1)
                {
                    T[u].nxt[i]=T[suffix[u]].nxt[i]; continue;
                }
                suffix[v]=T[suffix[u]].nxt[i];
                q.push(v);
                path[len++]=v;
                //if(E[suffix[v]]) esf[v]=suffix[v];
                //else             esf[v]=esf[suffix[v]];
            }
        }
    }
    void search(string s)
    {
        int now=0;
        for(int i=0; i<s.size(); i++)
        {
            int id=s[i]-'a';
            now=T[now].nxt[id];
            val[now]++;
            //int nd=now;
            //while(nd>0)
            //{
            //    if(E[nd]) v[E[nd]].push_back(i+1);
            //    nd=esf[nd];
            //}
        }
        for(int i=len-1; i>=0; i--)
        {
            val[suffix[path[i]]]+=val[path[i]];
        }
    }
}AC;
int main()
{
    int tc,cs=1;
    cin>>tc;
    while(tc--)
    {
        AC.init();

        int n; string T;
        cin>>n>>T;

        for(int i=1; i<=n; i++)
        {
            string s;
            cin>>s;
            AC.insert(s,i);
        }

        AC.reverse_link();
        AC.search(T);

        cout<<"Case "<<cs++<<":\n";
        for(int i=1; i<=n; i++) cout<<val[ed[i]]<<'\n';

    }
    return 0;
}
