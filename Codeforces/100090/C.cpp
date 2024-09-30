// Problem name: Graph Restoration
// Problem link: https://codeforces.com/gym/100090/problem/C
// Submission link: https://codeforces.com/gym/100090/submission/20993824

#include <bits/stdc++.h>

using namespace std;

#define DB( x ) cout << #x << " = " << x << endl;
#define LEFT(n) (2 * (n))
#define RIGHT(n) (2 * (n) + 1)
#define X real()
#define Y imag()

typedef long long ll;
typedef pair<int, int> node;
typedef complex<double> P;

const ll INF = 1e9;
const double EPS = 1e-6;
const ll MOD = (ll)(1e5);
const ll MAXV = (ll)(2e5 + 10);
const ll MAXE = (ll)(1e6 + 10);

int V;
ll matrix[500][500];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);

	scanf("%d", &V);

	for(int i = 0;i < V;i ++)
		for(int j = 0;j < V;j ++)
			scanf("%lld", &matrix[i][j]);

	bool ok = true;

	for(int i = 0;i < V;i ++)
		for(int j = 0;j < V;j ++)
			for(int k = 0;k < V;k ++){
				if(matrix[i][j] > matrix[i][k] + matrix[k][j])
					ok = false;
			}
	if(ok){
		for(int i = 0;i < V;i ++){
			for(int j = 0;j < V;j ++){
				if(j == 0)
					printf("%lld", matrix[i][j]);
				else
					printf(" %lld", matrix[i][j]);
			}
			printf("\n");
		}
	}
	else
		printf("-1\n");

	return 0;
}