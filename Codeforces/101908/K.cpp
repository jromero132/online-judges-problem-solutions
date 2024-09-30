// Problem name: Kepler
// Problem link: https://codeforces.com/gym/101908/problem/K
// Submission link: https://codeforces.com/gym/101908/submission/45144884

#include <bits/stdc++.h>

#define pb push_back
#define sqr(x) ((x) * (x))
#define endl '\n'

using namespace std;

struct circle{
    double x, y, r;
    circle() : x(0), y(0), r(0){ }
    friend istream &operator >>(istream &in, circle &c){
        in >> c.x >> c.y >> c.r;
        return in;
    }

    bool operator <(const circle &c) const{
        return r < c.r;
    }
};

bool intersect(const circle &c1, const circle &c2){
    return sqr(c1.x - c2.x) + sqr(c1.y - c2.y) > sqr(c1.r - c2.r);
}

int ans = 0;
vector<circle> ci;
vector<vector<int>> adj;

void dfs(circle &c, int p){
    ++ans;
    for(auto x : adj[ p ])
        if(intersect(c, ci[ x ]))
            dfs(c, x);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
    freopen("01.in", "r", stdin);
    freopen("01.out", "w", stdout);
#endif

    int n;
    cin >> n;
    ci.assign(n, circle());
    adj.assign(n, vector<int>());
    for(auto &c : ci)
        cin >> c;
    sort(ci.begin(), ci.end());
    set<int> s;
    for(int i = 0 ; i < n ; ++i){
        for(auto x : s){
            if(intersect(ci[ i ], ci[ x ])){
                dfs(ci[ i ], x);
                if(ans > n)
                    break;
            }
            else
                adj[ i ].pb(x);
        }
        if(ans > n)
            break;
        for(auto x : adj[ i ])
            s.erase(x);
        s.insert(i);
    }
    if(ans > n)
        cout << "greater" << endl;
    else
        cout << (ans << 1) << endl;
    return 0;
}