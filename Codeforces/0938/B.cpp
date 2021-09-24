// Problem name: Run For Your Prize
// Problem link: https://codeforces.com/contest/938/problem/B
// Submission link: https://codeforces.com/contest/938/submission/35343779

#include <bits/stdc++.h>

#define MAX ((int)1000001)
#define MAX_DIG ((int)10)
#define pb push_back
#define mp make_pair
#define endl '\n'

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int n, ans1 = 1, ans2 = 1000000, m = 1000000 >> 1, q;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> q;
        if(q <= m)
            ans1 = max(ans1, q);
        else
            ans2 = min(ans2, q);
    }
    cout << max(ans1 - 1, 1000000 - ans2);
	return 0;
}