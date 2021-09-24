// Problem name: Diverse Team
// Problem link: https://codeforces.com/contest/988/problem/A
// Submission link: https://codeforces.com/contest/988/submission/38863392

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

map<int, int> student;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k, n, v;
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++)
        cin >> v, student[ v ] = i;
    if(student.size() < k)
        cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        for(auto v : student){
            cout << v.second << ' ';
            if(!(--k))
                break;
        }
    }
    return 0;
}