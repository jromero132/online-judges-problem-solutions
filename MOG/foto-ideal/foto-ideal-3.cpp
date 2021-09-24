// Problem name: E - Foto Ideal
// Problem link: https://matcomgrader.com/problem/9103/foto-ideal/
// Submission link: https://matcomgrader.com/submission/126861/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,a;
vector<int> equipo1;
vector<int> equipo2;

double my_distance(double x1,double y1,double x2,double y2)
{
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

double my_function(double x)
{
    double distance_sum = 0;
    int m = 0,b = 0;
    for(int i = 0;i < 2*n;i++)
    {
        if(b == n || (m < n && equipo1[m] < equipo2[b]))
        {
            distance_sum += my_distance(equipo1[m],1,x,0);
            m++;
        }
        else
        {
            distance_sum += my_distance(equipo2[b],-1,x,0);
            b++;
        }
        x++;
    }
    return distance_sum;
}

void TernarySearch()
{
    double left = -1000000;
    double right = 1000000;
    int iterations = 100;
    double x,y;
    while(iterations--)
    {
        x = left + (right - left)/3;
        y = right - (right - left)/3;
        if(my_function(x) > my_function(y))
            left = x;
        else
            right = y;
    }
    cout << my_function(x) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(2) << fixed;

    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> a;
        equipo1.push_back(a);
    }
    for(int i = 0;i < n;i++)
    {
        cin >> a;
        equipo2.push_back(a);
    }
    sort(equipo1.begin(),equipo1.end());
    sort(equipo2.begin(),equipo2.end());
    TernarySearch();


    return 0;
}