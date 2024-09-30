// Problem name: Range Minimum Query
// Problem link: https://www.spoj.com/problems/RMQSQ/
// Submission link: https://www.spoj.com/submit/RMQSQ/id=22663637

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

template<typename T, typename Compare = less<T>>
struct direct_rmq
{
	direct_rmq() = default;

	template<typename Iter>
	direct_rmq(Iter first, Iter last, const Compare &comp = Compare()) :
		n(distance(first, last)),
		comp(comp),
		BlockSize(32),
		// BlockSize(max(static_cast<int>(1), __lg(n))),
		TotalBlocks((n + BlockSize - 1) / BlockSize),
		BlocksRMQ((__lg(TotalBlocks) + 1) * TotalBlocks),
		Masks(n)
	{
		for (int i = 0, block = 0; i < n;)
			for (int end = min(n, i + BlockSize), &min_pos = BlocksRMQ[block++] = i; ++i < end;)
				if (comp(first[i], first[min_pos])) min_pos = i;
		auto cur_lvl = BlocksRMQ.begin();
		for (int m, mh = 1; (m = mh << 1) <= TotalBlocks; mh = m)
		{
			auto next_lvl = next(cur_lvl, TotalBlocks);
			for (int i = 0; i + mh < TotalBlocks; ++i)
				next_lvl[i] = argmin(cur_lvl[i], cur_lvl[i + mh], first);
			cur_lvl = next_lvl;
		}
		deque<int> deq;
		for (int i = 0; i < n; i += BlockSize)
		{
			while (!deq.empty() && deq.front() < i) deq.pop_front();
			int end = min(n, i + BlockSize);
			for (int j = i; j < end; ++j)
			{
				while (!deq.empty() && comp(first[j], first[deq.back()]))
					deq.pop_back();
				if (!deq.empty()) Masks[j] = Masks[deq.back()] | (1 << (deq.back() - i));
				deq.push_back(j);
			}
		}
		 // This is a bit faster, but consumes O(n) extra memory
		 vector<int> stk(n);
		 for (int i = 0; i < n; ++i)
		 	for (stk[i] = i - 1; stk[i] >= 0 && comp(first[i], first[stk[i]]); stk[i] = stk[stk[i]]);
		 for (int i = 0; i < n; i += BlockSize)
		 {
		 	int end = min(n, i + BlockSize);
		 	for (int j = i + 1; j < end; ++j)
		 		if (stk[j] >= i) Masks[j] = Masks[stk[j]] | (1 << (stk[j] - i));
		 }
	}

	// argmin of a[l, r)
	template<typename Iter>
	int operator()(int l, int r, const Iter &data) const
	{
		int x = l / BlockSize, y = --r / BlockSize, z = y - x;
		if (z == 0) return in_block_query(x, l, r);
		if (z == 1) return argmin(in_block_query(x, l, x * BlockSize + BlockSize - 1),
								  in_block_query(y, y * BlockSize, r), data);
		z = __lg(z - 1);
		return argmin(argmin(in_block_query(x, l, x * BlockSize + BlockSize - 1),
							 argmin(BlocksRMQ[TotalBlocks * z + x + 1], BlocksRMQ[TotalBlocks * z + y - (1 << z)], data), data),
					  in_block_query(y, y * BlockSize, r), data);
	}

private:
	int n;
	Compare comp;
	int BlockSize;
	int TotalBlocks;
	vector<int> BlocksRMQ;
	vector<int> Masks;

	template<typename Iter>
	inline int argmin(int x, int y, const Iter &data) const { return comp(data[y], data[x]) ? y : x; }

	int in_block_query(int block, int l, int r) const
	{
		int rmask = Masks[r], pos = l - BlockSize * block;
		if (pos >= 1) rmask &= ~((1 << pos) - 1);
		if (rmask == 0) return r;
		int ret = __lg(lowest_one(rmask));
		return ret + block * BlockSize;
	}

	static inline size_t lowest_one(size_t x) { return x & -x; }
};

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n, q;
	cin >> n;
	vector<int> v(n);
	for(auto &x : v)
		cin >> x;
	direct_rmq<int> r(v.begin(), v.end());
	for(cin >> q ; q-- ; ){
		int a, b;
		cin >> a >> b;
		cout << v[ r(a, b + 1, v) ] << endl;
	}
	return 0;
}