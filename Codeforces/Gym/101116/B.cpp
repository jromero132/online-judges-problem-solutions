// Problem name: Bulbs
// Problem link: https://codeforces.com/gym/101116/problem/B
// Submission link: https://codeforces.com/gym/101116/submission/21213469

#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<map>


#define MAXN 10001

using namespace std;

typedef pair<double,double> pdd;

int n,t,m;

string a[500];

int M[500][500];

int main()
{
	cin >> t;
	while(t--)
	{
		cin >> n >> m;

		for(int i = 0 ; i < n ; i++)
		{
			cin >> a[i];
		}

		int s1 = 0;
		int s2 = 0;

		for(int i = 0;i < n ; i++)
		{
			for(int j = 0; j < m ; j++)
			{
				M[i][j] = a[i][j] - '0';
			}
		}

		for(int i = 0; i < n ; i++)
		{
			for(int j = m - 1; j >=0 ; j--)
			{
				if(M[i][j] == 0)
				{
					s1++;
					for(int k = j; k >= 0;k--)
					{
						if(M[i][k]== 0)
							M[i][k] = 1;
						else
							M[i][k] = 0;
					}
					for(int k = i; k < n ; k++)
					{
						if(M[k][j] == 0)
							M[k][j] = 1;
						else
							M[k][j] = 0;
					}
				}
			}
		}

		cout << s1 << endl;
	}
}