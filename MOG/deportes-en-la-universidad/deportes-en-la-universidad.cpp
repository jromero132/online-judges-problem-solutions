// Problem name: D - Deportes en la Universidad
// Problem link: https://matcomgrader.com/problem/347/deportes-en-la-universidad/
// Submission link: https://matcomgrader.com/submission/73146/

#include <iostream>

using namespace std;

int main()
{
    int n,s=0;
    cin>>n;
    int runners[n];
    for(int i=0;i<n;i++)
        cin>>runners[i];
    for(int i=n-1;i>=0;i--){
        if(s>0){
            s-=runners[i];
            runners[i]=1;
        }
        else{
            s+=runners[i];
            runners[i]=-1;
        }
    }
    if(s!=0)
        cout<<"No";
    else{
        cout<<"Yes";
        for(int i=0;i<n;i++)
            cout<<endl<<runners[i];
    }
    return 0;
}