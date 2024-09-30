// Problem name: Fibonacci Words
// Problem link: https://codeforces.com/gym/101205/problem/D
// Submission link: https://codeforces.com/gym/101205/submission/34334328

#include <iostream>

#define MAX ((int)101)
#define endl '\n'

using namespace std;

typedef unsigned long long ull;

ull fib[ MAX ];

void fibonacci(){
	fib[ 0 ] = 0ULL;
	fib[ 1 ] = 1ULL;
	for(int i = 2 ; i < MAX ; i++)
		fib[ i ] = fib[ i - 1 ] + fib[ i - 2 ];
}

ull solve(int n, string p){
	int last = p.length() - 1;

    if(n == 0 && last > 0)
    	return 0ULL;

	if(last == 0){
		if(p[ 0 ] == '0')
			return (n == 0 ? 1ULL : fib[ n - 1 ]);
		return fib[ n ];
	}

	if(p[ 0 ] == '0'){
		p = '1' + p;
		last++;
	}

    string s1 = "", s2 = "";
    for(int i = 0 ; i < last ; i++){
		if(p[ i ] == '0'){
			return 0ULL;
		}
    	else{
	    	if(p[ i + 1 ] == '0'){
		    	s1 += '1';
		    	i++;
	    	}
	    	else{
		    	s1 += '0';
	    	}
    	}
    }

    if(p[ last ] == '0' && p[ last - 1 ] == '0')
    	return 0ULL;

    if(p[ last ] == '1'){
    	s2 = s1 + '1';
    	s1 = s1 + '0';
    }

    return solve(n - 1, s1) + (s2 == "" ? 0LL : solve(n - 1, s2));
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