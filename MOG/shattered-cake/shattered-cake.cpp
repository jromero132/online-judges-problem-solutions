// Problem name: F - Shattered Cake
// Problem link: https://matcomgrader.com/problem/9493/shattered-cake/
// Submission link: https://matcomgrader.com/submission/123867/

#include <bits/stdc++.h>

#define MAX ((int)2000)
#define endl '\n'

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    ll W, A = 0, w, l;
    int n;
    cin >> W >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> w >> l, A += w * l;
    cout << A / W << endl;
    return 0;
}