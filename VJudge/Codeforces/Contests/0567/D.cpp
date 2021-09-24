// Problem name: One-Dimensional Battle Ships
// Problem link: https://vjudge.net/problem/CodeForces-567D
// Submission link: https://vjudge.net/solution/13263130

#include <bits/stdc++.h>

#define MAX ((int)200003)
#define endl '\n'

using namespace std;

int n, k, a, m, shot[ MAX ];
bool noShip[ MAX ];

bool k_ships(int limit){
    int ships = 0, last = 0, now = 0;
    memset(noShip, 0, sizeof(noShip));
    for(int i = 0 ; i <= limit ; i++)
        noShip[ shot[ i ] ] = 1;
    for(int i = 1 ; i <= n ; i++, now++)
        if(noShip[ i ]){
            ships += (i - last) / a;
            last = i;
        }
    return (ships + (n + 1 - last) / a) >= k;
}

int lie_on(){
    int left = 0, right = m - 1, middle;
    while(left < right){
        middle = (left + right) >> 1;
        if(k_ships(middle))
            left = middle + 1;
        else
            right = middle - 1;
    }
    if(k_ships(left))
        left++;
    return left == m ? -2 : left;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cin >> n >> k >> a >> m;
    a++;
    for(int i = 0 ; i < m ; i++)
        cin >> shot[ i ];
    cout << lie_on() + 1 << endl;
	return 0;
}