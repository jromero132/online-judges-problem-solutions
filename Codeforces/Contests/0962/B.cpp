// Problem name: Students in Railway Carriage
// Problem link: https://codeforces.com/contest/962/problem/B
// Submission link: https://codeforces.com/contest/962/submission/37161003

#include <iostream>

#define MAX ((int)200001)
#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, a, b, ans = 0, p;
    string s;
    cin >> n >> a >> b >> s;
    for(int i = 0 ; s[ i ] ; ){
        if(s[ i ] == '*'){
            i++;
            continue;
        }
        for(p = 1 ; s[ i + p ] == '.' ; p++);
        i += p;
        if(a < b)
            swap(a, b);
        if(p & 1){
            if(b >= (p >> 1)){
                a -= (p >> 1);
                b -= (p >> 1);
                ans += p - 1;
                if(a)
                    a--, ans++;
            }
            else{
                ans += (b << 1);
                p -= (b << 1);
                a -= b;
                b = 0;
                ans += min(a, (p + 1) >> 1);
                a -= min(a, (p + 1) >> 1);
            }
        }
        else{
            if(b >= (p >> 1))
                a -= (p >> 1), b -= (p >> 1), ans += p;
            else{
                ans += (b << 1);
                p -= (b << 1);
                a -= b;
                b = 0;
                ans += min(a, ((p + 1) >> 1));
                a -= min(a, ((p + 1) >> 1));
            }
        }
    }
    cout << ans << endl;
    return 0;
}