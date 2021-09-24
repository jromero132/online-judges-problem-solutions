// Problem name: Swap Adjacent Elements
// Problem link: https://codeforces.com/contest/920/problem/C
// Submission link: https://codeforces.com/contest/920/submission/34954467

#include <bits/stdc++.h>

#define MAX ((int)200001)
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

int num[ MAX ], sum[ MAX ];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int n;
    string s;
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        cin >> num[ i ];
    cin >> s;
    for(int i = 1 ; i < n ; i++)
        sum[ i ] = sum[ i - 1 ] + (s[ i - 1 ] == '1');
    sum[ n ] = sum[ n - 1 ];
    for(int i = 1 ; i <= n ; i++){
        if(num[ i ] == i)
            continue;
        //cout << i << ' ' << num[ i ] << ' ' << sum[ i ] << ' ' << sum[ num[ i ] ] << ' ' << sum[ max(i, num[ i ]) ] << ' ' << sum[ min(i, num[ i ]) - 1 ] + abs(num[ i ] - i) << endl;
        if(sum[ max(i, num[ i ]) - 1 ] != sum[ min(i, num[ i ]) - 1 ] + abs(num[ i ] - i)){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
	return 0;
}