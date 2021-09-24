// Problem name: Johny Likes Numbers
// Problem link: https://codeforces.com/contest/678/problem/A
// Submission link: https://codeforces.com/contest/678/submission/25027669

#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, k;
    cin >> n >> k;
    cout << n + k - n % k << endl;
    return 0;
}