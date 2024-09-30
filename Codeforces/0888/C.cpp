// Problem name: K-Dominant Character
// Problem link: https://codeforces.com/contest/888/problem/C
// Submission link: https://codeforces.com/contest/888/submission/37915739

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int ans = 100000, d, now;
    for(int i = 0 ; s[ i ] ; i++){
    	if(s[ i ] == 1)
    		continue;
    	d = i + 1;
    	now = 1;
    	for(int j = i + 1 ; s[ j ] ; j++){
    		if(s[ j ] == s[ i ]){
    			s[ j ] = 1;
    			d = max(d, now);
    			now = 0;
    		}
    		now++;
    	}
    	ans = min(ans, d = max(d, now));
    }
    cout << ans << endl;
    return 0;
}