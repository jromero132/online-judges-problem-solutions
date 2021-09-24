// Problem name: C - Cola de Coppelia
// Problem link: https://matcomgrader.com/problem/8/cola-de-coppelia/
// Submission link: https://matcomgrader.com/submission/125899/

#include <bits/stdc++.h>

#define F first
#define S second
#define endl '\n'

using namespace std;

typedef long long ll;

template<typename T, typename C = less_equal<T>>
struct monotonic_stack{
	stack<T> s, m;
	C cmp;

	monotonic_stack() : cmp(C()){ }

	void push(const T &x){
		s.push(x);
		m.push(m.empty() ? x : (cmp(m.top(), x) ? m.top() : x));
	}

	void pop(){
		s.pop();
		m.pop();
	}

	T top() const{
		return s.top();
	}

	T first() const{
		return m.top();
	}

	bool empty() const{
		return s.empty();
	}

	size_t size() const{
		return s.size();
	}
};

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
#endif

	int n;
	ll ans = 0;
	monotonic_stack<pair<int, int>> ms;
	cin >> n;
	for(int i = 0, x ; i < n ; ++i){
		cin >> x;
		for( ; !ms.empty() && ms.first().F < x ; ++ans, ms.pop());
		if(!ms.empty()){
			if(ms.first().F == x)
				ans += -ms.first().S, ms.push({ x, ms.first().S - 1 });
			else
				++ans, ms.push({ x, -2 });
		}
		else
			ms.push({ x, -1 });
	}
	cout << ans << endl;
	return 0;
}