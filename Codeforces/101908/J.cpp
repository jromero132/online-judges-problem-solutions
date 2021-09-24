// Problem name: Joining Capitals
// Problem link: https://codeforces.com/gym/101908/problem/J
// Submission link: https://codeforces.com/gym/101908/submission/45112528

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

template <typename T>
struct point{
    T x, y;
    point() : x(0), y(0) {}
    point(const T x, const T y) : x(x), y(y) {}
    point operator-(const point &p) const { return point(x - p.x, y - p.y); }
    friend istream &operator>>(istream &in, point &p)
    {
        in >> p.x >> p.y;
        return in;
    }
    static T dot(const point &a, const point &b) { return a.x * b.x + a.y * b.y; }
    static T dist2(const point &a, const point &b) { return dot(a - b, a - b); }
    static T dist(const point &a, const point &b) { return sqrt(dist2(a, b)); }
};

struct edge{
    int v;
    double weight;
};

double fixed_leaves_mst(int k, vector<vector<edge>> &adj){
    int n = adj.size();
    vector<vector<double>> DP(1 << k, vector<double>(n, 0));
    for(int mask = 0 ; mask < (1 << k) ; ++mask)
        for(int i = k ; i < n ; ++i)
            for(int j = 0 ; j < n && adj[ i ][ j ].v < k ; ++j)
                if(mask & (1 << adj[ i ][ j ].v))
                    DP[ mask ][ i ] += adj[ i ][ j ].weight;
    for(int mask = 0 ; mask < (1 << k) ; ++mask){
        for(int i = k ; i < n ; ++i){
            int j;
            for(j = 0 ; j < n && adj[ i ][ j ].v < k ; ++j);
            for( ; j < (int)adj[ i ].size() ; ++j)
                for(int submask = mask ; ; submask = (submask - 1) & mask){
                    DP[ mask ][ i ] = min(DP[ mask ][ i ], DP[ submask ][ i ] + adj[ i ][ j ].weight + DP[ mask ^ submask ][ adj[ i ][ j ].v ]);
                    if(!submask)
                        break;
                }
        }
    }
    double ans = 1e18;
    for(int i = k, all = (1 << k) - 1 ; i < n ; ++i)
        ans = min(ans, DP[ all ][ i ]);
    return ans;
}

vector<vector<edge>> build_adjacency(int k, vector<point<double>> &ps){
    vector<vector<edge>> adj(ps.size());
    for(int i = 0, n = ps.size() ; i < n ; ++i)
        for(int j = (i < k ? k : 0) ; j < n ; ++j){
            if(i == j)
                continue;
            adj[ i ].push_back({ j, point<double>::dist(ps[ i ], ps[ j ]) });
        }
    return adj;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
    freopen("01.in", "r", stdin);
    freopen("01.out", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;
    vector<point<double>> ps(n);
    for(auto &p : ps)
        cin >> p;
    vector<vector<edge>> adj = build_adjacency(k, ps);
    cout << setprecision(5) << fixed << fixed_leaves_mst(k, adj) << endl;
    return 0;
}