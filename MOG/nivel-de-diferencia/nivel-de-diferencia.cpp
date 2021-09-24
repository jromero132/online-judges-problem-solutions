// Problem name: B - Nivel de diferencia
// Problem link: https://matcomgrader.com/problem/9256/nivel-de-diferencia/
// Submission link: https://matcomgrader.com/submission/125218/

#include <bits/stdc++.h>

using namespace std;

#define INF ((int)(1 << 30))
#define pb push_back
#define endl '\n'

typedef long long ll;
typedef pair<ll, int> pli;

template<typename T>
struct suffix_tree{
	int node, pos, limit;
	vector<T> s;
	vector<int> spos, len, link;
	vector<map<T, int>> next;

	suffix_tree() : node(0), pos(0) { make_node(0); }

	inline int get_len(int node) { return node == 0 ? 0 : min(len[ node ], (int)s.size() - spos[ node ]); }

	inline int make_node(int _pos, int _len = INF){
		spos.pb(_pos);
		len.pb(_len);
		link.pb(0);
		next.emplace_back();
		return spos.size() - 1;
	}

	void extend(T c){
		int last = 0;
		for (s.pb(c), pos++ ; pos > 0 ; ){
			int n = s.size();
			while(pos > len[ next[ node ][ s[ n - pos ] ] ])
				node = next[ node ][ s[ n - pos ] ], pos -= len[ node ];

			T edge = s[ n - pos ];
			int &v = next[ node ][ edge ];
			T t = s[ spos[ v ] + pos - 1 ];

			if(v == 0){
				v = make_node(n - pos);
				link[ last ] = node;
				last = 0;
			}
			else if(t == c){
				link[last] = node;
				return;
			}
			else{
				int u = make_node(spos[ v ], pos - 1);
				next[ u ][ c ] = make_node(n - 1);
				next[ u ][ t ] = v;
				spos[ v ] += pos - 1;
				len[ v ] = (len[ v ] == INF ? INF : len[ v ] -  pos + 1);
				v = last = link[ last ] = u;
			}

			if (node == 0)
				pos--;
			else
				node = link[node];
		}
	}

	pli dfs(int node){
		if(node && len[ node ] == INF){
			if(spos[ node ] < limit)
				return { limit - spos[ node ] - 1, 1 };
			return { s.size() - spos[ node ] - 1LL, 2 };
		}

		ll ans = 0;
		int mask = 0;
		for(auto it : next[ node ]){
			pli now = dfs(it.second);
			ans += now.first;
			mask |= now.second;
		}
		if(spos[ node ] < limit && spos[ node ] + get_len(node) >= limit)
			return { ans + limit - spos[ node ], 1 };
		return { ans + (mask != 3) * get_len(node), mask };
	}
};

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s1, s2;
	cin >> s1 >> s2;
	suffix_tree<char> st;
	for(int i = 0 ; s1[ i ] ; st.extend(s1[ i++ ]));
	st.extend('#');
	for(int i = 0 ; s2[ i ] ; st.extend(s2[ i++ ]));
	st.extend('$');
	st.limit = s1.length() + 1;
	cout << st.dfs(0).first << endl;
}