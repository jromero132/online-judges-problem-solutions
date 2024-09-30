// Problem name: C - Calculadora del tío de Fito
// Problem link: https://matcomgrader.com/problem/5875/calculadora-del-tio-de-fito/
// Submission link: https://matcomgrader.com/submission/72717/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    string a,b,ans;
    char ope;
    cin>>a>>ope>>b;
    int len1=a.length()-1,len2=b.length()-1;
    if((a=="0" || b=="0") && ope=='*')
        ans="0";
    else if(ope=='+'){
        if(len1>len2){
            ans=a;
            ans[len1-len2]+=b[0]-48;
        }
        else{
            ans=b;
            ans[len2-len1]+=a[0]-48;
        }
    }
    else{
        ans=a;
        for(;len2>0;len2--)
            ans+='0';
    }
    cout<<ans;
    return 0;
}