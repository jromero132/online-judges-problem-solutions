// Problem name: Hissing Microphone
// Problem link: https://open.kattis.com/problems/hissingmicrophone
// Submission link: https://open.kattis.com/submissions/3695705

#include <bits/stdc++.h>

using namespace std;

bool hissing(string s){
    for(int i = 1 ; s[ i ] ; ++i)
        if(s[ i ] == s[ i - 1 ] && s[ i ] == 's')
            return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    string s;
    cin >> s;
    cout << (hissing(s) ? "hiss" : "no hiss") << endl;
    return 0;
}