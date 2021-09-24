// Problem name: Odd Divisor Count
// Problem link: https://csacademy.com/contest/archive/task/odd-divisor-count/
// Submission link: https://csacademy.com/submission/1407464/

#include <bits/stdc++.h>

#define MAX ((int)1000000)
#define MOD ((int)1000000007)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a, b, ans = 0, div;
    cin >> a >> b;
    for( ; a <= b ; a++){
        div = (a == 1 ? 1 : 2);
        for(int j = 2 ; j * j <= a ; j++)
            if(!(a % j)){
                div++;
                if(a != j * j)
                    div++;
            }
        if(div & 1)
            ans++;
    }
    cout << ans << endl;
    return 0;
}