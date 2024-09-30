// Problem name: F - Sufijos b-semejantes
// Problem link: https://matcomgrader.com/problem/9524/sufijos-b-semejantes/
// Submission link: https://matcomgrader.com/submission/125191/

#include <bits/stdc++.h>

using namespace std;

#define INF ((int)(1 << 30))
#define pb push_back
#define endl '\n'

template<typename T>
struct suffix_tree{
	int n, size, _node, _pos;
	vector<T> s;
	vector<int> fpos, len, link, count;
	vector<map<T, int>> next;

	suffix_tree(vector<T> &s) : n(0), size(1), _node(0), _pos(0), s(s), next(1, map<T, int>()), fpos(1, 0), len(1, INF), link(1, -1){
		for(auto c : s)
			extend(c);
		len[ 0 ] = 0;
		count.resize(size);
		dfs_count(0);
	}

	inline int get_len(int node){
		return min(len[ node ], n - fpos[ node ]);
	}

	inline int make_node(int _pos, int _len){
		fpos.pb(_pos);
		len.pb(_len);
		link.pb(0);
		next.pb(map<T, int>());
		return size++;
	}

	void extend(int c){
		int last = 0;
		for(s.pb(c), n++, _pos++ ; _pos > 0 ; ){
			while(_pos > get_len(next[ _node ][ s[ n - _pos ] ])){
				_node = next[ _node ][ s[ n - _pos ] ];
				_pos -= get_len(_node);
			}

			T edge = s[ n - _pos ];
			int &v = next[ _node ][ edge ];
			T t = s[ fpos[ v ] + _pos - 1 ];

			if(v == 0){
				v = make_node(n - _pos, INF);
				link[ last ] = _node;
				last = 0;
			}
			else if(t == c){
				link[ last ] = _node;
				return;
			}
			else{
				int u = make_node(fpos[ v ], _pos - 1);
				next[ u ][ c ] = make_node(n - 1, INF);
				next[ u ][ t ] = v;
				fpos[ v ] += _pos - 1;
				len [ v ] = (len[ v ] == INF ? INF : len[ v ] - _pos + 1);
				v = u;
				link[ last ] = u;
				last = u;
			}

			if(_node == 0)
				_pos--;
			else
				_node = link[ _node ];
		}
	}

	void dfs_count(int node){
		count[ node ] = (len[ node ] == INF);
		for(auto it : next[ node ])
			dfs_count(it.second), count[ node ] += count[ it.second ];
	}

	void update(vector<int> &b){
		for(int node = 0, p = 0 ; p < n ; p++){
			b[ p ] += count[ node ];
			if(p == fpos[ node ] + get_len(node))
				node = next[ node ][ s[ p ] ];
		}
		b[ 0 ]--;
	}
};

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t, k, q;
	string ss;
	vector<char> s;
	for(cin >> t ; t-- ; ){
		cin >> ss;
		s.clear();
		for(int i = 0 ; ss[ i ] ; s.pb(ss[ i++ ]));
		s.pb('$');
		suffix_tree<char> st(s);
		vector<int> b(s.size(), 0);
		st.update(b);
		for(cin >> k ; k-- ; )
			cin >> q, cout << (q < s.size() ? b[ q ] : 0) << " \n"[ !k ];
	}
}