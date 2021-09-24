// Problem name: Passwords
// Problem link: https://codeforces.com/contest/721/problem/B
// Submission link: https://codeforces.com/contest/721/submission/21053174

#include <bits/stdc++.h>

#define pb(n) push_back(n)
#define MAX (int)(1e2 + 5)

using namespace std;

typedef long long ll;

int array[ MAX ];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, f, m1 = 0, m2 = 0, now = 0, l;
	string s;
	cin >> n >> f;
	for(int i = 0 ; i < n ; i++)
        cin >> s, array[ s.length() ]++;
    cin >> s;
    l = s.length();
    for(int i = 1 ; i < MAX ; i++){
        if(i == l){
            m1++;
            m2 += ((now + array[ i ] - 1) / f) * 5 + array[ i ];
            break;
        }
        else{
            now += array[ i ];
            m1 = m2 += (now / f) * 5 + array[ i ];
            now %= f;
        }
    }
    cout << m1 << " " << m2 << endl;
}