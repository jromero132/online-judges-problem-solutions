// Problem name: Full Binary Tree Queries
// Problem link: https://codeforces.com/contest/960/problem/D
// Submission link: https://codeforces.com/contest/960/submission/37111004

#include <bits/stdc++.h>

#define MAX ((int)61)
#define endl '\n'

using namespace std;

typedef long long ll;

ll tree[ MAX ];

void preprocess(){
    tree[ 0 ] = 1LL;
    for(int i = 1 ; i < MAX ; i++)
        tree[ i ] = (tree[ i - 1 ] << 1LL);
}

int level(ll x){
    int l = 0;
    ll p = 1LL;
    while(p <= x)
        p <<= 1LL, l++;
    return --l;
}

void rot(ll x, ll k){
    int l = level(x);
    k = -k;
    k %= (1LL << l);
    if(k < 0LL)
        k += (1LL << l);
    tree[ l ] = (tree[ l ] + k) % (1LL << l) + (1LL << l);
}

ll get(int l, ll p){
    ll aux = tree[ l ] + p;
    if(aux >= (1LL << l))
        aux = (aux % (1LL << l)) + (1LL << l);
    return aux;
}

ll get_position(int l, ll n){
    ll aux = n - tree[ l ];
    if(aux < 0LL)
        aux += (1LL << l);
    return aux;
}

void print(ll x){
    int l = level(x);
    ll p = get_position(l, x);
    while((x = get(l, p)) != 1){
        cout << x << ' ';
        l--;
        p >>= 1LL;
    }
    cout << 1 << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    preprocess();

    int q, ope, l;
    ll x, k;
    for(cin >> q ; q-- ; ){
        cin >> ope >> x;
        if(ope == 3)
            print(x);
        else{
            cin >> k;
            if(ope == 1)
                rot(x, k);
            else{
                l = level(x);
                for( ; l < MAX ; l++)
                    rot(x, k), x <<= 1LL, k <<= 1LL;
               }
        }
    }
	return 0;
}