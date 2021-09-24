// Problem name: F - 3D Printed Statues
// Problem link: https://matcomgrader.com/problem/9213/3d-printed-statues/
// Submission link: https://matcomgrader.com/submission/117843/

#include <iostream>

#define CLZ(x) (__builtin_clz(x))
#define LOG2(x) (31 - CLZ(x))

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, a = 1, b = 1;
    cin >> n;
    while(a < n)
        a <<= 1LL, b++;
    cout << b << endl;
    return 0;
}