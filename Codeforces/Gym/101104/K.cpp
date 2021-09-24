// Problem name: Lucky Light
// Problem link: https://codeforces.com/gym/101104/problem/K
// Submission link: https://codeforces.com/gym/101104/submission/21052964

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<float, float> pdd;
typedef pair<int, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;

int t;
int n;

double eps = 1e-8;

pair<pdd,pdd> a[500];

vector<pdd> XX;

bool cmp(pair<pdd,pdd> a,pair<pdd,pdd> b)
{
	return a.first.first < b.first.first;
}

bool comp(pdd a,pdd b)
{
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--)
	{
		XX.clear();
		cin >> n;

		float xc,yc;
		cin >> xc >> yc;

		for(int i = 0;  i < n ;i++)
		{
			float x,y,xx,yy;
			cin >> x >> y >> xx >> yy;
			if(xx < x)
			{
				swap(x,xx);
				swap(y,yy);
			}
			a[i] = make_pair(pdd(x,y),pdd(xx,yy));
		}

		sort(a,a + n,cmp);

		if(n == 0)
			cout << 1 << endl;
		else if(n == 1)
			cout << 2 << endl;
		else
		{
			int solve = 2;

			for(int i = 0; i < n ; i++)
			{
				pair<pdd,pdd> X = a[i];

				pdd p1 = X.first;
				pdd p2 = X.second;

				float q = 0;
				float qq = 0;
				float m = 0;
				float nn = 0;

				if(p1.first == xc)
					q = xc;
				else
				{
					m = (p1.second - yc) / (p1.first - xc);

					nn = yc - m*xc;

					q = (-1.0*nn) / m;
				}

				if(p2.first == xc)
					qq = xc;
				else
				{
					m = (p2.second - yc) / (p2.first - xc);

					nn = yc - m*xc;

					qq = (-1.0*nn)/m;
				}
				if(qq < q)
				    swap(q, qq);
				XX.push_back(pdd(q,qq));
			}
			sort(XX.begin(),XX.end(),comp);

			float pivX = XX[0].first;
			float pivY = XX[0].second;

			for(int i = 1 ; i < n; i ++)
			{
				if(XX[i].first <= pivY)
				{
					pivY = max(XX[i].second,pivY);
				}
				else
				{
					solve++;
					pivX = XX[i].first;
					pivY = XX[i].second;
				}
			}

			cout << solve << endl;

		}
	}
}
/*2
3
50 60
55 45 30 35
64 39 92 18
20 30 40 16
2
-10 50
-10 1 10 11
-10 11 10
*/