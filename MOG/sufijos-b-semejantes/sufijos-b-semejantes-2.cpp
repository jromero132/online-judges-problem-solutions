// Problem name: F - Sufijos b-semejantes
// Problem link: https://matcomgrader.com/problem/9524/sufijos-b-semejantes/
// Submission link: https://matcomgrader.com/submission/125137/

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

vector<int> z, DP;

void z_function(string s){
    int len = s.length();
    z.clear();
    z.resize(len);
    z[ 0 ] = len;
    for(int i = 1, left = 0, right = 0 ; i < len ; i++){
        if(i <= right)
            z[ i ] = min(right - i + 1, z[ i - left ]);
        while(i + z[ i ] < len && s[ z[ i ] ] == s[ i + z[ i ] ])
            z[ i ]++;
        if(i + z[ i ] - 1 > right)
            left = i, right = i + z[ i ] - 1;
    }
}

void preprocess(string s){
    z_function(s);
    int len = s.length();
    DP.clear();
    DP.resize(len + 1);
    for(int i = 0 ; i < len ; DP[ z[ i++ ] ]++);
    for(int i = len - 1 ; i >= 0 ; i--)
        DP[ i ] += DP[ i + 1 ];
    DP[ 0 ] = len;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t, n, k;
    string s;
    for(cin >> t ; t-- ; ){
        cin >> s;
        preprocess(s);
        for(cin >> n ; n-- ; )
            cin >> k, cout << (k <= s.length() ? DP[ k ] : 0) << " \n"[ t != 0 ];
    }
    return 0;
}