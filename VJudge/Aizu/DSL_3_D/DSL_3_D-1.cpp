// Problem name: Sliding Minimum Element
// Problem link: https://vjudge.net/problem/Aizu-DSL_3_D
// Submission link: https://vjudge.net/solution/12785586

#include <bits/stdc++.h>

#define MAX ((int)1000000)
#define endl '\n'

using namespace std;

int array[ MAX ];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, l;
	multiset<int> order;
	cin >> n >> l;
	for(int i = 0 ; i < l ; i++)
		cin >> array[ i ], order.insert(array[ i ]);
	cout << *(order.begin());
	for(int i = l ; i < n ; i++){
		cin >> array[ i ];
		order.erase(order.find(array[ i - l ]));
		order.insert(array[ i ]);
		cout << ' ' << *(order.begin());
	}
	cout << endl;
	return 0;
}