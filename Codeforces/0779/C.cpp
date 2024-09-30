// Problem name: Dishonest Sellers
// Problem link: https://codeforces.com/contest/779/problem/C
// Submission link: https://codeforces.com/contest/779/submission/25063108

#include <iostream>
#include <algorithm>

#define MAX (int)(2e5 + 3)

using namespace std;

struct product{
    int price, offer;
};

bool cmp(product a, product b){
    if(a.offer - a.price != b.offer - b.price)
        return a.offer - a.price > b.offer - b.price;
    return a.price > b.price;
}

int n, k;
product item[ MAX ];

int solve(){
    sort(item, item + n, cmp);
    int ans = 0, i;
    for(i = 0 ; i < k ; i++)
        ans += item[ i ].price;
    for( ; i < n && item[ i ].price < item[ i ].offer ; i++)
        ans += item[ i ].price;
    for( ; i < n ; i++)
        ans += item[ i ].offer;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> n >> k;
    for(int i = 0 ; i < n ; i++)
        cin >> item[ i ].price;
    for(int i = 0 ; i < n ; i++)
        cin >> item[ i ].offer;
    cout << solve() << endl;
    return 0;
}