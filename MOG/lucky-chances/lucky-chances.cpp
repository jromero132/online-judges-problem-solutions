// Problem name: L - Lucky Chances
// Problem link: https://matcomgrader.com/problem/9278/lucky-chances/
// Submission link: https://matcomgrader.com/submission/120001/

#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>,
        rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int tab[105][105];
int n, m;

int solve(int i, int j){
    int ans = 0;
    bool ok = 1;
    for(int k = i - 1 ; k >= 0 ; k--)
        if(tab[ k ][ j ] >= tab[ i ][ j ]){
            ok = 0;
            break;
        }
    ans += ok;
    ok = 1;
    for(int k = j - 1 ; k >= 0 ; k--)
        if(tab[ i ][ k ] >= tab[ i ][ j ]){
            ok = 0;
            break;
        }
    ans += ok;
    ok = 1;
    for(int k = i + 1 ; k <= n ; k++)
        if(tab[ k ][ j ] >= tab[ i ][ j ]){
            ok = 0;
            break;
        }
    ans += ok;
    ok = 1;
    for(int k = j + 1 ; k <= m ; k++)
        if(tab[ i ][ k ] >= tab[ i ][ j ]){
            ok = 0;
            break;
        }
    return ans + ok;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            cin >> tab[ i ][ j ];
    int ans = 0;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            ans += solve(i, j);
    cout << ans;
}