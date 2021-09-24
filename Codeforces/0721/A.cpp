// Problem name: One-dimensional Japanese Crossword
// Problem link: https://codeforces.com/contest/721/problem/A
// Submission link: https://codeforces.com/contest/721/submission/21053082

#include <bits/stdc++.h>

#define pb(n) push_back(n)

using namespace std;

typedef long long ll;

vector<int> vals;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, groups = 0, now;
	string s;
	cin >> n >> s;
	groups = now = (s[ 0 ] == 'W' ? 0 : 1);
	bool ya = (s[ 0 ] == 'B');
	for(int i = 1 ; s[ i ] != '\0' ; i++){
        if(s[ i ] == 'B'){
            now++;
            if(!ya)
                groups++;
            ya = true;
        }
        if(s[ i ] == 'W' && now)
            vals.pb(now), ya = false, now = 0;
	}
	if(now)
        vals.pb(now);
	cout << groups << endl;
	if(vals.size()){
        cout << vals[ 0 ];
        for(int i = 1 ; i < vals.size() ; i++)
            cout << " " << vals[ i ];
    }
}