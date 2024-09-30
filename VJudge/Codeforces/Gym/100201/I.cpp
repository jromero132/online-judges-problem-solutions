// Problem name: Railroad Sort
// Problem link: https://vjudge.net/problem/Gym-100201I
// Submission link: https://vjudge.net/solution/13138130

#include <bits/stdc++.h>

#define MAX ((int)(1 << 13))
#define pb push_back
#define endl '\n'

using namespace std;

typedef vector<int> vi;

int n, m, len1, len2;
vi direct, indirect;
vector<vi> path, path2;

void BFS(vi &order){
    path.pb(order);
    for(int k = n ; --k >= 0 ; ){
        path2.clear();
        len1 = path.size();
        for(int j = 0 ; j < len1 ; j++){
            order = path[ j ];
            direct.clear();
            indirect.clear();
            len2 = order.size();
            for(int i = 0 ; i < len2 ; i++){
                cout << order[ i ] + 1 << ' ';
                if(order[ i ] & (1 << k))
                    indirect.pb(order[ i ]);
                else
                    cout << order[ i ] + 1 << ' ', direct.pb(order[ i ]);
            }
            reverse(indirect.begin(), indirect.end());
            len2 = indirect.size();
            for(int i = 0 ; i < len2 ; i++)
                cout << indirect[ i ] + 1 << ' ';
            path2.pb(direct);
            path2.pb(indirect);
        }
        swap(path, path2);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("railsort.in", "r", stdin);
    freopen("railsort.out", "w", stdout);
    cin >> n;
    m = (1 << n);
    vi order(m);
    for(int i = 0 ; i < m ; i++)
        cin >> order[ i ], order[ i ]--;
    BFS(order);
    return 0;
}