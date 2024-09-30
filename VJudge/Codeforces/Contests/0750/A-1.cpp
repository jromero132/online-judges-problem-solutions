// Problem name: New Year and Hurry
// Problem link: https://vjudge.net/problem/CodeForces-750A
// Submission link: https://vjudge.net/solution/32909193

#include <bits/stdc++.h>

using namespace std;

int lowerbound(int left, int right, const function<bool(int)> &f){
    for(int middle = left + (right - left) / 2 ; left < right ; middle = left + (right - left) / 2){
        if(f(middle))
            right = middle;
        else
            left = middle + 1;
    }
    return left;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k, k = 240 - k;
	auto f = [k](int mid){
		return 5 * mid * (mid + 1) / 2 > k;
	};
	cout << lowerbound(1, n + 1, f) - 1 << endl;
	return 0;
}