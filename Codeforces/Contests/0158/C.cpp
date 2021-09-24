// Problem name: Cd and pwd commands
// Problem link: https://codeforces.com/contest/158/problem/C
// Submission link: https://codeforces.com/contest/158/submission/20929489

#include <iostream>
#include <vector>

#define pb(n) push_back(n)
#define endl '\n'

using namespace std;

int p = 0;
string s;
vector<string> dir;

void print(){
    if(!p){
        cout << "/" << endl;
        return;
    }
    for(int i = 0 ; i < p ; i++)
        cout << "/" << dir[ i ];
    cout << "/" << endl;
}

void change(){
    int i = 0;
    if(s[ 0 ] == '/')
        p = 0, i++;
    string ss = "";
    for( ; s[ i ] != '\0' ; i++){
        if(s[ i ] != '/')
            ss += s[ i ];
        else{
            if(ss == "..")
                p--;
            else if(p < dir.size())
                dir[ p++ ] = ss;
            else
                dir.pb(ss), p++;
            ss = "";
        }
    }
    if(ss != ""){
        if(ss == "..")
            p--;
        else if(p < dir.size())
            dir[ p++ ] = ss;
        else
            dir.pb(ss), p++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    for(cin >> n ; n ; n--){
        cin >> s;
        if(s == "pwd")
            print();
        else{
            cin >> s;
            change();
        }
    }
    return 0;
}