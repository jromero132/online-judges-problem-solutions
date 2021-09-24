// Problem name: Searching Rectangles
// Problem link: https://vjudge.net/problem/CodeForces-713B
// Submission link: https://vjudge.net/solution/13287291

#include <bits/stdc++.h>

#define mp make_pair
#define F first
#define S second

using namespace std;

typedef pair<int, int> pii;

struct rectangle{
    pii bl, tr;

    rectangle() : rectangle(0, 0, 0, 0){ }

    rectangle(int b, int l, int t, int r) : bl(mp(b, l)), tr(mp(t, r)){ }
};

int query(int l, int b, int r, int t){
    printf("? %d %d %d %d\n", l, b, r, t);
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    return ans;
}

int xline(int n){
    int left = 1, right = n, middle, r;
    bool ok = 0;
    while(left <= right){
        middle = (left + right) >> 1;
        r = query(1, 1, middle, n);
        if(r == 1 && query(middle + 1, 1, n, n) == 1){
            ok = 1;
            break;
        }
        else if(!r)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return ok ? middle : -1;
}

int yline(int n){
    int left = 1, right = n, middle, r;
    bool ok = 0;
    while(left <= right){
        middle = (left + right) >> 1;
        r = query(1, 1, n, middle);
        if(r == 1 && query(1, middle + 1, n, n) == 1){
            ok = 1;
            break;
        }
        else if(!r)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return ok ? middle : -1;
}

int getLine1(rectangle r){
    int left = r.bl.F - 1, right = r.tr.F, middle;
    while(left + 1 < right){
        middle = (left + right) >> 1;
        if(query(r.bl.F, r.bl.S, middle, r.tr.S) == 1)
            right = middle;
        else
            left = middle;
    }
    return right;
}

int getLine2(rectangle r){
    int left = r.bl.S - 1, right = r.tr.S, middle;
    while(left + 1 < right){
        middle = (left + right) >> 1;
        if(query(r.bl.F, r.bl.S, r.tr.F, middle) == 1)
            right = middle;
        else
            left = middle;
    }
    return right;
}

int getLine3(rectangle r){
    int left = r.bl.F, right = r.tr.F + 1, middle;
    while(left + 1 < right){
        middle = (left + right) >> 1;
        if(query(middle, r.bl.S, r.tr.F, r.tr.S) == 1)
            left = middle;
        else
            right = middle;
    }
    return left;
}

int getLine4(rectangle r){
    int left = r.bl.S, right = r.tr.S + 1, middle;
    while(left + 1 < right){
        middle = (left + right) >> 1;
        if(query(r.bl.F, middle, r.tr.F, r.tr.S) == 1)
            left = middle;
        else
            right = middle;
    }
    return left;
}

rectangle findRectangle(int b, int l, int t, int r){
    rectangle ans(b, l, t, r);
    ans.tr.F = getLine1(ans);
    ans.tr.S = getLine2(ans);
    ans.bl.F = getLine3(ans);
    ans.bl.S = getLine4(ans);
    return ans;
}

int main(){
	int n, sep;
	scanf("%d", &n);
	sep = xline(n);
	rectangle r1, r2;
	if(sep != -1)
        r1 = findRectangle(1, 1, sep, n), r2 = findRectangle(sep + 1, 1, n, n);
	else
        sep = yline(n), r1 = findRectangle(1, 1, n, sep), r2 = findRectangle(1, sep + 1, n, n);
	printf("! %d %d %d %d %d %d %d %d\n", r1.bl.F, r1.bl.S, r1.tr.F, r1.tr.S, r2.bl.F, r2.bl.S, r2.tr.F, r2.tr.S);
	fflush(stdout);
	return 0;
}