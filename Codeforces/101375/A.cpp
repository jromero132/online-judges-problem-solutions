// Problem name: MaratonIME stacks popcorn buckets
// Problem link: https://codeforces.com/gym/101375/problem/A
// Submission link: https://codeforces.com/gym/101375/submission/37112914

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    ll n;
    cin >> n;
    cout << n * (n + 1) / 2 - n + 1 << endl;
	return 0;
}