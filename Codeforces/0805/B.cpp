// Problem name: 3-palindrome
// Problem link: https://codeforces.com/contest/805/problem/B
// Submission link: https://codeforces.com/contest/805/submission/26845763

#include <bits/stdc++.h>

#define MOD (int)(2e5 + 1)
#define MAX (int)(2e5 + 1)
#define INF (ll)(1e18)
#define EPS (double)(1e-7)
#define pb(x) push_back((x))
#define pf(x) push_front((x))
#define mp(x, y) make_pair((x), (y))
#define F first
#define S second
#define LEFT(i) ((i) << 1)
#define RIGHT(i) ((i) << 1 | 1)
#define FATHER(i) ((i) >> 1)
#define endl '\n'

#define MOD(a, b) (((a) % (b) + (b)) % (b))
#define FOR(i, n, m) for(int i = m ; i < n + m ; i++)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    char word[ MAX ];
    cin >> n;
    if(n == 1)
        cout << 'a';
    else{
        word[ 0 ] = word[ 1 ] = 'a';
        for(int i = 2 ; i < n ; i++){
            if(word[ i - 1 ] != word[ i - 2 ])
                word[ i ] = word[ i - 1 ];
            else
                word[ i ] = (word[ i - 1 ] == 'a' ? 'b' : 'a');
        }
        word[ n ] = '\0';
        cout << word;
    }
    return 0;
}