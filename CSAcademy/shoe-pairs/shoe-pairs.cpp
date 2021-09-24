// Problem name: Shoe Pairs
// Problem link: https://csacademy.com/contest/archive/task/shoe-pairs/
// Submission link: https://csacademy.com/submission/1296577/

#include <iostream>

#define MAX ((int)(1e3 + 1))

using namespace std;

int left_shoe[ MAX ], right_shoe[ MAX ];

int main() {
    int n, v, ans = 0;
    char c;
    for(cin >> n ; n-- ; ){
        cin >> v >> c;
        ans -= min(left_shoe[ v ], right_shoe[ v ]);
        if(c == 'L')
            left_shoe[ v ]++;
        else
            right_shoe[ v ]++;
        ans += min(left_shoe[ v ], right_shoe[ v ]);
    }
    cout << ans;
    return 0;
}