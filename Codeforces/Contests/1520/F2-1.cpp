// Problem name: Guess the K-th Zero (Hard version)
// Problem link: https://codeforces.com/contest/1520/problem/F2
// Submission link: https://codeforces.com/contest/1520/submission/121147612

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int get_sum(map<pii, int> &segment, int left, int right){
    pii range = { left, right };
    map<pii, int>::iterator it = segment.find(range);
    if(it != segment.end())
        return it -> second;

    cout << "? " << left << " " << right << endl << flush;
    int v;
    cin >> v;
    return segment[ range ] = right - left + 1 - v;
}

int find_kth_zero(map<pii, int> &segment, int n, int k){
    int left = 1, right = n;
    while(left < right){
        int middle = (left + right) >> 1;
        int sum = get_sum(segment, left, middle);
        --segment[{ left, right }];
        if(sum >= k)
            right = middle;
        else
            left = middle + 1, k -= sum;
    }
    --segment[{ left, right }];
    return right;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    map<pii, int> segment;
    for(cin >> n >> t ; t-- ; ){
        int k, pos;
        cin >> k;
        cout << "! " << find_kth_zero(segment, n, k) << endl << flush;
    }
    return 0;
}