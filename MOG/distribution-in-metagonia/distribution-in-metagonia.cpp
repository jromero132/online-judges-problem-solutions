// Problem name: D - Distribution in Metagonia
// Problem link: https://matcomgrader.com/problem/9269/distribution-in-metagonia/
// Submission link: https://matcomgrader.com/submission/120164/

#include <bits/stdc++.h>

#define pb(x) push_back(x)
#define endl '\n'

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>,
        rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    ll n, aux;
    vector<ll> num;
    for(cin >> t ; t ; t--){
        cin >> n;
        num.clear();
        aux = 1;
        while(n >= 1){
            while(!(n & 1))
                aux <<= 1LL, n >>= 1LL;
            while(!(n % 3))
                n /= 3, aux *= 3;
            ll aux2 = 1;
            while(aux2 * 3 <= n)
                aux2 *= 3;
            num.pb(aux * aux2);
            n -= aux2;
        }
        cout << num.size() << endl;
        for(int i = 0 ; i < num.size() ; i++)
            cout << (i ? " " : "") << num[ i ];
        cout << endl;
    }
    return 0;
}