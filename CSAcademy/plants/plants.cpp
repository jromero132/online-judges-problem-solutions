// Problem name: Plants
// Problem link: https://csacademy.com/contest/archive/task/plants/
// Submission link: https://csacademy.com/submission/1407496/

#include <bits/stdc++.h>

#define MAX ((int)100)
#define MOD ((int)1000000007)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'

using namespace std;

int room[ MAX ];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 0 ; i < m ; cin >> room[ i++ ]);
    sort(room, room + m);
    while(n--){
        cin >> a >> b;
        cout << upper_bound(room, room + m, b) - lower_bound(room, room + m, a) << endl;
    }
    return 0;
}