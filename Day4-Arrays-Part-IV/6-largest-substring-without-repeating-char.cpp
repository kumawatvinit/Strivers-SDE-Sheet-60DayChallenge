#include<bits/stdc++.h>
using namespace std;

// if input contains only lowercase alphabets
int uniqueSubstrings(string input)
{
    int start = -1, n = input.size(), itr = 0;
    vector<int> lastLoc(26, -1);
    int maxi = 0;

    for( ; itr<n; ++itr)
    {
        if(lastLoc[input[itr]-'a'] > start)
        {
            maxi = max(maxi, itr-start-1);
            start = lastLoc[input[itr]-'a'];
        }

        lastLoc[input[itr]-'a'] = itr;
    }
    maxi = max(maxi, itr-start-1);
    return maxi;
}

// it can contain any character
int lengthOfLongestSubstring(string input) {
    int start = -1, n = input.size(), itr = 0;
    vector<int> lastLoc(128, -1);
    int maxi = 0;

    for( ; itr<n; ++itr)
    {
        if(lastLoc[input[itr]] > start)
        {
            maxi = max(maxi, itr-start-1);
            start = lastLoc[input[itr]];
        }

        lastLoc[input[itr]] = itr;
    }
    maxi = max(maxi, itr-start-1);
    return maxi;
}

int main()
{
    string input = "abcabcbb";
    // string input = "pwwkew";
    // string input = "bbbbb";
    cout << lengthOfLongestSubstring(input) << endl;
    cout << uniqueSubstrings(input) << endl;

    return 0;
}