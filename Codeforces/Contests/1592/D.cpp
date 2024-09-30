// Problem name: Hemose in ICPC?
// Problem link: https://codeforces.com/contest/1592/problem/D
// Submission link: https://codeforces.com/contest/1592/submission/130744806

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<pii> get_order(vector<vector<int>> &tree, int v){
	vector<pii> order;
	for(queue<pii> q({{ v, -1 }}) ; !q.empty() ; q.pop()){
		pii cur = q.front();
		for(int u : tree[ cur.first - 1 ]){
			if(u != cur.second){
				order.emplace_back(cur.first, u);
				q.emplace(u, cur.first);
			}
		}
	}
	return order;
}

template<typename T>
T lowerbound(T left, T right, const function<bool(T)> &f){
    for(T middle = left + (right - left) / 2 ; left < right ; middle = left + (right - left) / 2){
        if(f(middle))
            right = middle;
        else
            left = middle + 1;
    }
    return left;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> tree(n);
	for(int u, v ; --n ; ){
		cin >> u >> v;
		tree[ u - 1 ].push_back(v);
		tree[ v - 1 ].push_back(u);
	}

	auto query = [](vector<pii>::iterator b, vector<pii>::iterator e){
		set<int> s;
		for( ; b < e ; s.insert(b -> first), s.insert(b -> second), ++b);
		cout << "? " << s.size();
		for(int x : s)
			cout << ' ' << x;
		cout << endl << flush;
		int ans;
		cin >> ans;
		return ans;
	};

	vector<pii> order = get_order(tree, 1);
	int ans = query(order.begin(), order.end());

	auto f = [ans, &query, &order](int middle){
		return query(order.begin(), order.begin() + middle + 1) == ans;
	};

	ans = lowerbound<int>(0, order.size() - 1, f);
	cout << "! " << order[ ans ].first << ' ' << order[ ans ].second << endl << flush;
	return 0;
}