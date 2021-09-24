// Problem name: Travel Cards
// Problem link: https://codeforces.com/contest/847/problem/K
// Submission link: https://codeforces.com/contest/847/submission/30953836

#include <bits/stdc++.h>

#define pb(x) push_back(x)
#define mp(i, j) make_pair(i, j)
#define F first
#define S second

using namespace std;

typedef pair<string, string> pss;

int n, a, b, k, f;
map<pss, int> travel;

bool cmp(pair<pss, int> a, pair<pss, int> b){
    return a.S > b.S;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b >> k >> f;
    string s1, s2, s;
    pss now;
    int price = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> s1 >> s2;
        now = mp(s1, s2);
        price += (s1 == s ? b : a);
        if(travel[ now ])
            travel[ now ]+= (s1 == s ? b : a);
        else
            travel[ mp(now.S, now.F) ]+= (s1 == s ? b : a);
        s = s2;
    }
    vector< pair<pss, int> > order;
    for(auto i : travel)
        if(i.S)
            order.pb(i);
    sort(order.begin(), order.end(), cmp);
    for(int i = 0 ; i < k && i < order.size() ; i++){
        //cout << order[ i ].S * a << endl;
        if(order[ i ].S < f)
            break;
        price += f - order[ i ].S ;
    }
    cout << price << endl;
    return 0;
}