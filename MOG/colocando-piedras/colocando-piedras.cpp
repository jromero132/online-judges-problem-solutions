// Problem name: C - Colocando Piedras
// Problem link: https://matcomgrader.com/problem/5882/colocando-piedras/
// Submission link: https://matcomgrader.com/submission/72963/

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    int t,a,j;
    cin>>t;
    int stones[t];
    cin>>stones[0];
    for (int i = 1; i < t; i++)
    {
        cin>>a;
        if (i % 2 == 1)
        {
            j = i - 1;
            if (stones[j] != a)
            {
                while (j >= 0 && stones[j] != a)
                {
                    stones[j] = a;
                    j--;
                }
            }
        }
        stones[i] = a;
    }
    a = 0;
    for (int i = 0; i < t; i++)
        if (stones[i] == 0)
            a++;
    cout<<a;
    return 0;
}