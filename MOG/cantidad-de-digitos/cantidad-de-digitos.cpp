// Problem name: F - Cantidad de Dígitos
// Problem link: https://matcomgrader.com/problem/4412/cantidad-de-digitos/
// Submission link: https://matcomgrader.com/submission/62231/

#include <bits/stdc++.h>

/* Name: Jose Ariel Romero Costa
   Class: �?
   Problem: F - Cantidad de D�gitos */

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.sync_with_stdio(false);
    cout.tie(0);
    int t;
    cin>>t;
    long long a,b;
    for(int k=1;k<=t;k++){
        cin>>a>>b;
        cout<<(long long)(b*log10(a)+1)<<endl;
    }
    return 0;
}