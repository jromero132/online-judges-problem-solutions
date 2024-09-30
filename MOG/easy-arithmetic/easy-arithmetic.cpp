// Problem name: E - Easy Arithmetic
// Problem link: https://matcomgrader.com/problem/9272/easy-arithmetic/
// Submission link: https://matcomgrader.com/submission/120040/

#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>,
        rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, ans = "";
    cin >> s;
    int len = s.length();
    for(int i = 0 ; i < len ; i++){
        if(s[ i ] == '-'){
            if(i + 2 < len && s[ i + 2 ] >= 48 && s[ i + 2 ] <= 57){
                ans += '-', ans += (char)(s[ ++i ]), ans += '+';
                for(i++ ; i < len && s[ i ] == '0' ; i++){
                    ans += s[ i ];
                    if(i + 1 < len && s[ i + 1 ] >= 48 && s[ i + 1 ] <= 57)
                        ans += '+';
                }
                i--;
            }
            else
                ans += '-';
        }
        else
            ans += s[ i ];
    }
    cout << ans << endl;
}