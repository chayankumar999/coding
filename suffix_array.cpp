#include<bits/stdc++.h>
using namespace std;
#define MX 100005
#define mem(a) memset(a,0,sizeof(a))
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
    void generate(char *s)
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
int main()
{
    int n,m,i,j,k;
    char s[MX];
    scanf("%s",s); // scan as char array not string
    SA.generate(s);
    SA.print();
    return 0;
}

