// Problem name: Digital Friends
// Problem link: https://codeforces.com/gym/101104/problem/D
// Submission link: https://codeforces.com/gym/101104/submission/20968837


#include<bits/stdc++.h>

#define PB push_back
#define remove erase
#define endl '\n'
#define FOR(in,n) for(int i = in;i < n;i++)
#define MAX

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;
typedef pair<int, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;

int f1[15];
int f2[15];

bool OK1(string a,string b)
{



	for(int i = 0 ; i < 10 ; i ++)
		if( (f1[i] == 0 || f2[i] == 0) && (f1[i] != f2[i]) )return false;

	return true;
}

bool OK2(string a,string b)
{


	for(int i = 1 ; i  < a.size(); i++)
	{
		int p1 = a[i - 1] - '0';
		int p2 = a[i] - '0';

		if(p1 >= 1 && p2 < 9)
		{
			if(i == 1)
			{
				if(p1 > 1)
				{
					f1[p1]--;
					f1[p2]--;
					f1[p1 - 1]++;
					f1[p2 + 1]++;
					if(OK1(a,b))return true;
					f1[p1]++;
					f1[p2]++;
					f1[p1 - 1]--;
					f1[p2 + 1]--;
				}
			}
			else
			{
				f1[p1]--;
				f1[p2]--;
				f1[p1 - 1]++;
				f1[p2 + 1]++;
				if(OK1(a,b))return true;
				f1[p1]++;
				f1[p2]++;
				f1[p1 - 1]--;
				f1[p2 + 1]--;
			}

		}
		if(p2 >= 1 && p1 < 9)
		{
			if(i == 1)
			{
				if(p1 > 1)
				{
					f1[p2]--;
					f1[p1]--;
					f1[p2 - 1]++;
					f1[p1 + 1]++;
					if(OK1(a,b))return true;
					f1[p2]++;
					f1[p1]++;
					f1[p2 - 1]--;
					f1[p1 + 1]--;
				}
			}
			else
			{
				f1[p2]--;
				f1[p1]--;
				f1[p2 - 1]++;
				f1[p1 + 1]++;
				if(OK1(a,b))return true;
				f1[p2]++;
				f1[p1]++;
				f1[p2 - 1]--;
				f1[p1 + 1]--;
			}
		}

	}


	for(int i = 1 ; i  < b.size(); i++)
	{
		int p1 = b[i - 1] - '0';
		int p2 = b[i] - '0';

		if(p1 >= 1 && p2 < 9)
		{
			if(i == 1)
			{
				if(p1 > 1)
				{
					f2[p1]--;
					f2[p2]--;
					f2[p1 - 1]++;
					f2[p2 + 1]++;
					if(OK1(a,b))return true;
					f2[p1]++;
					f2[p2]++;
					f2[p1 - 1]--;
					f2[p2 + 1]--;
				}
			}
			else
			{
				f2[p1]--;
				f2[p2]--;
				f2[p1 - 1]++;
				f2[p2 + 1]++;
				if(OK1(a,b))return true;
				f2[p1]++;
				f2[p2]++;
				f2[p1 - 1]--;
				f2[p2 + 1]--;
			}

		}
		if(p2 >= 1 && p1 < 9)
		{
			if(i == 1)
			{
				if(p2 > 1)
				{
					f2[p2]--;
					f2[p1]--;
					f2[p2 - 1]++;
					f2[p1 + 1]++;
					if(OK1(a,b))return true;
					f2[p2]++;
					f2[p1]++;
					f2[p2 - 1]--;
					f2[p1 + 1]--;
				}
			}
			else
			{
				f2[p2]--;
				f2[p1]--;
				f2[p2 - 1]++;
				f2[p1 + 1]++;
				if(OK1(a,b))return true;
				f2[p2]++;
				f2[p1]++;
				f2[p2 - 1]--;
				f2[p1 + 1]--;
			}
		}

	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;

	while (n--)
	{
		string a,b;
		cin >> a >> b;

		memset(f1,0,sizeof(f1));
		memset(f2,0,sizeof(f2));

		for(int i = 0 ; i < a.size(); i++)
		f1[a[i] - '0']++;

		for(int j = 0 ; j < b.size(); j++)
			f2[b[j] - '0']++;

		if(OK1(a,b))cout << "friends" << endl;
		else if(OK2(a,b))
			cout << "almost friends" << endl;
		else cout << "nothing" << endl;

	}


}