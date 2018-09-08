//LOJ 1203

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define mem(a) memset(a,0,sizeof(a))
#define ff first
#define ss second
#define pb push_back
#define mk make_pair
#define stp setprecision
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define inf 1e9
#define MX 100005
#define pi acos(-1.0)
#define pii pair<ll,ll>
#define eps 1e-9
ll SQR(ll aa)
{
    return aa*aa;
}
bool cw(pii &a, pii &b, pii &c)
{
    return (b.ff-a.ff)*(c.ss-a.ss)-(b.ss-a.ss)*(c.ff-a.ff)<0;
}
bool colin(pii a, pii b, pii c)
{
    return  a.ff*(b.ss-c.ss)+b.ff*(c.ss-a.ss)+c.ff*(a.ss-b.ss)==0;
}
vector<pii> convecHull(vector<pii> p)
{
    int n=p.size();
    if(n<=1)return p;
    sort(p.begin(),p.end());
    int cnt=0;
    vector<pii>qq(2*n);
    for(int i=0;i<n;qq[cnt++]=p[i++])
        for(;cnt>=2&&!cw(qq[cnt-2],qq[cnt-1],p[i]);cnt--);
    for(int i=n-2,t=cnt;i>=0;qq[cnt++]=p[i--])
        for(;cnt>t&&!cw(qq[cnt-2],qq[cnt-1],p[i]);cnt--);
    qq.resize(cnt-1-(qq[0]==qq[1]));
    return qq;
}
vector<pii>v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //////////////////////////////////////////
    ll i,j,k,n,m,z,cs=1,tc;
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        v.resize(n);
        for(i=0;i<n;i++)
        {
            cin>>v[i].ff>>v[i].ss;
        }
        v=convecHull(v);
        n=v.size();
        if(n<3)
        {
            cout<<"Case "<<cs++<<": "<<stp(6)<<fixed<<'0'<<endl;
            continue;
        }
        double ans=pi;
        for(i=0;i<n;i++)
        {
            pii xx=v[(i+1)%n];
            pii yy=v[i];
            pii zz=v[(i-1+n)%n];
            double a=SQR(xx.ff-zz.ff)+SQR(xx.ss-zz.ss);
            double b=SQR(yy.ff-zz.ff)+SQR(yy.ss-zz.ss);
            double c=SQR(xx.ff-yy.ff)+SQR(xx.ss-yy.ss);
            double dv=sqrt(b*c);
            double ang;
            if(abs(dv)>eps)
            {
                ang=(b+c-a)/2.0/dv;
            }
            else
            {
                ans=eps;
                break;
            }
            if(ang>1)ang=1;
            if(ang<-1)ang=-1;
            ans=min(ans,acos(ang));
        }
        cout<<"Case "<<cs++<<": "<<stp(6)<<fixed<<((ans*180)/pi)<<endl;
    }
    return 0;
}

