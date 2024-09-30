// Problem name: B - Black and White
// Problem link: https://matcomgrader.com/problem/9268/black-and-white/
// Submission link: https://matcomgrader.com/submission/120030/

#include <bits/stdc++.h>

#define MAX_ROW (int)(2)
#define MAX_COL (int)(2e3)
#define endl '\n'

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>,
        rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int a, b;

char tab[ 2 ][ 2000 ];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;

    char men, may;

    may = '@';
    men = '.';

    if(b > a){
        swap(a, b);
        swap(may, men);
    }
    for(int i = 0 ; i < MAX_ROW ; i++)
        for(int j = 0 ; j < MAX_COL ; j++)
            tab[ i ][ j ] = men;

    for(int j = 1, cnt = 0 ; cnt < a ; cnt++, j += 2)
        tab[ 0 ][ j ] = may;

    for(int j = 1, cnt = 1 ; cnt < b ; cnt++, j += 2)
        tab[ 1 ][ j ] = may;

    cout <<  MAX_ROW << " " << MAX_COL << endl;
    for(int i = 0 ; i < MAX_ROW ; i++){
        for(int j = 0 ; j < MAX_COL ; j++)
            cout << tab[ i ][ j ];
        cout << endl;
    }
}