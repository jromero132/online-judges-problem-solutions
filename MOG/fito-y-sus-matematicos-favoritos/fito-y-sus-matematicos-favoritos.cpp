// Problem name: F - Fito y sus Matemáticos Favoritos
// Problem link: https://matcomgrader.com/problem/5871/fito-y-sus-matematicos-favoritos/
// Submission link: https://matcomgrader.com/submission/72360/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int a,b,c,d;
    while(cin>>a>>b>>c>>d && a!=b!=c!=d!=0)
        cout<<min(c,d)-max(a,b)<<" "<<max(c,d)-min(a,b)<<endl;
    return 0;
}