// Problem name: A - A Trip
// Problem link: https://matcomgrader.com/problem/58/a-trip/
// Submission link: https://matcomgrader.com/submission/62230/

#include <bits/stdc++.h>

/* Name: Jose Ariel Romero Costa
   Class: �?
   Problem: A - A Trip */

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.sync_with_stdio(false);
    cout.tie(0);
    int n;
    double at;
    cin>>n>>at;
    double pt=0,p[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
        pt+=p[i];
    }
    for(int i=0;i<n;i++)
        printf("%.5lf\n",p[i]*at/pt);
    return 0;
}