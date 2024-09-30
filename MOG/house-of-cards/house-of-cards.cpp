// Problem name: D - House of Cards
// Problem link: https://matcomgrader.com/problem/9211/house-of-cards/
// Submission link: https://matcomgrader.com/submission/117900/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string h;

void sum(ll a){
    if(!a)
        return;
    string s = "";
    do{
        s = (char)(a % 10 + 48) + s;
        a /= 10;
    }while(a);
    if(s.length() > h.length())
        h = string(s.length() - h.length(), '0') + h;
    else
        s = string(h.length() - s.length(), '0') + s;
    int carry = 0;
    for(int i = h.length() - 1 ; i >= 0 ; i--){
        carry = h[ i ] + s[ i ] + carry - 96;
        h[ i ] = (char)(carry % 10 + 48);
        carry /= 10;
    }
    if(carry)
        h = '1' + h;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> h;
    ll r = 0, x = 0;
    for(int i = h.length() - 6 ;  ; i++){
        if(i < 0)
            continue;
        if(h[ i ] == '\0')
            break;
        r = r * 10, r += h[ i ] - 48;
    }
    while((r * (r + 1) / 2) % 4 != (3 * r) % 4)
        r++, x++;
    sum(x);
    cout << h << endl;
    return 0;
}