// Problem name: A - Igualando Lista
// Problem link: https://matcomgrader.com/problem/9203/igualando-lista/
// Submission link: https://matcomgrader.com/submission/117014/

#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;

typedef pair<int,int> pii;
typedef long long int64;

const int MAXN = 200010;

int a[MAXN];
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> a[i];

	sort(a, a + N);
	int64 ans = 0;
	for(int i = 0; i < N; i++)
		ans += abs(a[N/2] - a[i]);

	cout<<ans<<endl;

	return 0;
}