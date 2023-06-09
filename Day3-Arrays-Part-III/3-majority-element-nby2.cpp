#include <bits/stdc++.h>
using namespace std;

// if an element occurs more than n/2 times in an array of size n, then it is called majority element

// Moore's Voting Algorithm
// O(n) time, O(1) space
int majorityEle(vector<int>& nums)
{
    int cnt = 0, candidate = -1;

    for(int i:nums)
    {
        if(candidate == i) cnt++;
        else if(cnt == 0) candidate = i, cnt = 1;
        else cnt--;
    }

    for(int i:nums)
    {
        if(i == candidate) cnt++;
    }

    if(cnt > nums.size()/2) return candidate;
    return -1;
}

int majorityElement(vector<int> &nums)
{
    int cnt = 1, maxi = nums[0];

    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] == maxi)
        {
            cnt++;
        }
        else
        {
            cnt--;

            if (cnt == 0)
            {
                maxi = nums[i];
                cnt = 1;
            }
        }
    }

    return maxi;
}

// if not confirm that majority element exists
// O(n) time, O(1) space
int majorityElement2(vector<int> &nums)
{
    int cnt = 1, maxi = nums[0];

    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] == maxi)
        {
            cnt++;
        }
        else
        {
            cnt--;

            if (cnt == 0)
            {
                maxi = nums[i];
                cnt = 1;
            }
        }
    }

    cnt = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] == maxi)
        {
            cnt++;
        }
    }

    if (cnt > nums.size() / 2)
        return maxi;
    return -1;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 5, 5, 5, 5};
    vector<int> nums2 = {1, 2, 3, 4, 19, 12, 5, 3, 1};
    
    cout << majorityEle(nums) << endl;
    cout << majorityEle(nums2) << endl;
    cout << majorityElement(nums) << endl;
    cout << majorityElement2(nums2) << endl;

    return 0;
}