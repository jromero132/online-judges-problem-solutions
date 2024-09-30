// Problem name: Weird Rounding
// Problem link: https://codeforces.com/contest/779/problem/B
// Submission link: https://codeforces.com/contest/779/submission/25062816

#include <iostream>

using namespace std;

string s;
    int k;

int solve(){
    int zeroes = 0, ans = 0;
    for(int i = s.length() - 1 ; i > 0 ; i--){
        if(s[ i ] == '0')
            zeroes++;
        else
            ans++;
        if(zeroes == k)
            return ans;
    }
    return s.length() - 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> s >> k;
    cout << solve() << endl;
    return 0;
}