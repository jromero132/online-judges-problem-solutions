// Problem name: Gift Set
// Problem link: https://codeforces.com/contest/1538/problem/G
// Submission link: https://codeforces.com/contest/1538/submission/121064965

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool can_make_gifts(ll k, ll x, ll y, ll a, ll b){
    ll left = 0, right = k, middle, v1, v2;
    while(left <= right){
        middle = (left + right) >> 1;
        v1 = a * middle + b * (k - middle);
        v2 = a * (k - middle) + b * middle;
        if(v1 <= x && v2 <= y)
            return 1;
        else if(v1 >= x && v2 >= y)
            return 0;
        else if(v1 >= x)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return 0;
}

ll get_max_gifts(ll x, ll y, ll a, ll b){
    ll left = 0, right = (x + y) / (a + b), middle;
    while(left <= right){
        middle = (left + right) >> 1;
        if(can_make_gifts(middle, x, y, a, b))
            left = middle + 1;
        else
            right = middle - 1;
    }
    return right;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    for(cin >> t ; t-- ; ){
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        if(a > b)
            swap(a, b);
        cout << get_max_gifts(x, y, a, b) << endl;
    }
    return 0;
}