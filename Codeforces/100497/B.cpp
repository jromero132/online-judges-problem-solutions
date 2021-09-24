// Problem name: Palindrome
// Problem link: https://codeforces.com/gym/100497/problem/B
// Submission link: https://codeforces.com/gym/100497/submission/21239206

#include <bits/stdc++.h>

using namespace std;

#define DB( x ) cout << #x << " = " << x << endl;
#define LEFT(n) (2 * (n))
#define RIGHT(n) (2 * (n) + 1)
#define X real()
#define Y imag()

typedef long long ll;
typedef pair<int, int> node;
//typedef complex<double> P;

const ll INF = 1e9;
const double EPS = 1e-6;
const ll MOD = (ll)(1e5);
const ll MAXV = (ll)(1e5 + 1000);
const ll MAXE = (ll)(1e6 + 10);

string a;

vector<char> v;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a;

	int l1 = 0;
	int l2 = a.size() - 1;

	int dif = 0;

	int p1 = 0;
	int p2 = 0;
	int p3 = 0;
	int p4 = 0;

	while(l1 <= l2){
		if(a[l1] != a[l2]){
			dif++;
			if(dif > 2)break;
			if(dif == 1){
				p1 = l1;
				p2 = l2;
			}
			else{
				p3 = l1;
				p4 = l2;
			}
		}
		l1++;
		l2--;
	}

	if(dif == 0){
		cout << 1 << endl;
		cout << a << endl;
	}
	else if(dif == 2)
	{

		v.push_back(a[p1]);
		v.push_back(a[p2]);
		v.push_back(a[p3]);
		v.push_back(a[p4]);

		sort(v.begin(),v.end());

		if(v[0] != v[1] || v[2] != v[3])
		{
			cout << 0 << endl;
			return 0;
		}
		cout << 2 << endl;
		string b = "";
		string c = "";

		if(a[p1] == a[p3])
		{
			for(int i = 0 ; i < a.size(); i++){
				if(i == p1)
				{
					b += a[p4];
				}
				else if(i == p4)
				{
					b += a[p1];
				}
				else
					b += a[i];
			}

			for(int i = a.size() - 1 ; i >= 0; i--){
				if(i == p2)
				{
					c += a[p3];
				}
				else if(i == p3)
				{
					c += a[p2];
				}
				else c += a[i];
			}
		}
		else
		{
			for(int i = 0 ; i < a.size(); i++){
				if(i == p1)
				{
					b += a[p3];
				}
				else if(i == p3)
				{
					b += a[p1];
				}
				else
					b += a[i];
			}

			for(int i = a.size() - 1 ; i >= 0; i--){
				if(i == p2)
				{
					c += a[p4];
				}
				else if(i == p4)
				{
					c += a[p2];
				}
				else c += a[i];
			}
		}


		cout << min(b,c) << endl;
		cout << max(b,c) << endl;

	}
	else if(dif == 1)
	{
		if(a.size() % 2 == 0)
			cout << 0 << endl;
		else
		{
			string solve = "";
			if(a[a.size() / 2] == a[p1]){
				cout << 1 << endl;
				for(int i = 0 ; i < a.size(); i++)
				{
					if(i == a.size() / 2)
						solve += a[p2];
					else if(i == p2)
						solve += a[a.size()/2];
					else solve += a[i];
				}
				cout << solve << endl;
			}
			else if(a[a.size() / 2] == a[p2]){
				cout << 1 << endl;
				for(int i = 0 ; i < a.size(); i++)
				{
					if(i == a.size()/2)
						solve += a[p1];
					else if(i == p1)
						solve += a[a.size()/2];
					else
						solve += a[i];
				}
				cout << solve << endl;
			}
			else cout << 0 << endl;
		}
	}
	else cout << 0 << endl;


	return 0;
}