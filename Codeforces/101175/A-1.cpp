// Problem name: To Add or to Multiply
// Problem link: https://codeforces.com/gym/101175/problem/A
// Submission link: https://codeforces.com/gym/101175/submission/34334432

#include <iostream>

#define MAX ((int)30)
#define MAX_NUMBER ((int)1000000000)
#define endl '\n'

using namespace std;

typedef long long ll;

ll a, m, p, q, r, s;
int case_number = 1;

string toString(int n){
	string ans = "";
	do{
		ans = (char)(n % 10 + '0') + ans;
		n /= 10;
	}while(n);
	return ans;
}

bool isLess(string a, string b){
	int value_a = 0, value_b = 0, len = min(a.length(), b.length()), p1 = 0, p2;
	while(p1 < len && a[ p1 ] == b[ p1 ])
		p1++;
	p2 = p1;
	while(--p1 >= 0 && a[ p1 ] != ' ');
	while(--p2 >= 0 && a[ p2 ] != ' ');
	p1++;
	p2++;
	while(a[ p1 ] != 'A' && a[ p1 ] != 'M')
		value_a *= 10, value_a += a[ p1++ ] - '0';
	while(b[ p2 ] != 'A' && b[ p2 ] != 'M')
		value_b *= 10, value_b += b[ p2++ ] - '0';
	return (a[ p1 ] == b[ p2 ] ? (a[ p1 ] == 'A' ? value_a > value_b : value_a < value_b) : a[ p1 ] == 'A');
}

void solve(){
	if(r <= p && s >= q){
		cout << "Case " << case_number++ << ": empty" << endl;
		return;
	}

	ll pot[ MAX ] = { 1 }, left, right, sum;
	for(int i = 1 ; i < MAX && (pot[ i ] = pot[ i - 1 ] * m) <= MAX_NUMBER ; i++);

	int ope, aux, len_ans, len_now;
	bool first;
	string ans = "", now;
	for(int i = 0 ; i < MAX && (right = s - q * pot[ i ]) >= 0 ; i++){
		sum = len_now = ope = 0;
		left = r - p * pot[ i ];
		left = left / a + ((left <= 0 || left % a == 0) ? 0 : 1);
		left = max(left, 0LL);
		right /= a;
		if(right < left)
			continue;
		now = "";
		first = 1;
		for(int j = 0 ; j <= i ; j++){
			if(sum + pot[ i - j ] > right){
				if(j != 0)
					ope++;
				continue;
			}
			aux = min((right - sum) / pot[ i - j ], (left - sum) / pot[ i - j ] + ((left - sum) % pot[ i - j ] == 0 ? 0 : 1));
			if(aux == 0){
				if(j != 0)
				ope++;
				continue;
			}
			if(j != 0){
				now += (!first ? " " : "") + toString(ope + 1) + "M";
				len_now += ope + 1;
				first = 0;
			}
			ope = aux;
			now += (!first ? " " : "") + toString(ope) + "A";
			first = 0;
			sum += ope * pot[ i - j ];
			len_now += ope;
			ope = 0;
			if(sum >= left){
				if(j != i){
					now += " " + toString(i - j) + "M";
					len_now += i - j;
				}
				break;
			}
		}
		if(sum >= left){
			if(ope){
				now += (!first ? " " : "") + toString(ope) + "M";
				len_now += ope;
			}
			if(ans == "" || (len_now < len_ans) || (len_now == len_ans && isLess(now, ans))){
				ans = now;
				len_ans = len_now;
			}
		}
	}
	cout << "Case " << (case_number++) << ": " << (ans == "" ? "impossible" : ans) << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while(cin >> a >> m >> p >> q >> r >> s && a)
		solve();
	return 0;
}