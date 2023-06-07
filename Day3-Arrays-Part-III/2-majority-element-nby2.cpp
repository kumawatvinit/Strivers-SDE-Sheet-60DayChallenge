#include <bits/stdc++.h>
using namespace std;

// if an element occurs more than n/2 times in an array of size n, then it is called majority element

// Moore's Voting Algorithm
// O(n) time, O(1) space
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
    
    cout << majorityElement(nums) << endl;
    cout << majorityElement2(nums2) << endl;

    return 0;
}