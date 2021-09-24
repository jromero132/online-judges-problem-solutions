// Problem name: AvoidRoads
// Problem link: https://vjudge.net/problem/TopCoder-1889
// Submission link: https://vjudge.net/solution/31759480

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef vector<ll> vl;
typedef vector<vl> vvl;

class AvoidRoads{
public:
	ll numWays(int width, int height, vector<string> bad){
		const ll mod = (1ULL << 63ULL) - 1ULL;
		vvvb blocked(width + 1, vvb(height + 1, vb(2, 0)));
		vvl dp(width + 1, vl(height + 1, 0));
		for(int i = 0 ; i < bad.size() ; ++i){
			stringstream ss;
			ss << bad[ i ];
			int a, b, c, d;
			ss >> a >> b >> c >> d;
			blocked[ min(a, c) ][ min(b, d) ][ b == d ] = 1;
		}
		dp[ 0 ][ 0 ] = 1;
		for(int i = 1 ; i <= width ; i++)
			dp[ i ][ 0 ] = blocked[ i - 1 ][ 0 ][ 1 ] ? 0 : dp[ i - 1 ][ 0 ];
		for(int i = 1 ; i <= height ; i++)
			dp[ 0 ][ i ] = blocked[ 0 ][ i - 1 ][ 0 ] ? 0 : dp[ 0 ][ i - 1 ];
		for(int i = 1 ; i <= width ; ++i)
			for(int j = 1 ; j <= height ; ++j)
				dp[ i ][ j ] = dp[ i ][ j - 1 ] * !blocked[ i ][ j - 1 ][ 0 ] + dp[ i - 1 ][ j ] * !blocked[ i - 1 ][ j ][ 1 ];
		return dp[ width ][ height ] % mod;
	}
};