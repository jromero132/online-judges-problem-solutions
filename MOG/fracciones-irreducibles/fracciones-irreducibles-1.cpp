// Problem name: F - Fracciones irreducibles
// Problem link: https://matcomgrader.com/problem/349/fracciones-irreducibles/
// Submission link: https://matcomgrader.com/submission/73147/

#include <bits/stdc++.h>

/* Name: Jose Ariel Romero Costa
   Class: �?
   Problem: F - Fracciones irreducibles */

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.sync_with_stdio(false);
    cout.tie(0);
    int a,b,mcd;
    cin>>a>>b;
    mcd=__gcd(a,b);
    while(mcd!=1){
        a/=mcd;
        b/=mcd;
        mcd=__gcd(a,b);
    }
    cout<<a<<" "<<b<<endl;
    return 0;
}