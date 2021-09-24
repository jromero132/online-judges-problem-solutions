// Problem name: Packmen
// Problem link: https://codeforces.com/contest/847/problem/E
// Submission link: https://codeforces.com/contest/847/submission/31002111

#include <bits/stdc++.h>

#define INF (int)((1 << 31) - 1)
#define pb(x) push_back(x)
#define endl '\n'

using namespace std;

int P, A;
vector<int> pacman, asterisk;

int solve(){
    int left = 0, right = INF, mid, p, l, r;
    while(left < right){
        mid = (left + right) >> 1;
        p = 0;
        for(int i = 0 ; i < P ; i++){
            l = r = pacman[ i ];
            while(p < A){
                l = min(l, asterisk[ p ]);
                r = max(r, asterisk[ p ]);
                if(r - l + min(r - pacman[ i ], pacman[ i ] - l) > mid)
                    break;
                p++;
            }
        }
        if(p == A)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    int n;
    string board;
    cin >> n >> board;
    for(int i = 0 ; i < n ; i++){
        if(board[ i ] == 'P')
            pacman.pb(i), P++;
        else if(board[ i ] == '*')
            asterisk.pb(i), A++;
    }
    cout << solve();
	return 0;
}