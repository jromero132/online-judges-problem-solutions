// Problem name: C - Secuencia creciente
// Problem link: https://matcomgrader.com/problem/4472/secuencia-creciente/
// Submission link: https://matcomgrader.com/submission/62172/

#include <bits/stdc++.h>

/* Name: Jose Ariel Romero Costa
   Class: �?
   Problem: C - Secuencia creciente */

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.sync_with_stdio(false);
    cout.tie(0);
    int n,d;
    cin>>n>>d;
    long long sec[n],cantd=0,add;
    for(int i=0;i<n;i++)
        cin>>sec[i];
    for(int i=1;i<n;i++){
        if(sec[i]<=sec[i-1]){
            add=(sec[i-1]-sec[i])/d+1;
            sec[i]+=add*d;
            cantd+=add;
        }
    }
    cout<<cantd<<endl;
    return 0;
}