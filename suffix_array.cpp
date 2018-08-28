#include<bits/stdc++.h>
using namespace std;
#define MX 100005
#define mem(a) memset(a,0,sizeof(a))
#define sc(a) scanf("%d",&a)
struct SUFFIX_ARRAY
{
    int ra[MX],tra[MX],sa[MX],tsa[MX],r[MX];
    int len;
    int rank[MX],lcp[MX];
    int cmp(int *y, int a, int b, int l)
    {
        return y[a] == y[b] && y[a + l] == y[b + l]; // rank checking
    }
    void SuffixArr(int n,int m)//n= string length // m= unique char
    {
        int i,j,p,*x=tra,*y=ra,*t;
        mem(tsa);

        for(i=0; i<n; i++) tsa[ x[i]=r[i]]++; //assigned temporary rank

        for(i=1; i<m; i++) tsa[i]+=tsa[i-1]; // cumilative sum for c.s.

        for(i=n-1; i>=0; i--) sa[ --tsa[ x[i] ] ]=i; //counting sort

        for(j=1,p=1; p<n; j<<=1,m=p) // while rank < n // until there are n suffix
        {
            for(i=n-j,p=0; i<n; i++) y[p++]=i; // ranking for element i+j>n

            for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j; // ranking for others

            mem(tsa);

            for(i=0; i<n; i++) tsa[ x[ y[i] ] ]++;// for counting sort

            for(i=1; i<m; i++) tsa[i]+=tsa[i-1]; // cumilative sum for c.s.

            for(i=n-1; i>=0; i--) sa[ --tsa[ x[ y[ i ] ] ] ]=y[i];//suffix array for 2*j length substring

            for(t=x,x=y,y=t,x[ sa[0] ]=0,i=1,p=1; i<n; i++) // calculate tra
                x[ sa[i] ]= cmp(y,sa[i],sa[i-1],j)?p-1:p++;
        }
    }
    void LCP(int n)
    {
        int i,j,k=0;
        for(i=1; i<=n; i++) rank[sa[i]]=i;
        for(i=0; i<n; lcp[rank[i++]] = k )
            for(k?k--:0,j=sa[rank[i]-1]; r[i+k]==r[j+k]; k++);
    }
    void generate(string s)
    {
        int n;
        for (n=0; s[n] ; n++)
            r[n]=(int)s[n];
        this->len = n;
        r[n]=0;
        SuffixArr(n+1,128);
        LCP(n);
    }
    void print()
    {
        cout << "length :  " << len << endl;
        for(int i=0; i<=len; i++) cout << sa[i] << " ";
        cout << endl;
        cout << "rank of suffix " << endl;
        for(int i=0;i<=len;i++)  cout << rank[i] << " ";
        cout << endl;
        cout << "LCP between sa[i] and sa[i-1] " << endl;
        for(int i=0;i<=len;i++)  cout << lcp[i] << "  ";
        cout << endl;
    }
} SA;
struct _KMP
{
    int lps[MX],a[MX],c;
    void LpsArray(string st)
    {
        int i,j;
        i=0; j=1;
        while(st[j])
        {
            if(st[i]==st[j]) lps[j++]=++i;
            else
                if(i==0) lps[j++]=i;
                else  i=lps[i-1];
        }
    }
    void KmpSearch(string s, string st)
    {
        int i,j;
        i=j=c=0;
        while(s[i])
        {
            if(s[i]==st[j]) {i++,j++;
                if(j==st.size()) a[c++]=i-j, j=lps[j-1];}
            else
                if(j!=0) j=lps[j-1];
                else i++;
        }
        a[c++]=s.size();
    }
    int BinarySearch(int v)
    {
        int lo,hi,md;
        lo=0;hi=c-1;
        while(lo<=hi)
        {
            md=(lo+hi)/2;
            if(a[md]==v) {lo=md;break;}
            else if(a[md]>v) hi=md-1;
            else lo=md+1;
        }
        return lo;
    }

}KMP;
int main()
{
    int n,m,i,j,k,tc,cs=1,x,y,z,cnt;
    string s,st;
    sc(tc);
    while(tc--)
    {
        cin>>s>>st;
        SA.generate(s);
        KMP.LpsArray(st);
        KMP.KmpSearch(s,st);
        cnt=0;
        for(i=1;i<=SA.len;i++)
        {
            int _lcp=SA.lcp[i];
            x=SA.sa[i];
            int lo=KMP.BinarySearch(x);
            y=KMP.a[lo];
            if(y!=s.size())
            {
                y+=st.size()-1;
            }
            x=y-x;
            if(x>_lcp)
            {
                cnt+=x-_lcp;
            }
        }
        printf("Case %d: %d\n",cs++,cnt);
    }
    return 0;
}

