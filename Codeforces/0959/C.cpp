// Problem name: Mahmoud and Ehab and the wrong algorithm
// Problem link: https://codeforces.com/contest/959/problem/C
// Submission link: https://codeforces.com/contest/959/submission/36919985

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
//#define endl '\n'

using namespace std;

typedef unsigned int uint;
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
    cin >> n;
    if(n <= 5)
        cout << -1 << endl;
    else{
        for(int i = 2 ; i < n - 1 ; i++)
            cout << 1 << ' ' << i << endl;
        cout << 2 << ' ' << n - 1 << endl << 2 << ' ' << n << endl;
    }
    for(int i = 1 ; i < n ; i++)
        cout << i << ' ' << i + 1 << endl;
	return 0;
}