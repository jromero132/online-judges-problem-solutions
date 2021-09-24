// Problem name: Spreadsheet
// Problem link: https://codeforces.com/contest/1/problem/B
// Submission link: https://codeforces.com/contest/1/submission/25755908

#include <bits/stdc++.h>

#define MAX (int)(1e4 + 1)
#define BASE (int)(26)
#define START (int)(64)
#define endl '\n'

using namespace std;

typedef long long ll;

string s;

string changeBase(ll n){
    string ans;
    do{
        //cout << START << " " << n % BASE << " " << START + n % BASE << endl;
        ans = (char)(START + n % BASE) + ans;
        //cout << (int)ans[ 0 ] << endl;
        n /= BASE;
        if(ans[ 0 ] == 64)
            ans[ 0 ] = 90, n--;
    }while(n);
    return ans;
}

ll changeBase(string n){
    ll p = 1, ans = 0;
    for(int i = n.length() - 1 ; i >= 0 ; i--)
        ans += (n[ i ] - 64) * p, p *= BASE;
    return ans;
}

string toString(ll n){
    string ans;
    do{
        ans = (char)(n % 10 + 48) + ans;
        n /= 10;
    }while(n);
    return ans;
}

string convert(){
    string s1;
    int n1 = 0, n2 = 0;
    bool num = 0, second = 0;
    for(int i = 0 ; s[ i ] != '\0' ; i++){
        if(s[ i ] >= 65){
            if(num)
                second = 1;
            s1 += s[ i ];
        }
        else{
            num = 1;
            if(!second)
                n1 *= 10, n1 += s[ i ] - 48;
            else
                n2 *= 10, n2 += s[ i ] - 48;
        }
    }
    if(second)
        return changeBase(n2) + toString(n1);
    return 'R' + toString(n1) + 'C' + toString(changeBase(s1));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //cout << changeBase(494)<<endl;
    int t;
    for(cin >> t ; t ; t--){
        cin >> s;
        cout << convert() << endl;
    }
    return 0;
}

/*
3
R23C55
BC23
R228C494
*/