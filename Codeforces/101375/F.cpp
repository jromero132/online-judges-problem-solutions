// Problem name: MaratonIME educates
// Problem link: https://codeforces.com/gym/101375/problem/F
// Submission link: https://codeforces.com/gym/101375/submission/37112986

#include <bits/stdc++.h>

#define sqr(x) ((x) * (x))
#define endl '\n'

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int n, p, sum = 0;
    for(cin >> n ; n-- ; )
        cin >> p, sum += p;
    cout << (sum + 4) / 5 << endl;
	return 0;
}