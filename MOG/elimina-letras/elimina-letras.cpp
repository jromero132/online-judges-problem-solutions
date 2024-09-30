// Problem name: B - Elimina letras
// Problem link: https://matcomgrader.com/problem/9196/elimina-letras/
// Submission link: https://matcomgrader.com/submission/116895/

#include <bits/stdc++.h>

#define MOD (int)(1e9 + 7)
#define MAX (int)(2e5 + 1)
#define INF (ll)(1e18)
#define EPS (double)(1e-7)
#define pb(x) push_back((x))
#define pf(x) push_front((x))
#define mp(x, y) make_pair((x), (y))
#define F first
#define S second
#define LEFT(i) ((i) << 1)
#define RIGHT(i) ((i) << 1 | 1)
#define FATHER(i) ((i) >> 1)
#define endl '\n'

#define FOR(i, n, m) for(int i = m ; i < n + m ; i++)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;

string s, ss;
bool del[ MAX ];
int pos[ MAX ];

void Delete(int i, int j){
    for( ; i <= j ; i++)
        del[ pos[ i ] - 1 ] = 1;
}

void Put(int i, int j){
    for( ; i <= j ; i++)
        del[ pos[ i ] - 1 ] = 0;
}

bool Contains(){
    int p = 0;
    for(int i = 0 ; i < s.length() ; i++)
        if(!del[ i ] && s[ i ] == ss[ p ]){
            p++;
            if(p == ss.length())
                return 1;
        }
    return 0;
}

int BinarySearch(){
    int left = 0, right = s.length(), mid;
    while(left <= right){
        mid = ((left + right) >> 1);
        Delete(left, mid);
        if(Contains())
            left = mid + 1;
        else{
            Put(left, mid);
            right = mid - 1;
        }
    }
    return left;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> ss;
    for(int i = 0 ; i < s.length() ; cin >> pos[ i++ ]);
    cout << BinarySearch();
    return 0;
}