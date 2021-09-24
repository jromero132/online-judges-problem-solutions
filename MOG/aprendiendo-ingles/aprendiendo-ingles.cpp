// Problem name: A - Aprendiendo Inglés
// Problem link: https://matcomgrader.com/problem/4464/aprendiendo-ingles/
// Submission link: https://matcomgrader.com/submission/62125/

#include <bits/stdc++.h>

/* Name: Jose Ariel Romero Costa
   Class: �?
   Problem: A - Aprendiendo Ingl�s */

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.sync_with_stdio(false);
    cout.tie(0);
    int t;
    cin>>t;
    string s;
    for(int k=1;k<=t;k++){
        cin>>s;
        if(s.length()==5)
            cout<<"3"<<endl;
        else{
            int dos=0,uno=0;
            if(s[0]=='o' || s[0]=='O')
                uno++;
            if(s[1]=='n' || s[1]=='N')
                uno++;
            if(s[2]=='e' || s[2]=='E')
                uno++;
            if(s[0]=='t' || s[0]=='T')
                dos++;
            if(s[1]=='w' || s[1]=='W')
                dos++;
            if(s[2]=='o' || s[2]=='O')
                dos++;
            if(uno>dos)
                cout<<"1"<<endl;
            else
                cout<<"2"<<endl;
        }
    }
    return 0;
}