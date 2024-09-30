// Problem name: Merge Equals
// Problem link: https://codeforces.com/contest/962/problem/D
// Submission link: https://codeforces.com/contest/962/submission/37167847

#include <bits/stdc++.h>

#define MAX ((int)150001)
#define mp make_pair
#define F first
#define S second
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair< ll, pair<int, int> > plii;

ll num[ MAX ];

map< ll, priority_queue< int, vector<int>, greater<int> > > aux;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, s;
    cin >> n;
    s = n;
    for(int i = 0 ; i < n ; i++){
        cin >> num[ i ];
        aux[ num[ i ] ].push(i);
    }
    priority_queue< int, vector<int>, greater<int> > pos;
    int len, p1, p2;
    for(auto it = aux.begin() ; it != aux.end() ; it++){
        pos = it -> S;
        len = pos.size();
        while(len >= 2){
            p1 = pos.top();
            pos.pop();
            p2 = pos.top();
            pos.pop();
            len -= 2;
            num[ p1 ] = -1;
            num[ p2 ] <<= 1LL;
            s--;
            aux[ num[ p2 ] ].push(p2);
        }
    }
    cout << s << endl;
    for(int i = 0 ; i < n ; i++)
        if(num[ i ] != -1)
            cout << num[ i ] << ' ';
    cout << endl;
    return 0;
}