// Problem name: A - Fito Task
// Problem link: https://matcomgrader.com/problem/27/fito-task/
// Submission link: https://matcomgrader.com/submission/62100/

#include <bits/stdc++.h>

/* Name: Jose Ariel Romero Costa
   Class: �?
   Problem: A - Fito Task */

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.sync_with_stdio(false);
    cout.tie(0);
    char a[9],b[9];
    cin>>a>>b;
    int len=strlen(a);
    for(int i=0;i<len;i++)
        if(a[i]=='6')
            a[i]='5';
    len=strlen(b);
    for(int i=0;i<len;i++)
        if(b[i]=='6')
            b[i]='5';
    cout<<(atol(a)+atol(b))<<" ";
    len=strlen(a);
    for(int i=0;i<len;i++)
        if(a[i]=='5')
            a[i]='6';
    len=strlen(b);
    for(int i=0;i<len;i++)
        if(b[i]=='5')
            b[i]='6';
    cout<<(atol(a)+atol(b))<<endl;
    return 0;
}