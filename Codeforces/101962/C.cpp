// Problem name: Renan and Cirque du Soleil
// Problem link: https://codeforces.com/gym/101962/problem/C
// Submission link: https://codeforces.com/gym/101962/submission/45149709

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define F first
#define S second

typedef vector<ll> vec;
typedef vector<vec> mat;

mat eye(int n)
{
	mat I(n, vec(n));
	for (int i = 0; i < n; ++i)
		I[i][i] = 1;
	return I;
}

mat mul(mat &A, mat &B, ll M)
{
	int l = A.size(), m = B.size(), n = B[0].size();
	mat C(l, vec(n));
	for (int i = 0; i < l; ++i)
		for (int k = 0; k < m; ++k)
			for (int j = 0; j < n; ++j)
				C[i][j] = (C[i][j] + (A[i][k] * B[k][j] % M) % M);
	return C;
}

mat pow(mat A, ll b, ll M)
{
	mat X = eye(A.size());
	for (; b > 0; b >>= 1)
	{
		if (b & 1) X = mul(X, A, M);
		A = mul(A, A, M);
	}
	return X;
}

const ll mod = 1e9+7;

int main()
{
	//freopen("a.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	vector<vector<ll>> m(4, vector<ll>(4));
	m[0] = { 1, 1, 1, 0 };
	m[1] = { 0, 1, 1, 0 };
	m[2] = { 0, 0, 2, 2 };
	m[3] = { 0, 0, 0, 2 };

	int t; ll n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (n == 1)
		{
			cout << "0\n";
			continue;
		}
		auto r = pow(m, n-1, mod);
		cout << (r[0][2]+r[0][3])%mod << "\n";
	}

	return 0;
}