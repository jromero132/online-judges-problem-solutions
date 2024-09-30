// Problem name: Spreadsheet
// Problem link: https://codeforces.com/contest/1/problem/B
// Submission link: https://codeforces.com/contest/1/submission/27364076

#include <iostream>

#define endl '\n'

#define READ(t) for(cin >> t ; t ; t--)

using namespace std;

typedef long long ll;

string s, b, e;

string ToRXCY(int i){
    string row = "R" + e, col = "";
    ll c = 0, p = 1;
    for( ; i >= 0 ; i--)
        c += p * (s[ i ] - 64), p *= 26;
    do{
        col = (char)(c % 10 + 48) + col;
        c /= 10;
    }while(c);
    return row + "C" + col;
}

string ToExcel(int i){
    string row = "", col = "";
    for(i-- ; i ; row = s[ i-- ] + row);
    ll c = 0, p = 1;
    for(i = e.length() - 1 ; i >= 0 ; i--)
        c += (e[ i ] - 48) * p, p *= 10;
    do{
        col = (char)(c % 26 + 64) + col;
        if(col[ 0 ] == 64)
            col[ 0 ] = 90, c--;
        c /= 26;
    }while(c);
    return col + row;
}

string solve(){
    int i;
    b = e = "";
    for(i = s.length() - 1 ; i >= 0 ; i--){
        if(s[ i ] >= 48 && s[ i ] <= 57)
            e = s[ i ] + e;
        else
            break;
    }
    if(i == 0 || (s[ i - 1 ] >= 65 && s[ i - 1 ] <= 90))
        return ToRXCY(i);
    return ToExcel(i);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    READ(t){
        cin >> s;
        cout << solve() << endl;
    }
    return 0;
}