// Problem name: C - Diagonales
// Problem link: https://matcomgrader.com/problem/130/diagonales/
// Submission link: https://matcomgrader.com/submission/62235/

#include <bits/stdc++.h>

/* Name: Jose Ariel Romero Costa
   Class: �?
   Problem: C - Diagonales */

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.sync_with_stdio(false);
    cout.tie(0);
    double a;
    int case_number=1;
    while(cin>>a && a!=0){
        cout<<"Case "<<case_number<<": "<<(long long)(ceil(1.5+sqrt(9+8*a)/2))<<endl;
        case_number++;
    }
    return 0;
}