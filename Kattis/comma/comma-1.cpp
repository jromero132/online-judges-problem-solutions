// Problem name: Comma Sprinkler
// Problem link: https://open.kattis.com/problems/comma
// Submission link: https://open.kattis.com/submissions/3691053

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef pair<string,int> psi;

string s,temp,temp1;
map<string,int> m;
vector<int> graph[1000005];
bool visited[1000005];
vector<int> init;

void DFS_Visit(int u)
{
    visited[u] = true;
    for(int i = 0;i < graph[u].size();i++)
    {
        int v = graph[u][i];
        if(!visited[v])
        {
            DFS_Visit(v);
        }
    }
}

void DFS(int v)
{
    if(!visited[v])
        DFS_Visit(v);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    getline(cin,s);

    int diferent_words = 0;
    bool comma_begin = false;
    for(int i = 0 ;i < s.length();i++)
    {
        if(s[i] != ',' && s[i] != '.' && s[i] != ' ')
            temp += s[i];
        else if(temp.length() > 0)
        {
            psi p = make_pair(temp,diferent_words);
            if(m.find(temp) == m.end())
            {
                m.insert(p);
                diferent_words++;
            }
            temp = "";
        }
    }

    temp = "";
    char befor = ' ';
    for(int i = 0 ;i < s.length();i++)
    {
        if(s[i] != ',' && s[i] != '.' && s[i] != ' ')
            temp += s[i];
        else if(temp.length() > 0)
        {
            if(temp1.length() > 0 && (befor != '.' && befor != ','))
            {
                graph[m[temp1] + diferent_words].push_back(m[temp]);
                graph[m[temp]].push_back(m[temp1] + diferent_words);
            }
            if(comma_begin)
            {
                init.push_back(m[temp]);
                comma_begin = false;
            }
            if(s[i] == ',')
            {
                init.push_back(m[temp] + diferent_words);
                comma_begin = true;
            }
            befor = s[i];
            temp1 = temp;
            temp = "";
        }
    }

    for(int i = 0;i < init.size();i++)
        DFS(init[i]);

    string result = "";
    temp = "";
    for(int i = 0;i < s.length();i++)
    {
        if(s[i] != ',' && s[i] != '.' && s[i] != ' ')
            temp += s[i];
        else if(i > 0 && (s[i-1] == ',' || s[i-1] == '.'))
        {
            result += s[i];
            temp = "";
        }
        else if(s[i] == ' ')
        {
            result += temp;
            if(visited[m[temp] + diferent_words])
                result += ", ";
            else
                result += ' ';
            temp = "";
        }
        else
        {
            result += temp;
            temp = "";
            result += s[i];
        }
    }
    cout << result << endl;

    return 0;
}