// Problem name: I LOVE Kd-TREES
// Problem link: https://www.spoj.com/problems/ILKQUERY/
// Submission link: https://www.spoj.com/submit/ILKQUERY/id=22541870

#include <bits/stdc++.h>

#define pb push_back
#define endl '\n'

using namespace std;

typedef long long ll;

template<typename T>
struct wavelet_matrix{
	using bit_array = vector<int>;

	int n, max_level;
	T max_value;
	vector<bit_array> bit_arrays;
	vector<int> zero_cnt;
	vector<vector<T>> matrix;

	wavelet_matrix() : n(0), max_level(0), max_value(0){ };
	wavelet_matrix(const vector<T> &data, int max_level = 0){
		n = data.size();
		max_value = (n == 0 ? 0 : *max_element(data.begin(), data.end()));
		if(!max_level)
			while((1ULL << max_level) <= max_value)
				++max_level;
		this -> max_level = max_level;
		bit_arrays.assign(max_level, bit_array(n));
		zero_cnt.assign(max_level, 0);
		matrix.assign(max_level, vector<T>(n));
		vector<T> last = data;
		for(int lvl = 0 ; lvl < max_level ; ++lvl){
			ll mask = 1LL << (max_level - lvl - 1);
			int &zeros = zero_cnt[ lvl ] = 0;
			for(int i = 0 ; i < n ; ++i)
				zeros += ((last[ i ] & mask) == 0);
			bit_array &ba = bit_arrays[ lvl ];
			int zero_pos = 0, one_pos = zeros;
			for(int i = 0 ; i < n ; ++i){
				if(last[ i ] & mask){
					ba[ i ] = 1;
					matrix[ lvl ][ one_pos ] = last[ i ];
					one_pos++;
				}
				else{
					matrix[ lvl ][ zero_pos ] = last[ i ];
					zero_pos++;
				}
			}
			for(int i = 1 ; i < n ; ++i)
				ba[ i ] += ba[ i - 1 ];
			last = matrix[ lvl ];
		}
	}

	tuple<int, int, int> rank_all(const T c, int l, int r){
		if(c > max_value)
			return make_tuple(r - l, 0, 0);
		if(c < 0)
			return make_tuple(0, 0, r- l);
		int more_and_less[ 2 ] = { 0, 0 };
		for(int lvl = 0 ; lvl < max_level ; ++lvl){
			const bool bit = (c >> (max_level - lvl - 1)) & 1;
			more_and_less[ bit ] += r - l;
			l = rank(bit_arrays[ lvl ], l, bit);
			r = rank(bit_arrays[ lvl ], r, bit);
			if(bit)
				l += zero_cnt[ lvl ], r += zero_cnt[ lvl ];
			more_and_less[ bit ] -= r - l;
		}
		return make_tuple(more_and_less[ 1 ], r - l, more_and_less[ 0 ]);
	}

	T kth(int l, int r, int k){
		if(r - l < k)
			return -1;
		for(int lvl = 0 ; lvl < max_level ; ++lvl){
			int l0 = rank(bit_arrays[ lvl ], l, 0);
			int r0 = rank(bit_arrays[ lvl ], r, 0);
			if(r0 - l0 < k)
				k -= r0 - l0, l = zero_cnt[ lvl ] + rank(bit_arrays[ lvl ], l, 1), r = zero_cnt[ lvl ] + rank(bit_arrays[ lvl ], r, 1);
			else
				l = l0, r = r0;
		}
		return matrix[ max_level - 1 ][ l ];
	}

	inline int rank(const bit_array &ba, const int pos, const bool bit){
		int sum = (pos >= 1 ? ba[ pos - 1 ] : 0);
		return bit ? sum : pos - sum;
	}
};

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	const int MAP = (int)1e9;
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	map<int, vector<int>> pos;
	for(int i = 0 ; i < n ; ++i)
		cin >> v[ i ], v[ i ] += MAP, pos[ v[ i ] ].pb(i);
	wavelet_matrix<int> wm(v);
	while(q--){
		int k, i, l, x;
		cin >> k >> i >> l, --l;
		x = wm.kth(0, i + 1, k);
		cout << (pos[ x ].size() > l ? pos[ x ][ l ] : -1) << endl;
	}
	return 0;
}