// Problem name: Fibonacci Words
// Problem link: https://codeforces.com/gym/101205/problem/D
// Submission link: https://codeforces.com/gym/101205/submission/34334499

#include <iostream>
#include <string.h>

#define MAX ((int)29)
#define MAX_N ((int)101)
#define MAX_LENGTH ((int)(100000))
#define endl '\n'

using namespace std;

typedef unsigned long long ull;

int fail[ MAX_LENGTH ];
ull fib[ MAX_N ], C[ 4 ];
string Fib[ MAX ];

void fibonacci(){
	fib[ 0 ] = 0ULL;
	fib[ 1 ] = 1ULL;
	Fib[ 0 ] = "0";
	Fib[ 1 ] = "1";
	for(int i = 2 ; i < MAX ; i++){
		fib[ i ] = fib[ i - 1 ] + fib[ i - 2 ];
		Fib[ i ] = Fib[ i - 1 ] + Fib[ i - 2 ];
	}
	for(int i = MAX ; i < MAX_N ; i++)
		fib[ i ] = fib[ i - 1 ] + fib[ i - 2 ];
}

void preKMP(string p){
	int len = p.length();
	memset(fail, 0, len * sizeof(fail[ 0 ]));
	for(int i = 1, j = 0 ; i < len ; ){
		if(p[ i ] == p[ j ])
			fail[ i++ ] = ++j;
		else{
			if(j)
				j = fail[ j - 1 ];
			else
				fail[ i++ ] = 0;
		}
	}
}

void ocurrences(string p, int m){
	preKMP(p);
	memset(C, 0, sizeof(C));
	ull len_p = p.length(), len = min(fib[ m ] + len_p - 1, fib[ m + 1 ]), len_c0 = fib[ m - 1 ] + len_p;
	for(ull i = 0, j = 0 ; i < len ; ){
        if(Fib[ m ][ i ] == p[ j ]){
	        i++;
	        j++;
	        if(j == len_p){
				if(i < len_c0){
					if(i <= fib[ m - 1 ])
						C[ 0 ]++;
					else
						C[ 2 ]++;
					C[ 1 ]++;
				}
				else{
					if(i <= fib[ m ])
						C[ 1 ]++;
					else
						C[ 3 ]++;
				}
		        j = fail[ j - 1 ];
	        }
        }
        else if(j)
        	j = fail[ j - 1 ];
		else
			i++;
	}
}

ull solve(int n, string p){
	ull len_p = p.length();
	if(len_p == 1){
		if(p[ 0 ] == '0')
			return n == 0 ? 1ULL : fib[ n - 1 ];
		return fib[ n ];
	}
	int m;
	for(m = 3 ; len_p > fib[ m - 2 ] ; m++);
	if(m > n){
		if(m - 3 > n)
			return 0ULL;
		m = n;
	}
	preKMP(p);
	ocurrences(p, m);
	n -= m - 1;
	for(int i = 1 ; i <= n ; i++){
		swap(C[ 0 ], C[ 1 ]);
		C[ 1 ] += C[ 0 ] + C[ i % 2 + 2 ];
	}
	return C[ 1 ];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	fibonacci();

    int n, c = 0;
    string p;
    while(cin >> n >> p)
    	cout << "Case " << ++c << ": " << solve(n, p) << endl;
    return 0;
}