// Problem name: Guess the K-th Zero (Easy version)
// Problem link: https://codeforces.com/contest/1520/problem/F1
// Submission link: https://codeforces.com/contest/1520/submission/121147585

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
        if(sum >= k)
            right = middle;
        else
            left = middle + 1, k -= sum;
    }
    return right;
}

void update(map<pii, int> &segments, int n, int p, int v){
    int left = 1, right = n;
    segments[{ left, right }] += v;
    while(left < right){
        int middle = (left + right) >> 1;
        if(p <= middle)
            right = middle;
        else
            left = middle + 1;
        segments[{ left, right }] += v;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    map<pii, int> segment;
    for(cin >> n >> t ; t-- ; ){
        int k, pos;
        cin >> k;
        pos = find_kth_zero(segment, n, k);
        update(segment, n, pos, -1);
        cout << "! " << pos << endl << flush;
    }
    return 0;
}