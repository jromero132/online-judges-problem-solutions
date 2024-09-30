// Problem name: Maximizing Advertising
// Problem link: https://codeforces.com/gym/101879/problem/D
// Submission link: https://codeforces.com/gym/101879/submission/45337253

/*#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;
	if(m < (1 << n) - 1){
		cout << "N" << endl;
		return 0;
	}
	cout << 'Y' << endl;
	vector<char> peg = { 'A', 'B', 'C' };
	int q = m - (1 << n) + 1;
	for(int i = 2 ; i < q ; i += 2)
		cout << "A B" << endl << "B A" << endl;
	if(q & 1)
		cout << peg[ 0 ] << ' ' << peg[ 2 ] << endl;
	if(~n & 1)
		swap(peg[ 1 ], peg[ 2 ]);
	for(int m = 1, last = (1 << n) - 1 ; m <= last ; ++m)
		cout << peg[ (m - (m & -m)) % 3 ] << ' ' << peg[ (m + (m & -m)) % 3 ] << endl;
	return 0;
}*/

#include <bits/stdc++.h>

#define endl '\n'
#define S second
#define F first

using namespace std;

typedef long long ll;

struct st { int x, y; bool w;
bool operator < (const st &b) const
{
	return x < b.x;
}
};

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<st> a(n);
	char p;
	int cb = 0, cn = 0;
	for (auto &i : a)
	{
		cin >> i.x >> i.y >> p;
		i.w = p=='b';
		if (i.w)
			++cb;
		else
			++cn;
	}

	int ans = max(cb, cn);
	for (int it = 2; it--; )
	{
		sort(a.begin(), a.end());
		int tcb = 0, tcn = 0;

		for (auto &i : a)
		{
			if (i.w) ++tcb;
			else ++ tcn;

			ans = max(ans, max(tcb + cn-tcn, tcn + cb-tcb));
			swap(i.x, i.y);
		}
	}

	cout << ans;


	return 0;
}