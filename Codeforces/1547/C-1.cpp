// Problem name: Pair Programming
// Problem link: https://codeforces.com/contest/1547/problem/C
// Submission link: https://codeforces.com/contest/1547/submission/122042660

#include<bits/stdc++.h>
using namespace std;
#define rep(a, b, i) for (int i = (a); i < (b); ++i)
#define repi(a, b, i) for (int i = (a); i > (b); --i)
#define sz(x) (int)x.size()
#define pb push_back
#define mkp make_pair
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
void test()
{
    int k,n,m;
    cin>>k>>n>>m;
    vector<int> a;
    vector<int> b;
    vector<int> c;
    a.resize(n);
    b.resize(m);
    c.resize(n+m);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    rep(0,m,i)
    {
        cin>>b[i];
    }
    int i,j,l;
    i=0,j=0,l=0;
    bool check=true;
    while(l<(n+m))
    {
        if((i<n  && a[i]==0 )||(j<m && b[j]==0))
        {
            
            c[l++]=(i<n && a[i]==0)?a[i++]:b[j++]; 
            k++;
            continue;
        }
        if(i<n && a[i]<=k)
        {
            c[l++]=a[i++];
            continue;
        }
        if(j<m && b[j]<=k)
        {
            c[l++]=b[j++];
            continue;
        }
        break;
    };
    if(l<n+m)
    {
        cout<<"-1"<<"\n";
    }
    else
    {
        for(int i=0;i<sz(c);i++)
        {
            cout<<c[i]<<"\t";
        }
        cout<<"\n";
    }
}
int main()
{
        int t;
        cin>>t;
        while(t--)
        {
             test();
             //cout<<"\n";
        };
}