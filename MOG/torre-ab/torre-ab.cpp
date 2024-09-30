// Problem name: A - Torre AB
// Problem link: https://matcomgrader.com/problem/9107/torre-ab/
// Submission link: https://matcomgrader.com/submission/117485/

#include <iostream>

#define MOD (int)(1e1)

using namespace std;

int Pow(int a, int b){
    if(!b)
        return 1;
    if(b == 1)
        return a % MOD;
    int ans = 1;
    while(b){
        if(b & 1)
            ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> a >> b;
    if(a == b)
        cout << a % MOD;
    else{
        for(int i = b - 1 ; i >= a ; i--)
            b = Pow(i, b);
        cout << b;
    }
    return 0;
}