// Problem name: A - Tu viaje está aquí
// Problem link: https://matcomgrader.com/problem/142/tu-viaje-esta-aqui/
// Submission link: https://matcomgrader.com/submission/62116/

#include <bits/stdc++.h>

/* Name: Jose Ariel Romero Costa
   Class: �?
   Problem: A - Tu viaje est� aqu� */

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.sync_with_stdio(false);
    cout.tie(0);
    int comet=1,group=1,len;
    string name;
    cin>>name;
    len=name.length();
    for(int i=0;i<len;i++)
        comet=(comet*(name[i]-64))%47;
    cin>>name;
    len=name.length();
    for(int i=0;i<len;i++)
        group=(group*(name[i]-64))%47;
    if(comet==group)
        cout<<"GO"<<endl;
    else
        cout<<"STAY"<<endl;
    return 0;
}