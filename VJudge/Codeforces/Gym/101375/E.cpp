// Problem name: MaratonIME does (not do) PAs
// Problem link: https://vjudge.net/problem/Gym-101375E
// Submission link: https://vjudge.net/solution/13406275

#include <bits/stdc++.h>

#define MAX ((int)100000)
#define mp make_pair
#define F first
#define S second
#define endl '\n'

using namespace std;

typedef long long ll;

pair<int, int> task[ MAX ];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int n;
    ll s, ans = 0;
    cin >> n >> s;
    for(int i = 0 ; i < n ; i++)
        cin >> task[ i ].F >> task[ i ].S;
    sort(task, task + n);
    for(int i = 0 ; i < n ; i++){
        if(s + task[ i ].F > task[ i ].S)
            ans += s + task[ i ].F - task[ i ].S;
        s += task[ i ].F;
    }
    cout << ans << endl;
	return 0;
}