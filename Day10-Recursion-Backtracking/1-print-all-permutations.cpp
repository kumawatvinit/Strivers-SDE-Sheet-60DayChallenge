#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}

vector<vector<int>> ans;
void rec(vector<int> &nums, int mask, vector<int> &temp)
{
    if (mask == 0)
    {
        ans.push_back(temp);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (mask & (1 << i))
        {
            temp.push_back(nums[i]);
            rec(nums, mask & ~(1 << i), temp);
            temp.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{

    vector<int> temp;
    rec(nums, (1 << nums.size()) - 1, temp);

    return ans;

    // vector<vector<int>> ans(factorial(nums.size()));
    // sort(nums.begin(), nums.end());
    // int idx = 0;

    // do {
    //     ans[idx] = nums;
    //     ++idx;
    // } while(next_permutation(nums.begin(), nums.end()));

    // return ans;
}


// for string
vector<string> ans2;
void rec(string& s, int mask, string& temp)
{
    if(mask == 0) {
        ans2.push_back(temp);
        return;
    }

    for(int i=0; i<s.size(); i++)
    {
        if(mask & (1<<i)) 
        {
            temp+= s[i];
            rec(s, mask&~(1<<i), temp);
            temp.pop_back();
        }
    }
}

vector<string> findPermutations(string &s) {
    string temp = "";
    rec(s, (1<<s.size()) - 1, temp);

    return ans2;
}

int main()
{
    vector<int> nums = {8, 5, 6};
    vector<vector<int>> ans = permute(nums);

    for (auto v : ans)
    {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    cout << endl;

    string s = "abc";
    vector<string> ans2 = findPermutations(s);

    for (auto v : ans2)
    {
        cout << v << endl;
    }

    return 0;
}