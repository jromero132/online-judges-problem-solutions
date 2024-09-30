// Problem name: XorShift
// Problem link: https://vjudge.net/problem/AtCoder-arc084_d
// Submission link: https://vjudge.net/solution/32881767

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_BITS = 4001;

struct pol{
	bitset<MAX_BITS> c;
	int grade = 0;

	bool operator<=(const pol &q){
		if(this -> grade != q.grade)
			return (this -> grade) < q.grade;
		for(int i = (this -> grade) - 1 ; i >= 0 ; --i)
			if((this -> c[ i ]) ^ q.c[ i ])
				return q.c[ i ];
		return true;
	}

	pol operator%(const pol &q){
		pol d, r = *this;
		for(int i = (this -> grade) - q.grade ; i >= 0 ; --i)
			if(r.c[ q.grade + i ])
				r.c ^= q.c << i;
		r.update_grade();
		return r;
	}

	void update_grade(){
		this -> grade = 0;
		for(int i = c.size() - 1 ; i >= 0 ; --i){
			if(this -> c[ i ]){
				this -> grade = i;
				break;
			}
		}
	}
};

pol gcd(pol p, pol q){
	while(q.c.any()){
		pol r = p % q;
		p = q;
		q = r;
	}
	return p;
}

int pow(int n, int b, int mod){
	int ans = 1;
	while(b){
		if(b & 1)
			ans = ((ll)ans * n) % mod;
		n = ((ll)n * n) % mod;
		b >>= 1;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int MOD = 998244353;

	int n;
	pol x;
	cin >> n >> x.c, x.update_grade();
	vector<pol> a(n);
	pol d;
	for(pol y ; n-- ; )
		cin >> y.c, y.update_grade(), d = gcd(d, y);
	int ans = 0;
	pol k;
	for(int i = x.grade - d.grade, bit ; i >= 0 ; --i){
		bit = d.grade + i;
		if(x.c[ bit ])
			ans = (ans + pow(2, i, MOD)) % MOD;
		if(x.c[ bit ] ^ k.c[ bit ]){
			k.c ^= d.c << i;
			if(k.grade == 0)
				k.grade = d.grade + i;
		}
	}
	cout << (ans + (k <= x)) % MOD;
	return 0;
}