// Problem name: Hat-Xor
// Problem link: https://codeforces.com/gym/101962/problem/E
// Submission link: https://codeforces.com/gym/101962/submission/45148839

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
    freopen("01.in", "r", stdin);
    freopen("01.out", "w", stdout);
#endif

    string s;
    cin >> s;
    int now = 0;
    for(auto c : s)
        now ^= (c - '0');
    if ((now ^= (s.back() - '0')) != s.back() - '0'){
        cout << "NO" << endl;
        return 0;
    }
    for(int i = s.size() - 2 ; i >= 0 ; --i){
        if(now != (now ^ (s[ i ] - '0'))){
            if(s[ i ] == '0'){
                cout << "NO" << endl;
                return 0;
            }
        }
        else{
            if(s[ i ] == '1'){
                cout << "NO" << endl;
                return 0;
            }
        }
        now ^= (s[ i ] - '0');
    }
    cout << "YES" << endl;
    return 0;
}