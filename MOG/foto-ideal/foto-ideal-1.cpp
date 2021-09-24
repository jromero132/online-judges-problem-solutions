// Problem name: E - Foto Ideal
// Problem link: https://matcomgrader.com/problem/9103/foto-ideal/
// Submission link: https://matcomgrader.com/submission/126863/

#include <bits/stdc++.h>

#define INF ((double)1e15)
#define x first
#define y second
#define endl '\n'

using namespace std;

typedef pair<double, double> point;

double dist(point p1, point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double f(vector<point> &equipo1, vector<point> &equipo2, double x)
{
    double distance_sum = 0;
    int n = equipo1.size(), e1 = 0, e2 = 0;
    for(int i = 0; i < 2 * n; i++)
    {
        if(e2 == n || (e1 < n && equipo1[e1] < equipo2[e2]))
        {
            distance_sum += dist(equipo1[e1], point(x, 0));
            e1++;
        }
        else
        {
            distance_sum += dist(equipo2[e2], point(x,0));
            e2++;
        }
        x++;
    }
    return distance_sum;
}

double ternary_search(vector<point> &equipo1, vector<point> &equipo2)
{
    int iterations = 100;
    double left = -INF, right = INF;
    while(iterations--)
    {
        double x1 = left + (right - left) / 3, x2 = right - (right - left) / 3;
        if(f(equipo1, equipo2, x1) > f(equipo1, equipo2, x2))
            left = x1;
        else
            right = x2;
    }
    return left;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vector<point> equipo1(n), equipo2(n);
    for(int i = 0; i < n; i++)
    {
        cin >> equipo1[i].x;
        equipo1[i].y = 1;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> equipo2[i].x;
        equipo2[i].y = -1;
    }
    sort(equipo1.begin(), equipo1.end());
    sort(equipo2.begin(), equipo2.end());
    cout << setprecision(2) << fixed << f(equipo1, equipo2, ternary_search(equipo1, equipo2)) << endl;
    return 0;
}