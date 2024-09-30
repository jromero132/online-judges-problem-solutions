// Problem name: H - Hash Code Hacker
// Problem link: https://matcomgrader.com/problem/9274/hash-code-hacker/
// Submission link: https://matcomgrader.com/submission/120081/

#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>,
        rb_tree_tag, tree_order_statistics_node_update> ordered_set;

/*int calc(string s){
    long long h = 0;
    int t = s.size();
    for(int i = 0;i < t;i ++){
        h += s[i] * pow(31LL, t - 1LL - i);
    }
    return h;
}*/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;

    cin >> k;

    string aux;

    for(int i = 0;i < k;i ++){
        for(int j = 0;j < 10;j ++){
            if(i & (1 << j))
                cout << "ed";
            else
                cout << "fE";
        }
        //cout << calc(aux) << "\n";
        cout << aux << "\n";
    }

}
//-703-15-40-4000000000000001