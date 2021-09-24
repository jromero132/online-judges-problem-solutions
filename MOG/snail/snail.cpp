// Problem name: B - Snail
// Problem link: https://matcomgrader.com/problem/28/snail/
// Submission link: https://matcomgrader.com/submission/62101/

#include <bits/stdc++.h>

/* Name: Jose Ariel Romero Costa
   Class: �?
   Problem: B - Snail */

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.sync_with_stdio(false);
    cout.tie(0);
    double a,b,v;
    cin>>a>>b>>v;
    cout<<(long long)(floor(ceil((v-a)/(a-b))+1))<<endl;
    return 0;
}