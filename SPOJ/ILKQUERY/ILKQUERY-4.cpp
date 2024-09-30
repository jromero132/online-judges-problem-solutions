// Problem name: I LOVE Kd-TREES
// Problem link: https://www.spoj.com/problems/ILKQUERY/
// Submission link: https://www.spoj.com/submit/ILKQUERY/id=22627339

#include <bits/stdc++.h>

#define pb push_back
#define sz(x) ((int)(x).size())
#define endl '\n'

using namespace std;

typedef long long ll;

struct bit_array{
	vector<int> blocks, rank_table;

	bit_array() : blocks(0), rank_table(0){ }

	bit_array(int n, bool one = false) : blocks((n + 31) >> 5, one ? 0xffffffff : 0), rank_table(sz(blocks), 0){ }

	// Return number of bits sets on in x
	inline int bit_count(int x) const{
		x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
		x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
		x = (x & 0x0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f);
		x = (x & 0x00ff00ff) + ((x >> 8) & 0x00ff00ff);
		x = (x & 0x0000ffff) + ((x >> 16) & 0x0000ffff);
		return x;
	}

	void build(){
		int sum = 0;
		for(int i = 0 ; i < sz(rank_table) ; ++i)
			rank_table[ i ] = (sum += bit_count(blocks[ i ]));
		// return sum; // Number of bits on in the structure.
	}

	// Return number of bits equal to one in range [0, pos)
	int rank(int pos, bool one = true) const{
		int block = pos >> 5, bit = pos & 31;
		int sum = (block >= 1 ? rank_table[ block - 1 ] : 0) + bit_count(blocks[ block ] & ((1 << bit) - 1));
		return one ? sum : pos - sum;
	}

	void set_bit(const int pos, const bool one = true){
		int block = pos >> 5, bit = pos & 31;
		if(one)
			blocks[ block ] |= (1 << bit);
		else
			blocks[ block ] &= ~(1 << bit);
	}

	bool get_bit(const int pos) const{ return (blocks[ pos >> 5 ] >> (pos & 31)) & 1; }
};

template<typename T>
struct wavelet_matrix{
	int n, max_level;
	T max_value;
	vector<bit_array> bit_arrays;
	vector<int> zero_cnt;

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
		vector<T> last = data, next = data;
		for(int lvl = 0 ; lvl < max_level ; ++lvl){
			ll mask = 1LL << (max_level - lvl - 1);
			int &zeros = zero_cnt[ lvl ] = 0;
			for(int i = 0 ; i < n ; ++i)
				zeros += ((last[ i ] & mask) == 0);
			bit_array &ba = bit_arrays[ lvl ];
			int zero_pos = 0, one_pos = zeros;
			for(int i = 0 ; i < n ; ++i){
				if(last[ i ] & mask){
					ba.set_bit(i);
					next[ one_pos ] = last[ i ];
					one_pos++;
				}
				else{
					next[ zero_pos ] = last[ i ];
					zero_pos++;
				}
			}
			ba.build();
			swap(last, next);
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
			l = bit_arrays[ lvl ].rank(l, bit);
			r = bit_arrays[ lvl ].rank(r, bit);
			if(bit)
				l += zero_cnt[ lvl ], r += zero_cnt[ lvl ];
			more_and_less[ bit ] -= r - l;
		}
		return make_tuple(more_and_less[ 1 ], r - l, more_and_less[ 0 ]);
	}

	T kth(int l, int r, int k){
		if(r - l < k)
			return -1;
		int ans = 0;
		for(int lvl = 0 ; lvl < max_level ; ++lvl){
			int l0 = bit_arrays[ lvl ].rank(l, 0);
			int r0 = bit_arrays[ lvl ].rank(r, 0);
			if(r0 - l0 < k){
				ans |= (1 << (max_level - lvl - 1));
				k -= r0 - l0;
				l = zero_cnt[ lvl ] + bit_arrays[ lvl ].rank(l, 1);
				r = zero_cnt[ lvl ] + bit_arrays[ lvl ].rank(r, 1);
			}
			else
				l = l0, r = r0;
		}
		return ans;
	}

	// inline int rank(const bit_array &ba, const int pos, const bool bit){
	// 	int sum = (pos >= 1 ? ba[ pos - 1 ] : 0);
	// 	return bit ? sum : pos - sum;
	// }
};

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
	freopen("01.out", "w", stdout);
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