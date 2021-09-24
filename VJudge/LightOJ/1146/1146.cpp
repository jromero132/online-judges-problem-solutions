// Problem name: Closest Distance
// Problem link: https://vjudge.net/problem/LightOJ-1146
// Submission link: https://vjudge.net/solution/17887045

#include <bits/stdc++.h>

#define x first
#define y second
#define endl '\n'

using namespace std;

typedef pair<double, double> point;

double dist(point p1, point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

point get_point(point a, point b, double t)
{
    return point(a.x + t * (b.x - a.x), a.y + t * (b.y - a.y));
}

double f(point a, point b, point c, point d, double t){
    return dist(get_point(a, b, t), get_point(c, d, t));
}

double ternary_search(point a, point b, point c, point d)
{
    int iterations = 100;
    double left = 0, right = 1;
    while(iterations--)
    {
        double x1 = left + (right - left) / 3, x2 = right - (right - left) / 3;

        if(f(a, b, c, d, x1) > f(a, b, c, d, x2))
            left = x1;
        else
            right = x2;
    }
    return left;
}

int main()
{
    int t;
    scanf("%d", &t);
    point a, b, c, d;
    for(int i = 1 ; i <= t ; i++)
    {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y);
        printf("Case %d: %.10lf\n", i, f(a, b, c, d, ternary_search(a, b, c, d)));
    }

    return 0;
}