// Problem name: Sliding Minimum Element
// Problem link: https://vjudge.net/problem/Aizu-DSL_3_D
// Submission link: https://vjudge.net/solution/16669727

#include <bits/stdc++.h>

#define ppf pop_front
#define pb push_back
#define ppb pop_back
#define endl '\n'

using namespace std;

template<typename T, typename C = less_equal<T>>
struct monotonic_queue{
    queue<T> q;
    deque<T> m;
    C cmp;

    monotonic_queue() : cmp(C()){ }

    void push(const T &v){
        q.push(v);
        for( ; !m.empty() && !cmp(m.back(), v) ; m.ppb());
        m.pb(v);
    }

    void pop(){
        if(m.front() == q.front())
            m.ppf();
        q.pop();
    }

    T front() const{
        return q.front();
    }

    T first() const{
        return m.front();
    }

    bool empty() const{
        return q.empty();
    }

    int size() const{
        return q.size();
    }
};

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);

#ifdef JoseA132
	freopen("01.in", "r", stdin);
    freopen("01.out", "w", stdout);
#endif

    int n, k;
    monotonic_queue<int> mq;
    cin >> n >> k;
    for(int i = 0, x ; i < k ; ++i)
        cin >> x, mq.push(x);
    cout << mq.first();
    for(int i = k, x ; i < n ; ++i)
        cin >> x, mq.pop(), mq.push(x), cout << ' ' << mq.first();
    cout << endl;
	return 0;
}