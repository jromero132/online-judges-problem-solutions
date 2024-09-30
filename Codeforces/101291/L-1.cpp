// Problem name: Three Square
// Problem link: https://codeforces.com/gym/101291/problem/L
// Submission link: https://codeforces.com/gym/101291/submission/37240883

#include <bits/stdc++.h>

#define mp make_pair
#define F first
#define S second
#define endl '\n'

using namespace std;

typedef pair<int, int> rect;

rect r[ 3 ], r2[ 3 ];

bool square(rect a, rect b, rect c){
    if(a.F + b.F + c.F == a.S && a.S == b.S && b.S == c.S)
        return 1;
    if(a.F + b.F == a.S + c.S && a.F + b.F == c.F && a.S == b.S)
        return 1;
    return 0;
}

void rot(rect &a){
    a = mp(a.S, a.F);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0 ; i < 3 ; i++)
        cin >> r[ i ].F >> r[ i ].S;
    int order[] = { 0, 1, 2 };
    bool ok = 0;
    do{
        for(int mask = 0 ; mask < 8 ; mask++){
            for(int i = 0 ; i < 3 ; i++)
                r2[ i ] = r[ order[ i ] ];
            for(int i = 0 ; i < 3 ; i++)
                if(mask & (1 << i))
                    rot(r2[ i ]);
            ok |= square(r2[ 0 ], r2[ 1 ], r2[ 2 ]);
        }
    }while(next_permutation(order, order + 3));
    cout << (ok ? "YES" : "NO") << endl;
    return 0;
}