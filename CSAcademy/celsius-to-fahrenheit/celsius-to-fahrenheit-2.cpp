// Problem name: Celsius to Fahrenheit
// Problem link: https://csacademy.com/contest/archive/task/celsius-to-fahrenheit/
// Submission link: https://csacademy.com/submission/1407502/

#include <bits/stdc++.h>

#define MAX ((int)1000000)
#define MOD ((int)1000000007)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int c;
    cin >> c;
    cout << (int)(c * 1.8 + 32) << endl;
    return 0;
}