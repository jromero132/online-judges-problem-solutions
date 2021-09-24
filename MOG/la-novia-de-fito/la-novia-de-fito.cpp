// Problem name: A - La novia de Fito
// Problem link: https://matcomgrader.com/problem/149/la-novia-de-fito/
// Submission link: https://matcomgrader.com/submission/62121/

#include <bits/stdc++.h>

/* Name: Jose Ariel Romero Costa
   Class: �?
   Problem: A - La novia de Fito */

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.sync_with_stdio(false);
    cout.tie(0);
    string text;
    cin>>text;
    string::size_type a = text.find("ana",0);
    while(a!=string::npos){
        text.erase(text.begin()+a,text.begin()+a+3);
        a = text.find("ana",0);
    }
    cout<<text<<endl;
    return 0;
}