// Problem name: To Go Or Not To Go?
// Problem link: https://codeforces.com/contest/1520/problem/G
// Submission link: https://codeforces.com/contest/1520/submission/121268646

#include <bits/stdc++.h>

#define INF (ll)1e18

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;

namespace FastIO{
	const int BSZ = 1 << 15;
	char ibuf[ BSZ ]; int ipos = -1, ilen = 0;
	char next_char(){
		if (++ipos == ilen){
			ipos = 0;
            ilen = fread(ibuf, 1, BSZ, stdin);
			if(!ilen)
                return EOF;
		}
		return ibuf[ ipos ];
	}
    char get_char(){ return ipos >= 0 ? ibuf[ ipos ] : next_char(); }
	template<class T> void read_int(T& x){
        x = 0;
		for(char c = get_char() ; !isdigit(c) && c != '-' && c != EOF ; c = next_char());
        bool sgn = get_char() == '-';
        for(char c = sgn ? next_char() : get_char() ; isdigit(c) ; x = 10 * x + (c ^ '0'), c = next_char());
		x = sgn ? -x : x;
	}
	template<class T, typename... Args> void read_int(T& x, Args&... rest){ read_int(x); read_int(rest...); }
	char obuf[ BSZ ], numBuf[ 30 ]; int opos = 0;
	void flushOut(){ fwrite(obuf, 1, opos, stdout); opos = 0; }
	void write_char(char c){ if(opos == BSZ) flushOut(); obuf[ opos++ ] = c; }
	template<class T> void write_int(T x){
        if(x < (T)0) write_char('-'), x = -x;
        int len = 0;
        for( ; x >= 10 ; x /= 10) numBuf[ len++ ] = '0' | (x % 10);
        write_char('0' | x);
        while(len--) write_char(numBuf[ len ]);
	}
	void initO(){ assert(atexit(flushOut) == 0); }
}
using namespace FastIO;

const int NOT_REACHED = -2;
const vii VALID_MOVES = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

vvi bfs(vvi &graph, pii &source){
    int n = graph.size(), m = graph[ 0 ].size();
    vvi dist(n, vi(m, NOT_REACHED));
    dist[ source.first ][ source.second ] = 0;
    pii cur;
    for(queue<pii> q({ source }) ; !q.empty() ; q.pop()){
        cur = q.front();
        for(pii dir : VALID_MOVES){
            dir.first += cur.first;
            dir.second += cur.second;
            if(dir.first >= 0 && dir.first < n
            && dir.second >= 0 && dir.second < m
            && graph[ dir.first ][ dir.second ] != -1 && dist[ dir.first ][ dir.second ] == NOT_REACHED){
                dist[ dir.first ][ dir.second ] = dist[ cur.first ][ cur.second ] + 1;
                q.push(dir);
            }
        }
    }
    return dist;
}

ll get_min_path(const vvi &matrix, const vvi &source_dist, const vvi &target_dist, const int w){
    int n = matrix.size() - 1, m = matrix[ 0 ].size() - 1;
    ll no_portals = source_dist[ n ][ m ] == NOT_REACHED ? INF : (ll)source_dist[ n ][ m ] * w;
    ll one_portal_source = INF, one_portal_target = INF;
    for(int i = 0 ; i < matrix.size() ; ++i){
        for(int j = 0 ; j < matrix[ 0 ].size() ; ++j){
            if(matrix[ i ][ j ] > 0){
                if(source_dist[ i ][ j ] != NOT_REACHED)
                    one_portal_source = min(one_portal_source, (ll)source_dist[ i ][ j ] * w + matrix[ i ][ j ]);
                if(target_dist[ i ][ j ] != NOT_REACHED)
                    one_portal_target = min(one_portal_target, (ll)target_dist[ i ][ j ] * w + matrix[ i ][ j ]);
            }
        }
    }
    ll ans = min(no_portals, one_portal_source + one_portal_target);
    return ans == INF ? -1 : ans;
}

int main(){
    initO();

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m, w;
    read_int(n);
    read_int(m);
    read_int(w);
    vvi matrix(n, vi(m));
    for(vi &row : matrix)
        for(int &cell : row)
            read_int(cell);
    pii source = { 0, 0 }, target = { n - 1, m - 1 };
    vvi source_distance = bfs(matrix, source);
    vvi target_distance = bfs(matrix, target);
    write_int(get_min_path(matrix, source_distance, target_distance, w));
    return 0;
}