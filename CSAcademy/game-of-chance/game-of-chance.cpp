// Problem name: Game of Chance
// Problem link: https://csacademy.com/contest/archive/task/game-of-chance/
// Submission link: https://csacademy.com/submission/1407514/

#include <bits/stdc++.h>

#define MAX ((int)1000000)
#define MOD ((int)1000000007)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, a, b, v;
    cin >> n >> a >> b;
    for(int i = 0 ; i < n ; i++)
        cin >> v, a += v;
    for(int i = 0 ; i < n ; i++)
        cin >> v, b += v;
    cout << (a == b ? 0 : (a > b ? 1 : 2)) << endl;
    return 0;
}