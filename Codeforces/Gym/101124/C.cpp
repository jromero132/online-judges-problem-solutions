// Problem name: Old Chess Sets
// Problem link: https://codeforces.com/gym/101124/problem/C
// Submission link: https://codeforces.com/gym/101124/submission/21383651

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



string a,b;

map<string,int> total;

map<string,int> B1;
map<string,int> W1;
map<string,int> B2;
map<string,int> W2;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k1,k2;
	cin >> k1 >> k2;

	total["queen"] = 1;
	total["king"] = 1;
	total["bishop"] = 2;
	total["knight"] = 2;
	total["rook"] = 2;
	total["pawn"] = 8;

	W1["queen"] = 0;
	W1["king"] = 0;
	W1["bishop"] = 0;
	W1["knight"] = 0;
	W1["rook"] = 0;
	W1["pawn"] = 0;

	B1["queen"] = 0;
	B1["king"] = 0;
	B1["bishop"] = 0;
	B1["knight"] = 0;
	B1["rook"] = 0;
	B1["pawn"] = 0;

	W2["queen"] = 0;
	W2["king"] = 0;
	W2["bishop"] = 0;
	W2["knight"] = 0;
	W2["rook"] = 0;
	W2["pawn"] = 0;

	B2["queen"] = 0;
	B2["king"] = 0;
	B2["bishop"] = 0;
	B2["knight"] = 0;
	B2["rook"] = 0;
	B2["pawn"] = 0;

	for(int i = 0 ; i < k1; i++)
	{
		cin >> a >> b;
		if(a == "white")
			W1[b]++;
		else
			B1[b]++;
	}
	for(int i = 0 ; i < k2; i++)
	{
		cin >> a >> b;
		if(a == "white")
			W2[b]++;
		else
			B2[b]++;
	}
	for(map<string,int>::iterator i = B1.begin(); i != B1.end(); i++)
	{
		string piece = i ->first;
		int amount = i ->second;
		if(amount < total[piece])
		{
			int missing = total[piece] - amount;
			if(B2[piece] < missing)
			{
				cout << "impossible" << '\n';
				return 0;
			}
		}
	}
	for(map<string,int>::iterator i = W1.begin(); i != W1.end(); i++)
	{
		string piece = i ->first;
		int amount = i ->second;
		if(amount < total[piece])
		{
			int missing = total[piece] - amount;
			if(W2[piece] < missing)
			{
				cout << "impossible" << '\n';
				return 0;
			}
		}
	}


	for(map<string,int>::iterator i = B1.begin(); i != B1.end(); i++)
	{
		string piece = i ->first;
		int amount = i ->second;
		if(amount < total[piece])
		{
			int missing = total[piece] - amount;
			for(int j = 0 ; j < missing; j++)
			{
				cout << "black " << piece << endl;
			}
		}
	}

	for(map<string,int>::iterator i = W1.begin(); i != W1.end(); i++)
	{
		string piece = i ->first;
		int amount = i ->second;
		if(amount < total[piece])
		{
			int missing = total[piece] - amount;
			for(int j = 0 ; j < missing; j++)
			{
				cout << "white " << piece << endl;
			}
		}
	}



}