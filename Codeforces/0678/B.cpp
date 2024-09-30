// Problem name: The Same Calendar
// Problem link: https://codeforces.com/contest/678/problem/B
// Submission link: https://codeforces.com/contest/678/submission/25027817

#include <iostream>

using namespace std;

bool isLeap(int n){
    return !(n % 400) || (!(n % 4) && (n % 100));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k = 0;
    cin >> n;
    bool leap = isLeap(n);
    do{
        if(isLeap(n))
            k++;
        n++;
        k++;
        k %= 7;
    }while(k || (leap != isLeap(n)));
    cout << n << endl;
    return 0;
}