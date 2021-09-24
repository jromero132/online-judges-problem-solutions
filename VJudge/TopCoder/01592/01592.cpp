// Problem name: ChessMetric
// Problem link: https://vjudge.net/problem/TopCoder-1592
// Submission link: https://vjudge.net/solution/31761808

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<pii> vii;

class ChessMetric{
	const ll INF = (1ULL << 63ULL);

public:
	ll howMany(int size, vi start, vi end, int numMoves){
		vvvl memo(size, vvl(size, vl(numMoves + 1, INF)));
		vii valid_moves;
		for(int i = -1 ; i <= 1 ; ++i)
			for(int j = -1 ; j <= 1 ; ++j)
				if(i != 0 || j != 0)
					valid_moves.push_back(make_pair(i, j));
		for(int i = 1 ; i <= 2 ; ++i){
			valid_moves.push_back(make_pair(i, 3 - i));
			valid_moves.push_back(make_pair(i, -3 + i));
			valid_moves.push_back(make_pair(-i, 3 - i));
			valid_moves.push_back(make_pair(-i, -3 + i));
		}
		return howMany(size, make_pair(start[ 0 ], start[ 1 ]), make_pair(end[ 0 ], end[ 1 ]), numMoves, valid_moves, memo);
	}

	ll howMany(int size, pii start, pii end, int numMoves, vii& valid_moves, vvvl& memo){
		if(memo[ start.first ][ start.second ][ numMoves ] != INF)
			return memo[ start.first ][ start.second ][ numMoves ];
		if(!numMoves)
			return memo[ start.first ][ start.second ][ 0 ] = start == end ? 1 : 0;
		ll ans = 0;
		for(int i = 0 ; i < valid_moves.size() ; ++i){
			int r = start.first + valid_moves[ i ].first;
			int c = start.second + valid_moves[ i ].second;
			if(min(r, c) >= 0 && max(r, c) < size)
				ans += howMany(size, make_pair(r, c), end, numMoves - 1, valid_moves, memo);
		}
		return memo[ start.first ][ start.second ][ numMoves ] = ans;
	}
};