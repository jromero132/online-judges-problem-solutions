// Problem name: Distribution of Days
// Problem link: https://codeforces.com/gym/101522/problem/D
// Submission link: https://codeforces.com/gym/101522/submission/44089112

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

ll gregorian_to_julian(int d, int m, ll y){
	return 1461LL * (y + 4800LL + (m - 14LL) / 12LL) / 4LL +
			367LL * (m - 2LL - (m - 14LL) / 12LL * 12LL) / 12LL -
			3LL * ((y + 4900LL + (m - 14LL) / 12LL) / 100LL) / 4LL +
			d - 32075LL;
}

int day_of_week(ll jd){
	return (jd + 1) % 7 ;
}

inline bool is_leap_year(ll y){
	return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

inline bool is_valid(int d, int m, ll y){
	return d != 29 || m != 2 || is_leap_year(y);
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int q;
	for(cin >> q ; q-- ; ){
		ll y1, y2;
		int m, d;
		cin >> y1 >> y2 >> m >> d;
		vector<ll> days(7, 0);
		for(int i = 0 ; y1 <= y2 && i < 400 ; ++y1, ++i)
			if(is_valid(d, m, y1))
				++days[ day_of_week(gregorian_to_julian(d, m, y1)) ];
		if(y1 <= y2){
			ll q = (y2 - y1) / 400;
			for(auto &x : days)
				x += x * q;
			for(y1 += q * 400 ; y1 <= y2 ; ++y1)
				if(is_valid(d, m, y1))
					++days[ day_of_week(gregorian_to_julian(d, m, y1)) ];
		}
		for(auto &x : days)
			cout << x << " \n"[ &x == &days.back() ];
	}
	return 0;
}