// Problem name: A - Potenciales Palíndromos
// Problem link: https://matcomgrader.com/problem/9237/potenciales-palindromos/
// Submission link: https://matcomgrader.com/submission/120599/

#include <bits/stdc++.h>

#define MOD (int)(1e7 + 9)
#define mod(x) (((x) % MOD + MOD) % MOD)
#define endl '\n'

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int t, len1, len2;
    ll ans;
    string s;
    for(cin >> t ; t ; t--){
        cin >> s;
        ans = 1;
        len1 = s.length() - 1;
        len2 = (len1 >> 1) + 1;
        for(int i = 0 ; i < len2 ; i++){
            if(s[ i ] == '?' && s[ len1 - i ] == '?')
                ans = mod(26 * ans);
            else if(s[ i ] != '?' && s[ len1 - i ] != '?' && s[ i ] != s[ len1 - i ])
                ans = 0;
        }
        cout << ans << endl;
    }
	return 0;
}