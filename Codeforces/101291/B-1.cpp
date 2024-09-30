// Problem name: Barbells
// Problem link: https://codeforces.com/gym/101291/problem/B
// Submission link: https://codeforces.com/gym/101291/submission/37259938

#include <bits/stdc++.h>

#define MAX ((int)14)
#define pb push_back
#define endl '\n'

using namespace std;

int barbell[ MAX ], plate[ MAX ];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, sum1, sum2;
    vector<int> sums, ans;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
        cin >> barbell[ i ];
    for(int i = 0 ; i < m ; i++)
        cin >> plate[ i ];
    for(int mask = (1 << m) ; --mask ; ){
        sum1 = 0;
        for(int i = m ; --i >= 0 ; )
            if(mask & (1 << i))
                sum1 += plate[ i ];
        for(int maskC = mask ^ ((1 << m) - 1), submask = maskC ; submask ; submask = (submask - 1) & maskC){
            sum2 = 0;
            for(int i = m ; --i >= 0 ; )
                if(submask & (1 << i))
                    sum2 += plate[ i ];
            if(sum1 == sum2){
                sums.pb(sum1);
                break;
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        ans.pb(barbell[ i ]);
        for(int j = sums.size() ; --j >= 0 ; )
            ans.pb(barbell[ i ] + (sums[ j ] << 1));
    }
    sort(ans.begin(), ans.end());
    cout << ans[ 0 ] << endl;
    for(int i = 1 ; i < ans.size() ; i++)
        if(ans[ i ] != ans[ i - 1 ])
            cout << ans[ i ] << endl;
    return 0;
}