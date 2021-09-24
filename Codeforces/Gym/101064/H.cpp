// Problem name: Pop Divas
// Problem link: https://codeforces.com/gym/101064/problem/H
// Submission link: https://codeforces.com/gym/101064/submission/45257408

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define DB( x ) cout << #x << " = " << x << endl;
#define LEFT(n) (2 * (n))
#define RIGHT(n) (2 * (n) + 1)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef pair<ll, pii> piii;
typedef pair<pii, pii> piiii;
typedef pair<double, double> point;


//const ll MOD = (ll)(1e9 + 7);
const ll MAXV = (ll)(2e5 + 5);
const ll MAXE = (ll)(2e6 + 10);
const ll MAXLOG = (ll)(20);

typedef long double T;//tipo de las coordenadas long double, double, long long etc
typedef long double TT;//tipo de las magniutdes, precicion de angulos, distancias long double, double, etc
const TT EPS = 1e-16;
//const TT INF = (1e8 + 10);
#define M_PI 3.1415926535897932384626433832795
#define NEXT(i) (((i) + 1) % n)

ll INF = (ll)(1e14);

vector<ll> X, Y;
vector<TT> A, B;
map <ll, ll> M;

int main(){
	ios_base::sync_with_stdio(0);cin.tie( 0 );

	int n, m;

	cin >> n >> m;
	A.resize(n), B.resize(m);
	X.resize(n), Y.resize(m);
	for(int i = 0;i < n;i ++){
		ll num;
		cin >> num;
		A[i] = log2l(num);
		X[i] = num;
	}
	for(int i = 0;i < m;i ++){
		ll num;
		cin >> num;
		B[i] = log2l(num);
		Y[i] = num;
	}

	for(ll mask = 1LL;mask < (1LL << n);mask ++){
		TT sum = 0.0;
		for(ll j = 0;j < n;j ++)
			if(mask & (1LL << j))
				sum += A[j];
		M[ll(sum * INF)] = mask;
	}

	for(ll mask = 1LL;mask < (1LL << m);mask ++){
		TT sum = 0.0;
		for(ll j = 0;j < m;j ++)
			if(mask & (1LL << j))
				sum += B[j];
		ll curr = ll(sum * INF);
		if(M.find(curr) != M.end()){
			ll mask_A = M[curr];
			cout << "Y\n";
			vector <ll> ans_A, ans_B;
			for(ll j = 0;j < n;j ++)
				if(mask_A & (1LL << j))
					ans_A.push_back(X[j]);
			for(ll j = 0;j < m;j ++)
				if(mask & (1LL << j))
					ans_B.push_back(Y[j]);

			cout << ans_A.size() << " " << ans_B.size() << "\n";

			cout << ans_A[0];
			for(int i = 1;i < ans_A.size();i ++)
				cout << " " << ans_A[i];cout << "\n";
			cout << ans_B[0];
			for(int i = 1;i < ans_B.size();i ++)
				cout << " " << ans_B[i];cout << "\n";
			return 0;
		}
	}

	cout << "N\n";

	return 0;
}