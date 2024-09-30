// Problem name: D - Black Widow
// Problem link: https://matcomgrader.com/problem/9102/black-widow/
// Submission link: https://matcomgrader.com/submission/117486/

#include <iostream>

#define MAX (int)(1e3 + 1)

using namespace std;

int num[ MAX ];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, i, j;
    cin >> n;
    for(i = 0 ; i < n ; cin >> num[ i++ ]);
    for(i = 2 ; ; i++){
        for(j = 0 ; j < n ; j++)
            if(!(num[ j ] % i))
                break;
        if(j == n){
            cout << i;
            break;
        }
    }
    return 0;
}