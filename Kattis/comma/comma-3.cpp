// Problem name: Comma Sprinkler
// Problem link: https://open.kattis.com/problems/comma
// Submission link: https://open.kattis.com/submissions/3696062

#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;

map<string, int> vertex;
vector<vector<pii>> adj[ 2 ];
vector<pii> start;
vector<bool> checked[ 2 ];

void parse(string s){
    string now = "";
    int v1 = -1, v2 = -1, dif = 0;
    bool comma = 0;
    for(auto c : s){
        if(c == ' ' || c == ',' || c == '.'){
            if(now == ""){
                v1 = -1;
                continue;
            }
            auto it = vertex.find(now);
            if(it == vertex.end()){
                vertex[ now ] = v2 = dif++;
                adj[ 0 ].pb(vector<pii>(0)), checked[ 0 ].pb(0);
                adj[ 1 ].pb(vector<pii>(0)), checked[ 1 ].pb(0);
            }
            else
                v2 = it -> second;
            if(comma)
                start.pb(pii(0, v2));
            if(c == ',')
                start.pb(pii(1, v2));
            comma = (c == ',');
            if(v1 == -1){
                v1 = v2;
                now = "";
                continue;
            }
            adj[ 1 ][ v1 ].pb(pii(0, v2));
            adj[ 0 ][ v2 ].pb(pii(1, v1));
            v1 = (c == '.' ? -1 : v2);
            now = "";
        }
        else
            now += c;
    }
}

void bfs(pii v){
    queue<pii> q;
    for(q.push(v), checked[ v.F ][ v.S ] = 1 ; !q.empty() ; q.pop()){
        v = q.front();
        for(auto x : adj[ v.F ][ v.S ])
            if(!checked[ x.F ][ x.S ])
                checked[ x.F ][ x.S ] = 1, q.push(x);
    }
}

void print(string s){
    string now = "", ans = "";
    int v, dif = 0, foo;
    for(auto c : s){
        if(c == ' ' || c == ',' || c == '.'){
            if(now == ""){
                ans += ' ';
                continue;
            }
            v = vertex[ now ];
            if(c == '.'){
                ans += now + '.';
                now = "";
                continue;
            }
            ans += now + (checked[ 1 ][ v ] ? "," : "") + (c == ' ' ? " " : "");
            now = "";
        }
        else
            now += c;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s;
    getline(cin, s);
    parse(s);
    for(auto x : start)
        bfs(x);
    print(s);
    return 0;
}