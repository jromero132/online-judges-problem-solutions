// Problem name: Event Planning
// Problem link: https://codeforces.com/gym/100494/problem/E
// Submission link: https://codeforces.com/gym/100494/submission/21187086

#include <iostream>
#include <algorithm>
#include <vector>

#define MAXH 20
#define pb(n) push_back(n)

using namespace std;

typedef pair<int, int> pii;

pii hotels[ MAXH ];

bool cmp(pii a, pii b){
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, b, h, w, aux;
    cin >> n >> b >> h >> w;
    for(int i = aux = 0 ; i < h ; i++){
        cin >> hotels[ i ].first;
        for(int j = 1 ; j <= w ; j++)
            cin >> aux, hotels[ i ].second = (hotels[ i ].second < aux ? aux : hotels[ i ].second);
    }
    sort(hotels, hotels + h, cmp);
    bool ok = false;
    for(int i = 0 ; i < h ; i++)
        if(hotels[ i ].second >= n && n * hotels[ i ].first <= b){
            cout << n * hotels[ i ].first << endl;
            ok = true;
            break;
        }
    if(!ok)
        cout << "stay home" << endl;
    return 0;
}