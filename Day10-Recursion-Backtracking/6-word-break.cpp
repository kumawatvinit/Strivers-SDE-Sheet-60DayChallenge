#include <bits/stdc++.h>
using namespace std;

void solve(int idx, string &s, string temp, unordered_map<string, bool> &dict, vector<string> &ans)
{
    if (idx >= s.size())
    {
        temp.pop_back();
        ans.push_back(temp);
        return;
    }

    for (int count = 1; count <= s.size() - idx; count++)
    {
        string word = s.substr(idx, count);

        if (dict.find(word) != dict.end())
        {
            solve(idx + count, s, temp + word + " ", dict, ans);
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string> ans;
    unordered_map<string, bool> dict;

    string temp = "";

    for (auto word : dictionary)
    {
        dict[word] = 1;
    }

    solve(0, s, temp, dict, ans);
    return ans;
}

int main()
{
    string s = "godisnowherenowhere";
    vector<string> dictionary = {"god", "is", "now", "no", "where", "here"};

    vector<string> ans = wordBreak(s, dictionary);

    for (auto word : ans)
    {
        cout << word << endl;
    }

    return 0;
}