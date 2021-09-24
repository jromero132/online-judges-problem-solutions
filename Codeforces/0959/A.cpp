// Problem name: Mahmoud and Ehab and the even-odd game
// Problem link: https://codeforces.com/contest/959/problem/A
// Submission link: https://codeforces.com/contest/959/submission/36909168

#include <bits/stdc++.h>

#define MAX ((int)300001)
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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int n;
    while(cin >> n)
        cout << ((n & 1) ? "Ehab" : "Mahmoud") << endl;
	return 0;
}