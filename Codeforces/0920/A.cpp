// Problem name: Water The Garden
// Problem link: https://codeforces.com/contest/920/problem/A
// Submission link: https://codeforces.com/contest/920/submission/34952424

#include <bits/stdc++.h>

#define MAX ((int)41)
#define MOD ((int)1000000007)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define mod(x, y) (((x) % (y) + (y)) % (y))
#define POPCOUNT(x) __builtin_popcount(x)
#define gcd(a, b) __gcd(a, b)
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int t, n, m, ans, last, now;
    for(cin >> t ; t-- ; ){
        cin >> n >> m;
        cin >> last;
        ans = last;
        for(int i = 1 ; i < m ; i++){
            cin >> now;
            ans = max(ans, ((now - last) >> 1) + 1);
            last = now;
        }
        cout << max(ans, n - last + 1) << endl;
    }
	return 0;
}