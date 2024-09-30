// Problem name: B - Se puede o NO se Puede
// Problem link: https://matcomgrader.com/problem/143/se-puede-o-no-se-puede/
// Submission link: https://matcomgrader.com/submission/62115/

#include <bits/stdc++.h>

/* Name: Jose Ariel Romero Costa
   Class: �?
   Problem: B - Se puede o NO se Puede */

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.sync_with_stdio(false);
    cout.tie(0);
    int t,a,b,c;
    cin>>t;
    for(int k=1;k<=t;k++){
        cin>>a>>b>>c;
        if(a+b>c && a+c>b && a<b+c)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}