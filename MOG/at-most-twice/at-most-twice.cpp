// Problem name: A - At most twice
// Problem link: https://matcomgrader.com/problem/9290/at-most-twice/
// Submission link: https://matcomgrader.com/submission/121136/

#include <bits/stdc++.h>

#define MAX (int)(1e1)
#define MOD (ll)(1e9 + 7)
#define mod(x) (((x) % MOD + MOD) % MOD)

using namespace std;

typedef long long ll;

int nums[ MAX ];
string s;

void fix(int i){
    if(i == 0){
        nums[ s[ i ] - 48 ]--;
        s[ i ] = 0;
        return;
    }
    do{
        if(s[ i ] != 48){
            nums[ s[ i ] - 48 ]--;
            s[ i ]--;
            nums[ s[ i ] - 48 ]++;
        }
        else{
            nums[ 0 ]--;
            fix(i - 1);
            s[ i ] = '9';
            nums[ 9 ]++;
        }
    } while(nums[ s[ i ] - 48 ] == 3);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	bool first = 1;
	cin >> s;
	for(int i = 0 ; s[ i ] != '\0' ; i++){
        nums[ s[ i ] - 48 ]++;
        if(nums[ s[ i ] - 48 ] == 3){
            fix(i);
            if(first){
                first = 0;
                for(int j = i + 1 ; s[ j ] != '\0' ; j++)
                    s[ j ] = '9';
            }
        }
	}
	for(int i = (s[ 0 ] == 0) ; s[ i ] != '\0' ; i++)
        cout << s[ i ];
    return 0;
}