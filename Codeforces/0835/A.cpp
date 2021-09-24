// Problem name: Key races
// Problem link: https://codeforces.com/contest/835/problem/A
// Submission link: https://codeforces.com/contest/835/submission/29140575

#include <iostream>

#define endl '\n'

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int s, v1, v2, t1, t2, first, second;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    first = (t1 << 1) + v1 * s;
    second = (t2 << 1) + v2 * s;
    cout << (first < second ? "First" : (first == second ? "Friendship" : "Second")) << endl;
    return 0;
}