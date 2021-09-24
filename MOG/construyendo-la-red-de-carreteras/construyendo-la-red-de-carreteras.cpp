// Problem name: B - Construyendo la red de carreteras
// Problem link: https://matcomgrader.com/problem/9464/construyendo-la-red-de-carreteras/
// Submission link: https://matcomgrader.com/submission/125968/

#include <bits/stdc++.h>

#define pb push_back
#define endl '\n'

using namespace std;

typedef long long ll;

template <typename T>
struct point{
    T x, y;
    point() : x(0), y(0) {}
	point(const T x, const T y) : x(x), y(y){ }
    point operator-(const point &p) const { return point(x - p.x, y - p.y); }
    friend istream &operator>>(istream &in, point &p){
        in >> p.x >> p.y;
        return in;
    }
};

struct disjoint_sets{
    int n, sets;
    vector<int> p;

    disjoint_sets(int n = 0) : n(n), sets(n), p(n, -1) {}

    int find(int pos) { return p[pos] < 0 ? pos : p[pos] = find(p[pos]); }

    bool merge(int p1, int p2){
        if ((p1 = find(p1)) == (p2 = find(p2)))
            return 0;
        --sets;
        if (p[p1] > p[p2])
            swap(p1, p2);
        p[p1] += p[p2];
        p[p2] = p1;
        return 1;
    }
};

template<typename R, typename T, typename C = less<T>>
R kruskal(int n, vector<T> &edges){
    sort(edges.begin(), edges.end(), C());

    disjoint_sets ds(n);
    R cost = 0;
    for(auto e : edges)
        if(ds.merge(e.u, e.v))
            cost += e.weight;
    return cost;
}


ll rectilinear_mst(vector<point<ll>> &ps){
    struct edge{
        int u, v;
        ll weight;
    };

    vector<int> id(ps.size());
    iota(id.begin(), id.end(), 0);

    vector<edge> edges;

    for(int s = 0 ; s < 2 ; ++s){
        for(int t = 0 ; t < 2 ; ++t){
            sort(id.begin(), id.end(), [ &ps ](int i, int j){
                return (ps[ i ] - ps[ j ]).x < (ps[ j ]- ps[ i ]).y;
            });

            map<ll, int> sweep;

            for(int i : id){
                for(auto it = sweep.lower_bound(-ps[ i ].y) ; it != sweep.end() ; sweep.erase(it++)){
                    int j = it -> second;
                    if((ps[ j ] - ps[ i ]).y < (ps[ j ] - ps[ i ]).x)
                        break;
                    ll d = abs((ps[ i ] - ps[ j ]).x) + abs((ps[ i ] - ps[ j ]).y);
                    edges.pb({ i, j, d });
                }
                sweep[ -ps[ i ].y ] = i;
            }
            for(auto &p : ps)
                swap(p.x, p.y);
        }
        for(auto &p : ps)
            swap(p.x = -p.x, p.y);
    }

    struct cmp{
        bool operator ()(const edge &a, const edge &b) const{
            return a.weight < b.weight;
        }
    };
    return kruskal<ll, edge, cmp>(ps.size(), edges);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
    freopen("01.in", "r", stdin);
    freopen("01.out", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<point<ll>> ps(n);
    for(auto &p : ps)
        cin >> p;
    cout << (rectilinear_mst(ps) << 1) << endl;
    return 0;
}