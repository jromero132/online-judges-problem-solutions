// Problem name: E - Un problema muy difícil
// Problem link: https://matcomgrader.com/problem/239/un-problema-muy-dificil/
// Submission link: https://matcomgrader.com/submission/117604/

#include <iostream>
#include <vector>
#include <map>

#define mp(i, j) make_pair(i, j)
#define F first
#define S second
#define pb(x) push_back(x)
#define endl '\n'

using namespace std;

map< int, vector<int> > num;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k, v;
    cin >> n >> m;
    for(int i = 0 ; i < n ; cin >> v, num[ v ].pb(++i));
    while(m--)
        cin >> k >> v, cout << (num[ v ].size() >= k ? num[ v ][ k - 1 ] : 0) << endl;
}