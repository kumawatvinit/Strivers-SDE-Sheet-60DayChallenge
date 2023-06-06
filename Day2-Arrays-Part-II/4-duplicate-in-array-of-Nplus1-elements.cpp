#include <bits/stdc++.h>
using namespace std;

// requires modification of array, but we can restore it later
// O(n) time, O(1) space
int findDuplicate(vector<int> &nums)
{
    int ans = -1;
    for (int i = 0; i < nums.size(); ++i)
    {
        int idx = abs(nums[i]);

        if (nums[idx] < 0)
        {
            ans = idx;
            break;
        }

        nums[idx] = -nums[idx];
    }

    for (int i = 0; i < nums.size(); ++i)
    {
        nums[i] = abs(nums[i]);
    }

    return ans;
}

// no modification of array
// O(n) time, O(1) space
int findDuplicate(vector<int> &nums, int n)
{
    int slow = nums[0], fast = nums[0];

    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    fast = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

void print(vector<int> &ans)
{
    cout << "Start: \n";
    
    for(auto &i: ans)
    {
        cout << i << " ";
    }
    cout << "\nEnd!\n";
}

int main()
{
    vector<int> nums = {1, 3, 4, 2, 2};

    print(nums);

    cout << findDuplicate(nums) << endl;
    cout << findDuplicate(nums, nums.size()) << endl;

    return 0;
}