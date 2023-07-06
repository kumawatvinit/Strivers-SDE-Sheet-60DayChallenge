#include<bits/stdc++.h>
using namespace std;


void rec(vector<int>& arr, int idx, int target, vector<int>& temp, vector<vector<int>>& ans)
{
	if(target == 0) {
		ans.push_back(temp);
		return;
	}

	for(int i=idx; i<arr.size(); i++)
	{
		if(i>idx && arr[i] == arr[i-1]) continue;

		if(arr[i] <= target) {
			temp.push_back(arr[i]);
			rec(arr, i+1, target-arr[i], temp, ans);
			temp.pop_back();
		} else return;
	}
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	sort(arr.begin(), arr.end());

	vector<int> temp;
	vector<vector<int>> ans;

	rec(arr, 0, target, temp, ans);
	return ans;
}


void helper(vector<int>& nums, int target, int indx, vector<int> &temp,vector<vector<int>>&ans)
    {
        if(indx == nums.size())
        {
            if(target == 0) 
            {
                if(temp.size()>0) ans.push_back(temp);
            }
            return;
        }

        // liya
        if(nums[indx] <= target)
        {
            temp.push_back(nums[indx]);
            helper(nums,target-nums[indx],indx+1,temp,ans);

            temp.pop_back();
        }

        // nhi liya
        while(indx+1 < nums.size() && nums[indx] == nums[indx+1]) {
            indx++;
        }
        helper(nums,target,indx+1,temp,ans);
    }

    vector<vector<int>> leet_combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());

        helper(candidates,target,0,temp,ans);
        return ans;
    }


int main()
{
    vector<int> arr = {10, 5, 2, 3, 6, 8};

    vector<vector<int>> ans = combinationSum2(arr, arr.size(), 8);

    for(auto v: ans) {
    	for(auto i: v) cout << i << " ";
    	cout << endl;
    }

    vector<vector<int>> ans2 = leet_combinationSum2(arr, 8);

    for(auto v: ans2) {
    	for(auto i: v) cout << i << " ";
    	cout << endl;
    }

    return 0;
}