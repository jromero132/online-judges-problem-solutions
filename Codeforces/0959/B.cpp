// Problem name: Mahmoud and Ehab and the message
// Problem link: https://codeforces.com/contest/959/problem/B
// Submission link: https://codeforces.com/contest/959/submission/36914999

#include <bits/stdc++.h>

#define MAX ((int)100005)
#define INF ((int)((1 << 31) - 1))
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define DAD(x) ((x) >> 1)
#define LEFT(x) ((x) << 1)
#define RIGHT(x) ((x) << 1 | 1)
#define endl '\n'

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;

string word[ MAX ];
int cost[ MAX ];
uint minimum[ MAX ];
map<string, int> group;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int n, m, k, l, v;
    string s;
    cin >> n >> k >> m;
    for(int i = 0 ; i < n ; i++)
        cin >> word[ i ];
    for(int i = 0 ; i < n ; i++)
        cin >> cost[ i ];
    memset(minimum, -1, sizeof(minimum));
    for(int j = 0 ; j < k ; j++){
        cin >> l;
        for(int i = 0 ; i < l ; i++){
            cin >> v, v--;
            group[ word[ v ] ] = j;
            minimum[ j ] = min(minimum[ j ], (uint)cost[ v ]);
        }
    }
    ll ans = 0;
    for(int i = 0 ; i < m ; i++){
        cin >> s;
        ans += minimum[ group[ s ] ];
    }
    cout << ans << endl;
	return 0;
}