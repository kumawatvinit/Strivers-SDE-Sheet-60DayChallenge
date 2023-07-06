#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 

bool isPalindrome(string& a)
{
    int start = 0, end = a.size()-1;

    while(start < end)
    {
        if(a[start] != a[end]) return false;

        start+= 1;
        end-= 1;
    }

    return true;
}

void rec(string& s, int idx, vector<string>& temp, vector<vector<string>>& ans)
{
    if(idx >= s.size()) {
        if(temp.size() == 0 || isPalindrome(temp[temp.size()-1])) {
            ans.push_back(temp);
        }
        return;
    }

    

    // add in prev string
    if (temp.size() > 0) {
        string prev = temp[temp.size() - 1];
        temp.pop_back();
        
        string neww = prev + s[idx];
        temp.push_back(neww);
        rec(s, idx + 1, temp, ans);

        temp.pop_back();
        temp.push_back(prev);
    }


    // create new
    if(temp.size() > 0) {
        if(!isPalindrome(temp[temp.size() - 1])) return;
    }
    
    string curr = "";
    curr+= s[idx];
    temp.push_back(curr);
    rec(s, idx+1, temp, ans);
    
    temp.pop_back();
}

vector<vector<string>> ans;
vector<vector<bool>> dp;

void solve(string& s, int idx, vector<string>& curr)
{
    if(idx >= s.size()) {
        ans.push_back(curr);
        return;
    }

    for(int end = idx; end < s.size(); end++)
    {
        if(s[idx] == s[end] && (end-idx<=2 || dp[idx+1][end-1]))
        {
            dp[idx][end] = true;

            curr.push_back(s.substr(idx, end-idx+1));
            solve(s, end+1, curr);
            curr.pop_back();
        }

        /*
            if(isPalindrome(s.substr(idx, end-idx+1)))
            {
                curr.push_back(s.substr(idx, end-idx+1));
                solve(s, end+1, curr);
                curr.pop_back();
            }
        */
    }
}


vector<vector<string>> partition(string &s) 
{
    // vector<vector<string>> ans;
    // vector<string> temp;
    // rec(s, 0, temp, ans);

    dp.resize(s.size(), vector<bool>(s.size(), false));
    vector<string> curr;
    solve(s, 0, curr);
    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string s = "aab";
    vector<vector<string>> ans = partition(s);

    for(auto v: ans)
    {
        for(auto s: v) cout<<s<<" ";
        cout<<endl;
    }

    return 0;
}