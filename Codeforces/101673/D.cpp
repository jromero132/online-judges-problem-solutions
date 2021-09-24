// Problem name: Game of Throwns
// Problem link: https://codeforces.com/gym/101673/problem/D
// Submission link: https://codeforces.com/gym/101673/submission/37979677

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

stack<int> task;

int toInt(string s){
	int ans = 0, sign = (s[ 0 ] == '-' ? -1 : 1);
	for(int i = (s[ 0 ] == '-') ; s[ i ] ; i++)
		ans *= 10, ans += s[ i ] - 48;
	return sign * ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, q, m, cur = 0;
    cin >> n >> k;
    string s;
    while(k--){
    	cin >> s;
    	if(s[ 0 ] != 'u'){
    		m = toInt(s);
    		task.push(m);
    		cur = ((cur + m) % n + n) % n;
    	}
    	else{
    		cin >> q;
    		q = min(q, (int)task.size());
    		while(q--){
    			m = -task.top();
    			task.pop();
        		cur = ((cur + m) % n + n) % n;
    		}
    	}
    }
    cout << cur << endl;
}