// Problem name: DNA Analysis
// Problem link: https://vjudge.net/problem/Gym-100324D
// Submission link: https://vjudge.net/solution/13138159

#include <bits/stdc++.h>

#define MAX ((int)2500)
#define pb push_back
#define all(x) x.begin(), x.end()
#define POPCOUNT __builtin_popcount
#define endl '\n'

using namespace std;

vector<string> word;
bool match = 0;

void doit(string s, int c, bool check){
    if(!c){
        if(!check)
            word.pb(s);
        else
            match = match || ((*lower_bound(all(word), s)) == s);
        return;
    }
    string now;
    for(int i = 0 ; s[ i ] ; i++){
        for(int j = i ; s[ j ] ; j++){
            now = s;
            reverse(now.begin() + i, now.begin() + j + 1);
            doit(now, c - 1, check);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("dna.in", "r", stdin);
    freopen("dna.out", "w", stdout);
    string s1, s2;
    cin >> s1 >> s2;
    doit(s1, 2, 0);
    sort(all(word));//cout<<endl<<endl;
    doit(s2, 2, 1);
    cout << (match ? "Similar" : "Different") << endl;
    return 0;
}