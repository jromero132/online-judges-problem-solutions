// Problem name: Average Speed
// Problem link: https://codeforces.com/gym/101124/problem/K
// Submission link: https://codeforces.com/gym/101124/submission/21385506

#include<bits/stdc++.h>

#define PB push_back
#define remove erase
#define endl '\n'
#define FOR(IN,N) for(int I = IN;I < N;++I)
#define MAX

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, int> psi;


string a;

vector<string> P;

int convert(string a)
{
	int number = 0;
	int ten = 1;
	for(int i = a.size() - 1; i >= 0 ; i--)
	{
		number += (a[i] - '0')*ten;
		ten *= 10;
	}
	return number;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cout << setprecision(2) << fixed;

	double pos = 0;
	double v = 0;
	double hh = 0;
	double mm = 0;
	double ss = 0;

	while (getline(cin,a))
	{
		double h = 0;
		double m = h;
		double s = 0;
		int c = 0;
		int h1 = 0;
		int m1 = 0;
		int s1 = 0;
		string b = "";
		for(int i = 0 ; i < a.size(); i++)
		{
			if(c == 1)
			{
				b += a[i];
			}
			else if(a[i] == ' '){
				c = 1;
				P.push_back(b);
				int number = convert(b);
				if(h1 == 0){
					h = 1.0*number;
					h1 = 1;
				}
				else if(m1 == 0){
					m = 1.0*number;
					m1 = 1;
				}
				else if(s1 == 0){
					s = 1.0*number;
					s1 = 1;
				}
				b = "";
			}
			else if(a[i] == ':'){
				P.push_back(b);
				int number = convert(b);
				if(h1 == 0){
					h = 1.0*number;
					h1 = 1;
				}
				else if(m1 == 0){
					m = 1.0*number;
					m1 = 1;
				}
				else if(s1 == 0){
					s = 1.0*number;
					s1 = 1;
				}
				b = "";
			}
			else
			{
				b += a[i];
			}
		}



		int speed = -1;

		if(c == 1)
			speed = convert(b);
		else{
			int number = convert(b);
			s = 1.0*number;
			P.push_back(b);
		}

		double dif = 0;

		double hh1 = 60.0*60.0*hh;
		double mm1 = 60.0*mm;
		double ss1 = ss;

		double hhh = 60.0*60.0*h;
		double mmm = 60.0*m;
		double sss = s;

		double t1 = hh1 + mm1 + ss1;
		double t2 = hhh + mmm + sss;

		dif = t2 - t1;

		hh = h;
		ss = s;
		mm = m;

		double diff = dif*1.0;

		if(c == 1){
			pos = pos + diff*v;
			double vv = 1.0*speed;
			v = vv;
			v /= (60.0*60.0);
		}
		else{
			pos = pos + diff*v;
			cout << P[0] << ":" << P[1] << ":"<< P[2] << " "<< pos << " km" << endl;
		}
		P.clear();
	}

}
