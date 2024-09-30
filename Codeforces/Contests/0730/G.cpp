// Problem name: Car Repair Shop
// Problem link: https://codeforces.com/contest/730/problem/G
// Submission link: https://codeforces.com/contest/730/submission/30812781

#include <bits/stdc++.h>

using namespace std;

#define DB( x ) cout << #x << " = " << x << endl;
#define LEFT(n) (2 * (n))
#define RIGHT(n) (2 * (n) + 1)

typedef long long ll;
typedef pair<ll, ll> node;
typedef pair<double, double> P;

const ll INF = 1e9;
const double EPS = 1e-9;
const ll MOD = (ll)(2e9 + 99);
const ll MAX = (ll)(200000 + 10);
const ll MAXE = (ll)(1e6 + 10);

struct cmp{
	bool operator()(const node &a, const node &b){
		return a.first + a.second <= b.first + b.second;
	}
};

int n;

set <node, cmp> S;

bool check(node curr){
	ll curr_a, curr_b;
	ll a, b;

	curr_a = curr.first;
	curr_b = curr_a + curr.second;

	for(set <node, cmp> :: iterator it = S.begin();it != S.end();it ++){
		a = it -> first;
		b = a + it -> second;

		if(!(b < curr_a || a > curr_b))
			return false;
	}
	return true;
}

int main(){
	cin.sync_with_stdio( 0 );cin.tie( 0 );

	cin >> n;

	for(int i = 0;i < n;i ++){
		ll a, b;
		cin >> a >> b;
		b --;
		S.insert(node(-1, 1));

		if(check(node(a, b))){
			S.insert(node(a, b));
			cout << a << " " << a + b << "\n";
		}
		else{
			for(set <node, cmp> :: iterator it = S.begin();it != S.end();it ++){
				ll na;
				na = it ->first + it ->second + 1;
				if(check(node(na, b))){
					S.insert(node(na, b));
					cout << na << " " << na + b << "\n";
					break;
				}
			}
		}
	}



	return 0;
}