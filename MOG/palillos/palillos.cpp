// Problem name: B - Palillos
// Problem link: https://matcomgrader.com/problem/9204/palillos/
// Submission link: https://matcomgrader.com/submission/120634/

#include <bits/stdc++.h>

#define MAX (int)(1 << 4)
#define pb(x) push_back(x)

using namespace std;

int array[ MAX ];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, sum1 = 0, sum2, sum3;
    bool ok;
    vector<int> aux1, aux2;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> array[ i ], sum1 += array[ i ];
    if(sum1 & 3){
        cout << "NO";
        return 0;
    }
    for(int mask = 1 ; mask < (1 << n) ; mask++){
        aux1.clear();
        aux2.clear();
        sum2 = 0;
        for(int i = 0 ; i < n ; i++){
            if(mask & (1 << i))
                aux1.pb(array[ i ]), sum2 += array[ i ];
            else
                aux2.pb(array[ i ]);
        }
        if(sum2 != (sum1 >> 1))
            continue;
        ok = 0;
        for(int mask2 = (1 << aux1.size() - 1) ; mask2 ; mask2--){
            sum3 = 0;
            for(int i = aux1.size() - 1 ; i >= 0 ; i--)
                if(mask2 & (1 << i))
                    sum3 += aux1[ i ];
            if(sum3 == (sum2 >> 1)){
                ok = 1;
                break;
            }
        }
        if(ok){
            for(int mask2 = (1 << aux2.size() - 1) ; mask2 ; mask2--){
                sum3 = 0;
                for(int i = aux2.size() - 1 ; i >= 0 ; i--)
                    if(mask2 & (1 << i))
                        sum3 += aux2[ i ];
                if(sum3 == (sum2 >> 1)){
                    cout << "SI";
                    return 0;
                }
            }
        }
    }
    cout << "NO";
    return 0;
}