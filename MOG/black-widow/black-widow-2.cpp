// Problem name: D - Black Widow
// Problem link: https://matcomgrader.com/problem/9102/black-widow/
// Submission link: https://matcomgrader.com/submission/117096/

#include<bits/stdc++.h>

using namespace std;

#ifdef ONLINE_JUDGE
	#define WAIT
#else
	#define WAIT cout<<flush, system("PAUSE")
#endif

#define FOR(IN,N) for(int I = IN;I < N;++I)
#define FORR(END,N) for(int I = N-1;I >= END;--I)
#define foreach(arr) for(auto item : arr)
#define REP(I,A,B) for(int I = A;I < B;++I)

#define CONTAINS(m,x) m.find(x) != m.end()
#define clr(x) memset((x),0,sizeof(x))
#define PB push_back
#define remove erase
#define ALL(v) v.begin(),v.end()
#define sz(a) a.size();
#define endl '\n'
#define MAX

typedef long long ll;
typedef pair<int,int> pii;
using namespace std;

set<int> M;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	//M.insert(1)
	for(int i = 0 ; i < n; i++){
		int x;
		cin >> x;

		for(int j = 1; j * j <= x; j++){
			if(x % j == 0){
				int a = j;
				int b = x/j;
				M.insert(a);
				if(a != b)M.insert(b);
			}
		}

	}

	for(int i = 1; ; i++){
		if(M.find(i) == M.end()){
			cout << i << endl;
			return 0;
		}
	}



	return 0;

}