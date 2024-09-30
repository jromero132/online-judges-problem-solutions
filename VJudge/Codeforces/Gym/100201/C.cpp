// Problem name: Yellow Code
// Problem link: https://vjudge.net/problem/Gym-100201C
// Submission link: https://vjudge.net/solution/13138145

#include <bits/stdc++.h>

#define MAX ((int)(1 << 12))
#define POPCOUNT __builtin_popcount
#define endl '\n'

using namespace std;

int n, n2, s, num[ MAX ];
bool check[ MAX ];

bool solve(int p){
    if(p == s){
        if(POPCOUNT(num[ 0 ] ^ num[ p - 1 ]) < (n >> 1))
            return 0;
        for(int i = 0 ; i < s ; cout << endl, i++){
            for(int j = 0 ; j < n ; j++)
                cout << (num[ i ] & (1 << j) ? 1 : 0);
        }
        return 1;
    }
    int now, subset, lo, lz;
    bool ans = 0;
    now = (~num[ p - 1 ]) & (s - 1);
    if(!check[ now ]){
        check[ now ] = 1;
        num[ p ] = now;
        ans = solve(p + 1);
        check[ now ] = 0;
    }
    for(int k = 1 ; k <= n2 ; k++){
        subset = (1 << k) - 1;
        while(!(subset & s)){
            now = (num[ p - 1 ] ^ (~subset)) & (s - 1);
            if(!check[ now ]){
                check[ now ] = 1;
                num[ p ] = now;
                ans = ans || solve(p + 1);
                check[ now ] = 0;
            }
            lo = subset & (~(subset - 1));
            lz = (subset + lo) & (~subset);
            subset |= lz;
            subset &= (~(lz - 1));
            subset |= (lz / lo / 2) - 1;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("code.in", "r", stdin);
    freopen("code.out", "w", stdout);
    cin >> n;
    n2 = (n + 1) >> 1;
    s = (1 << n);
    num[ 0 ] = 0;
    check[ 0 ] = 1;
    if(!solve(1))
        cout << -1 << endl;
    return 0;
}