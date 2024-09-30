// Problem name: B - Teclado roto
// Problem link: https://matcomgrader.com/problem/236/teclado-roto/
// Submission link: https://matcomgrader.com/submission/117605/

#include <iostream>
#include <stack>

#define endl '\n'

using namespace std;

string s;
stack<string> word;

string solve(){
    string aux = "", text = "";
    for(int i = 0 ; s[ i ] != '\0' ; i++){
        if(s[ i ] != '[' && s[ i ] != ']')
            aux += s[ i ];
        else if(s[ i ] == '[')
            word.push(aux), aux = "";
        else if(!word.empty())
                aux += word.top(), word.pop();
    }
    text += aux;
    while(!word.empty())
        text += word.top(), word.pop();
    return text;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin >> s)
        cout << solve() << endl;
}