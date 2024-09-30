// Problem name: Sliding Minimum Element
// Problem link: https://vjudge.net/problem/Aizu-DSL_3_D
// Submission link: https://vjudge.net/solution/12830228

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

struct MonotonicQueue{
	queue<int> q;
	deque<int> m;

	void Push(int n){
		q.push(n);
		while(!m.empty() && *(m.end() - 1) > n)
			m.pop_back();
		m.push_back(n);
	}

	void Pop(){
		if(q.front() == m.front())
			m.pop_front();
		q.pop();
	}

	int Front(){
		return q.front();
	}

	int Min(){
		return m.front();
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, l, v;
	MonotonicQueue q;
	cin >> n >> l;
	for(int i = 0 ; i < l ; i++)
		cin >> v, q.Push(v);
	cout << q.Min();
	for(int i = l ; i < n ; i++)
		cin >> v, q.Pop(), q.Push(v), cout << ' ' << q.Min();
	cout << endl;
	return 0;
}