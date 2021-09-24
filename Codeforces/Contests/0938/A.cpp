// Problem name: Word Correction
// Problem link: https://codeforces.com/contest/938/problem/A
// Submission link: https://codeforces.com/contest/938/submission/35341863

#include <bits/stdc++.h>

#define MAX ((int)1000001)
#define MAX_DIG ((int)10)
#define pb push_back
#define mp make_pair
#define endl '\n'

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;

bool isVowel(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int len;
    string s, ans = "";
    cin >> len >> s;
    ans += s[ 0 ];
    for(int i = 1 ; i < len ; i++){
        if(isVowel(s[ i ]) && isVowel(s[ i - 1 ]))
            continue;
        ans += s[ i ];
    }
    cout << ans;
	return 0;
}