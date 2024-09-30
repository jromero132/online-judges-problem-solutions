// Problem name: Contest Score
// Problem link: https://codeforces.com/gym/101291/problem/E
// Submission link: https://codeforces.com/gym/101291/submission/37260079

#include <bits/stdc++.h>

#define MAX ((int)100001)
#define endl '\n'

using namespace std;

typedef long long ll;

priority_queue< int, vector<int>, greater<int> > order;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, v;
    ll ans = 0, sum = 0;
    cin >> n >> k;
    for(int i = 0 ; i < k ; i++)
        cin >> v, order.push(v);
    for(int i = k ; i < n ; i++){
        ans += sum + order.top();
        sum += order.top();
        order.pop();
        cin >> v;
        order.push(v);
    }
    while(!order.empty()){
        ans += sum + order.top();
        sum += order.top();
        order.pop();
    }
    cout << ans << endl;
    return 0;
}