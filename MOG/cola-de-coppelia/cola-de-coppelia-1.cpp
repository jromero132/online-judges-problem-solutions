// Problem name: C - Cola de Coppelia
// Problem link: https://matcomgrader.com/problem/8/cola-de-coppelia/
// Submission link: https://matcomgrader.com/submission/125900/

#include <iostream>
#include <utility>

#define F first
#define S second
#define endl '\n'

using namespace std;

typedef long long ll;

template<typename T>
struct linked_list{
	struct node{
		T v;
		node *previous = NULL, *next = NULL;

		node(const T &v, node *previous = NULL, node *next = NULL) : v(v), previous(previous), next(next){ }

		void operator =(const node &n){
			v = n.v;
			previous = n.previous;
			next = n.next;
		}
	} *root, *last;

	int n;

	linked_list() : root(NULL), last(NULL), n(0){ }

	void push_front(const T &v){
		root = (n++ ? (root -> previous) = new node(v, NULL, root) : last = new node(v));
	}

	void push_back(const T &v){
		last = (n++ ? (last -> next) = new node(v, last) : root = new node(v));
	}

	void pop_front(){
		root = (--n ? (root -> next) : last = NULL);
	}

	void pop_back(){
		last = (--n ? (last -> previous) : root = NULL);
	}

	int size() const{
		return n;
	}

	bool empty() const{
		return !n;
	}

	T front() const{
		return root -> v;
	}

	T back() const{
		return last -> v;
	}
};

template<typename T>
struct stack{
	linked_list<T> s;

	stack(){ }

	void push(const T &v){
		s.push_front(v);
	}

	void pop(){
		s.pop_front();
	}

	T top() const{
		return s.front();
	}

	int size() const{
		return s.size();
	}

	bool empty() const{
		return s.empty();
	}
};

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

	int size() const{
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