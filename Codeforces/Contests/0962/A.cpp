// Problem name: Equator
// Problem link: https://codeforces.com/contest/962/problem/A
// Submission link: https://codeforces.com/contest/962/submission/37175774

#include <iostream>

#define MAX ((int)200001)

using namespace std;

int s[ MAX ];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, sum = 0, now = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> s[ i ], sum += s[ i ];
    for(int i = 0 ; i < n ; i++){
        now += s[ i ];
        if(now >= ((sum + 1) >> 1)){
            cout << ++i << endl;
            return 0;
        }
    }
    return 0;
}