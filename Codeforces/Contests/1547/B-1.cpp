// Problem name: Alphabetical Strings
// Problem link: https://codeforces.com/contest/1547/problem/B
// Submission link: https://codeforces.com/contest/1547/submission/122042197

#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>
using namespace std;
int const INF = (int)1e9 + 1e3;
long long const INFL = (long long)1e18 + 1e6;
 
#ifdef LOCAL
    mt19937 tw(9450189);
#else
    mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<long long> ll_distr;
long long rnd(long long a, long long b) { return ll_distr(tw) % (b - a + 1) + a; }
 
 
 
 
 
 
struct test{
    void solve(){
 
/* ___________________________________________________*/
 
    //start here
 
    //first check;
    int aphabets[26] = {0};
    int chk = 1;
    string s; cin>>s;
    int n = s.size();
    int mx = -1;
    int idx = -1;
    for(int i = 0; i<n; i++){
        aphabets[s[i]-'a']++;
        mx = max(s[i]-'a', mx);
        if(s[i]=='a') idx = i;
 
    }
    for(int i = 0; i<=mx; i++){
        if(!aphabets[i]||aphabets[i]>1) chk = 0;
    }
 
    for(int i = idx+1; i<n; i++){
        if(s[i]-s[i-1]<=0) chk = 0;
    }
 
    for(int i = idx - 1; i>=0; i--){
        if(s[i] - s[i+1]<=0) chk = 0;
    }
 
    cout<<(chk?"YES\n":"NO\n");
 
    
 
 
 
/*_____________________________________________________*/
 
 
    }
};
 
 
 
 
 
int main() {
 
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
#ifdef LOCAL
    auto start_time = clock();
    cerr << setprecision(3) << fixed;
#endif
    cout << setprecision(15) << fixed;
    ios::sync_with_stdio(false);
 
    cin.tie(nullptr);
 
    int test_count = 1;
    cin >> test_count;
    test T;
    for (int test = 1; test <= test_count; ++test) {
        T. solve();
    }
 
#ifdef LOCAL
    auto end_time = clock();
    cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}