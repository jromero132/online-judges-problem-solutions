// Problem name: MaratonIME doesn't like odd numbers
// Problem link: https://codeforces.com/gym/101375/problem/L
// Submission link: https://codeforces.com/gym/101375/submission/37113320

#include <bits/stdc++.h>

#define INF ((int)10000)
#define endl '\n'

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int n, sum = 0, odd = INF, v;
    for(cin >> n ; n-- ; ){
        cin >> v;
        sum += v;
        if(v & 1)
            odd = min(odd, v);
    }
    cout << (sum & 1 ? sum - odd : sum) << endl;
	return 0;
}