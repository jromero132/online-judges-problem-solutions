// Problem name: Knapsack Problem with Limitations
// Problem link: https://vjudge.net/problem/Aizu-DPL_1_G
// Submission link: https://vjudge.net/solution/12818400

#include <iostream>

#define MAX ((int)10010)
#define endl '\n'

using namespace std;

int DP[ MAX ], aux[ MAX ], auxV[ MAX ];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, W, v, w, m, head, tail, now;
    cin >> n >> W;
    for(int i = 0 ; i < n ; i++){
        cin >> v >> w >> m;
        for(int k = 0 ; k < w ; k++){
            head = tail = 0;
            for(int j = 0 ; j * w + k <= W ; j++){
                now = DP[ j * w + k ] - j * v;
                while(head < tail && auxV[ tail - 1 ] <= now)
                    tail--;
                aux[ tail ] = j;
                auxV[ tail++ ] = now;
                DP[ j * w + k ] = auxV[ head ] + j * v;
                if(aux[ head ] == j - m)
                    head++;
            }
        }
    }
    cout << DP[ W ] << endl;
    return 0;
}