// Problem name: MaratonIME eats japanese food
// Problem link: https://codeforces.com/gym/101375/problem/C
// Submission link: https://codeforces.com/gym/101375/submission/37113543

#include <bits/stdc++.h>

#define MAX ((int)100000)
#define sqr(x) ((x) * (x))
#define pb push_back
#define endl '\n'

using namespace std;

typedef long long ll;

struct circle{
    int x, y, r;

    circle(int x, int y, int r) : x(x), y(y), r(r){ }

    bool operator == (circle c){
        return x == c.x && y == c.y && r == c.r;
    }
};

int len = 0;
vector<circle> circles;

int on_table(circle c){
    for(int i = 0 ; i < len ; i++)
        if(circles[ i ] == c)
            return i;
    return -1;
}

bool overlaps(circle c){
    for(int i = 0 ; i < len ; i++)
        if(sqr(circles[ i ].x - c.x) + sqr(circles[ i ].y - c.y) < sqr(circles[ i ].r + c.r))
            return 1;
    return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int q, x, y, r;
    char ope;
    for(cin >> q ; q-- ; ){
        cin >> ope >> x >> y >> r;
        if(ope == 'A'){
            if(overlaps(circle(x, y, r)))
                cout << "No" << endl;
            else{
                cout << "Ok" << endl;
                circles.pb(circle(x, y, r));
                len++;
            }
        }
        else{
            if((r = on_table(circle(x, y, r))) != -1){
                circles.erase(circles.begin() + r, circles.begin() + r + 1);
                len--;
                cout << "Ok" << endl;
            }
            else
                cout << "No" << endl;
        }
    }
	return 0;
}