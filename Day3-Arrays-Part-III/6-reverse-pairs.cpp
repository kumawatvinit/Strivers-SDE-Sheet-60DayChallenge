#include<bits/stdc++.h>
using namespace std;

class Solution {
    int mergeSort(vector<int>& nums, int start, int end, vector<int>& temp)
    {
        if(start >= end) return 0;

        int mid = (start+end)/2;
        int count = 0;

        count = mergeSort(nums, start, mid, temp);
        count+= mergeSort(nums, mid+1, end, temp);

        // merge
        int i=start, j = mid+1;
        int idx = start;

        // O(n)
        for(; i<=mid; ++i)
        {
            for(; j<=end && nums[i] > 2ll*nums[j]; ++j) { }
            count+= j-(mid+1);
        }

        i=start; j = mid+1;
        while(i<=mid && j<=end)
        {
            if(nums[i] <= nums[j]) {
                temp[idx++] = nums[i++];
            }
            else 
            {
                temp[idx++] = nums[j++];
            }
        }
        while(i<=mid) {
            temp[idx++] = nums[i++];
        }
        while(j<=end) {
            temp[idx++] = nums[j++];
        }
        
        for(i=start; i<=end; ++i)
        {
            nums[i] = temp[i];
        }
        return count;
    }
public:
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums);
        int ans = mergeSort(nums,0,nums.size()-1, temp);

        // for(int i: nums) cout << i << " ";
        // cout << "\n" << ans << endl;
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {2,4,3,5,1};
    cout << obj.reversePairs(nums) << endl;

    return 0;
}