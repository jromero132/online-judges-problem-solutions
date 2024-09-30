// Problem name: Help Kingdom of Far Far Away 2
// Problem link: https://codeforces.com/contest/143/problem/B
// Submission link: https://codeforces.com/contest/143/submission/25694273

#include <bits/stdc++.h>

#define MAX (int)(1e1)
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int separator = 3;
const int rounded = 2;
int p;
string num;

void findDot(){
    for(p = 0 ; num[ p ] != '\0' ; p++)
        if(num[ p ] == '.')
            return;
}

void print(){
    findDot();
    int i = (num[ 0 ] == '-'), aux = (p - i) % separator + i;
    cout << (i ? "(" : "") << '$';
    bool ok = 0;
    for( ; i < aux ; i++)
        cout << num[ i ], ok = 1;
    for( ; i < p ; i += separator){
        cout << (ok ? "," : "");
        ok = 1;
        for(int j = 0 ; j < separator ; j++)
            cout << num[ i + j ];
    }
    cout << '.';
    p++;
    for(i = 0 ; p < num.length() && i < rounded ; i++)
        cout << num[ p++ ];
    for( ; i < rounded ; cout << '0', i++);
    cout << (num[ 0 ] == '-' ? ")" : "")<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> num;
    print();
    return 0;
}