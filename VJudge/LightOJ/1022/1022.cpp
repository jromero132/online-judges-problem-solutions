// Problem name: Circle in Square
// Problem link: https://vjudge.net/problem/LightOJ-1022
// Submission link: https://vjudge.net/solution/32878071

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const double rem = 4 - 2 * acos(0);
	int t;
	cin >> t;
	for(int k = 1 ; k <= t ; ++k){
		double r;
		cin >> r;
		cout << setprecision(2) << "Case " << k << ": " << fixed << rem * r * r << endl;
	}
}