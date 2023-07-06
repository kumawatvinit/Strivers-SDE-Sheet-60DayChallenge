#include<bits/stdc++.h>
using namespace std;


// TC: O(2^n)
// SC: o(n)
void rec(vector<int>& nums, int idx, int sum, vector<int>& ans)
{
	if(idx == nums.size()) return;

	rec(nums, idx+1, sum+nums[idx], ans);
	ans.push_back(sum+nums[idx]);

	rec(nums, idx+1, sum, ans);
}

vector<int> itrBitmask(vector<int>& nums)
{
	// TC: O(n*2^n)
	// SC: O(1)
	vector<int> ans;
	int n = nums.size();

	for(int i=0; i<(1<<n); i++)
	{
		int sum = 0;
		for(int j=0; j<n; j++)
		{
			if(i&(1<<j)) sum+= nums[j];
		}

		ans.push_back(sum);
	}

	sort(ans.begin(), ans.end());

	return ans;
}

vector<int> subsetSum(vector<int> &nums) {
  // vector<int> ans(1);
  // rec(nums, 0, 0, ans);

  // sort(ans.begin(), ans.end());
  // return ans;

  return itrBitmask(nums);
}


int main()
{
    vector<int> nums = {1,2,3};
    vector<int> ans = subsetSum(nums);

    for(auto i: ans) cout<<i<<" ";
    cout<<endl;

    return 0;
}