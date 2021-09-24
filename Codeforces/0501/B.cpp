// Problem name: Misha and Changing Handles
// Problem link: https://codeforces.com/contest/501/problem/B
// Submission link: https://codeforces.com/contest/501/submission/20929595

#include <iostream>

#define MAX (int)(1e3 + 5)
#define endl '\n'

using namespace std;

string handles[ MAX ][ 2 ];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, i, ans;
    string a, b;
    bool ok;
    for(cin >> t, ans = 0 ; t ; t--){
        cin >> a >> b;
        for(i = 0, ok = false ; handles[ i ][ 0 ] != "" ; i++){
            if(handles[ i ][ 0 ] == a || handles[ i ][ 1 ] == a){
                handles[ i ][ 1 ] = b;
                ok = true;
                break;
            }
        }
        if(!ok)
            handles[ i ][ 0 ] = a, handles[ i ][ 1 ] = b, ans++;
    }
    cout << ans << endl;
    for(i = 0 ; handles[ i ][ 0 ] != "" ; i++)
        cout << handles[ i ][ 0 ] << " " << handles[ i ][ 1 ] << endl;
    return 0;
}