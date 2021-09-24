// Problem name: Help Vasilisa the Wise 2
// Problem link: https://codeforces.com/contest/143/problem/A
// Submission link: https://codeforces.com/contest/143/submission/25693648

#include <bits/stdc++.h>

#define MAX (int)(1e1)
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int c1, c2, d1, d2, r1, r2, n1, n2, n3, n4;

bool solve(){
    for(int i = 1 ; i < MAX ; i++)
        for(int j = 1 ; j < MAX ; j++)
            for(int k = 1 ; k < MAX ; k++)
                for(int m = 1 ; m < MAX ; m++)
                    if(i + j == r1 && k + m == r2 && i + k == c1 && j + m == c2 && i + m == d1 && j + k == d2 && i != j && i != k && i != m && j != k && j != m && k != m){
                        n1 = i;
                        n2 = j;
                        n3 = k;
                        n4 = m;
                        return 1;
                    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    if(solve())
        cout << n1 << " " << n2 << endl << n3 << " " << n4;
    else
        cout << "-1";
    return 0;
}