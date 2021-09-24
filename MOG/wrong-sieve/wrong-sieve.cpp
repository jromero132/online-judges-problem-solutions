// Problem name: I - Wrong Sieve
// Problem link: https://matcomgrader.com/problem/9110/wrong-sieve/
// Submission link: https://matcomgrader.com/submission/117488/

#include <iostream>
#include <math.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t, n;
    for(cin >> t ; t ; t--){
        cin >> n;
        for(ll i = 1 ; ; i++){
            if(i + 1 > n){
                cout << i << endl;
                break;
            }
            if(!(n % (i + 1))){
                cout << -1 << endl;
                break;
            }
            n = (ll)(ceil((double)(n) * i / (i + 1)));
        }
    }
    return 0;
}