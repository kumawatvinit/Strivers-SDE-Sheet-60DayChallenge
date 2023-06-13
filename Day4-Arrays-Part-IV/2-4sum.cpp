#include<bits/stdc++.h>
using namespace std;

// return all pairs
// TC: O(n^3) | SC: O(1)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();
    for(int i=0; i<n; ++i)
    {
        // avoid duplicates
        if(i>0 && nums[i] == nums[i-1]) continue;
        for(int j=i+1; j<n; ++j)
        {
            // avoid duplicates
            if(j>i+1 && nums[j] == nums[j-1]) continue;
            int k = j+1, l = n-1;
            
            while(k<l)
            {
                long long sum = 1ll*nums[i] + nums[j]+nums[k]+nums[l];
                if(sum == target) {
                    ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                    ++k; --l;
                    // skip duplicates
                    while(k<l && nums[k] == nums[k-1]) ++k;
                    while(k<l && nums[l] == nums[l+1]) --l;
                }
                else if(sum < target) ++k;
                else --l;
            }                
        }
    }

    return ans;
}

// TC: O(n^2) | SC: O(n^2)
bool commonIdx(const pair<int,int> a, const pair<int,int> b)
{
    return (a.first==b.first||a.first==b.second||a.second==b.first||a.second==b.second);
}

string fourSumOpt(vector<int> nums, int target, int n) {
    sort(nums.begin(), nums.end());

    map<int, pair<int,int>> mp;
    for(int i=0; i<n; ++i)
    {
        for(int j=i+1; j<n; ++j) {
            mp[nums[i]+nums[j]] = {i,j};
        }
    }
    
    for(int i=0; i<n; ++i)
    {
        for(int j=i+1; j<n; ++j)
        {
            int req = target - nums[i] - nums[j];

            if(mp.find(req) != mp.end() && !commonIdx(mp[req],{i,j})) {
                return "Yes";
            }               
        }
    }
    return "No";
}

int main()
{
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> ans = fourSum(nums, target);
    for(auto v: ans)
    {
        for(auto x: v) cout << x << " ";
        cout << endl;
    }

    cout << fourSumOpt(nums, target, nums.size()) << endl;

    return 0;
}