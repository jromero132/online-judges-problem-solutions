// Problem name: D - Coliseo de Roma
// Problem link: https://matcomgrader.com/problem/4474/coliseo-de-roma/
// Submission link: https://matcomgrader.com/submission/62171/

#include <bits/stdc++.h>

/* Name: Jose Ariel Romero Costa
   Class: �?
   Problem: D - Coliseo de Roma */

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.sync_with_stdio(false);
    cout.tie(0);
    int t;
    cin>>t;
    double dist,x,y,r,min,max;
    for(int k=1;k<=t;k++){
        cin>>x>>y>>r;
        dist=sqrt(x*x+y*y);
        min=r-dist;
        max=2*r-min;
        printf("%.2lf %.2lf\n",min,max);
    }
    return 0;
}