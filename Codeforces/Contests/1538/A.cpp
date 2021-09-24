// Problem name: Stone Game
// Problem link: https://codeforces.com/contest/1538/problem/A
// Submission link: https://codeforces.com/contest/1538/submission/121043805

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    for(cin >> t ; t-- ; ){
        int n, min_pos = 0, max_pos = 0;
        cin >> n;
        int v[ n ];
        for(int i = 0 ; i < n ; ++i){
            cin >> v[ i ];
            if(v[ i ] < v[ min_pos ])
                min_pos = i;
            if(v[ i ] > v[ max_pos ])
                max_pos = i;
        }
        if(min_pos > max_pos)
            swap(min_pos, max_pos);
        cout << min(max_pos + 1, min(n - min_pos, min_pos + 1 + n - max_pos)) << endl;
    }
    return 0;
}