#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    // TC: O(n*2^(n-1))
    /*
        ans.size() - max value = 2^n-1
        outer loop = n
    */
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans(1);
    int size = 0;

    for(int i=0; i<nums.size(); i++)
    {
        int startIdx = i>0? (nums[i]==nums[i-1]? size: 0): 0;

        size = ans.size();

        for(int j=startIdx; j<size; j++)
        {
            vector<int> subset = ans[j];
            subset.push_back(nums[i]);
            ans.push_back(subset);
        }
    }

    return ans;
}


void rec(vector<int>& nums, vector<int>& temp, int idx, vector<vector<int>>& ans)
{
    ans.push_back(temp);

    for(int i=idx; i<nums.size(); i++)
    {
        if(i>idx && nums[i]==nums[i-1]) continue;

        temp.push_back(nums[i]);
        rec(nums, temp, i+1, ans);
        temp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup2(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    vector<int> temp;

    rec(nums, temp, 0, ans);

    return ans;
}

int main()
{
    vector<int> nums = {1,2,2};

    vector<vector<int>> ans = subsetsWithDup(nums);

    for(auto i: ans)
    {
        for(auto j: i) cout<<j<<" ";
        cout<<endl;
    }


    vector<vector<int>> ans2 = subsetsWithDup2(nums);

    for(auto i: ans2)
    {
        for(auto j: i) cout<<j<<" ";
        cout<<endl;
    }


    return 0;
}