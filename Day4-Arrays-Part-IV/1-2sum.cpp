#include <bits/stdc++.h>
using namespace std;

// returns all pairs of numbers which sum to s
vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    vector<vector<int>> ans;

    unordered_map<int, int> hash;

    for (int i : arr)
    {
        if (hash.find(s - i) != hash.end())
        {
            int times = hash[s - i];
            int first = min(i, s - i), second = max(i, s - i);
            while (times--)
                ans.push_back({first, second});
        }
        hash[i]++;
    }
    sort(ans.begin(), ans.end());
    return ans;
}

// returns indices of the two numbers such that they add up to target.
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> hash;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (hash.find(target - nums[i]) != hash.end())
        {
            return {hash[target - nums[i]], i};
        }
        hash[nums[i]] = i;
    }

    return {};
}

int main()
{
    vector<int> arr = {10, 5, 2, 3, -6, 9, 11};
    int s = 4;
    vector<vector<int>> ans = pairSum(arr, s);
    if (ans.size() == 0)
        cout << "No such pair";
    else
    {
        for (auto i : ans)
            cout << i[0] << ", " << i[1] << endl;
    }

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = twoSum(nums, target);
    for (int i : res)
        cout << i << " ";
    cout << endl;

    return 0;
}