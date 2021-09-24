// Problem name: Funny Substrings
// Problem link: https://codeforces.com/contest/1538/problem/E
// Submission link: https://codeforces.com/contest/1538/submission/121060738

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct data{
    bool split;
    string begin, end;
    ll count;
};

const string S = "haha";

int matches(string s1, string s2){
    int ans = 0;
    for(int i = 0 ; i + s2.length() <= s1.length() ; ++i){
        bool match = 1;
        for(int j = 0 ; j < s2.length() ; ++j){
            if(s1[ i + j ] != s2[ j ]){
                match = 0;
                break;
            }
        }
        if(match)
            ++ans;
    }
    return ans;
}

void assign_expression(map<string, data> &vars, string var1, string var2){
    data d = { 0, "", "", matches(var2, S) };

    if(var2.length() < 3)
        d.begin = var2;
    else{
        d.split = 1;
        d.begin = var2.substr(0, S.length() - 1);
        d.end = var2.substr(var2.length() - (S.length() - 1));
    }

    vars[ var1 ] = d;
}

void concatenate_expression(map<string, data> &vars, string var1, string var2, string var3){
    data d2 = vars[ var2 ], d3 = vars[ var3 ];
    data d = { 0, "", "", d2.count + d3.count };
    
    if(d2.split && d3.split){
        d.split = 1;
        d.begin = d2.begin;
        d.end = d3.end;
        d.count += matches(d2.end + d3.begin, S);
    }
    else if(d2.split){
        d.split = 1;
        d.begin = d2.begin;
        d.end = d2.end.substr(d2.end.length() - d3.begin.length()) + d3.begin;
        d.count += matches(d2.end + d3.begin, S);
    }
    else if(d3.split){
        d.split = 1;
        d.begin = d2.begin + d3.begin.substr(S.length() - 1 - d2.begin.length());
        d.end = d3.end;
        d.count += matches(d2.begin + d3.begin, S);
    }
    else{
        string s = d2.begin + d3.begin;
        assign_expression(vars, var1, s);
        return;
    }
    
    vars[ var1 ] = d;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    for(cin >> t ; t-- ; ){
        int n;
        map<string, data> vars;
        string var1, exp_t, var2, var3;
        for(cin >> n ; n-- ; ){
            cin >> var1 >> exp_t >> var2;
            if(exp_t == ":=")
                assign_expression(vars, var1, var2);
            else
                cin >> var3 >> var3, concatenate_expression(vars, var1, var2, var3);
        }
        cout << vars[ var1 ].count << endl;
    }
    return 0;
}