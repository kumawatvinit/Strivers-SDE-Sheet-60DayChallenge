#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{

    int i = nums.size() - 1;

    // find last increased point
    for (; i > 0; --i)
    {
        if (nums[i - 1] < nums[i])
            break;
    }

    // if sorted in decreasing order => next permm. => reversed
    if (i == 0)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    int idx = i, j = i;

    // find just greater element of nums[i-1]
    for (; j < nums.size(); ++j)
    {
        if (nums[j] > nums[i - 1])
            idx = j;
        else
            break;
    }
    swap(nums[i - 1], nums[idx]);

    // to get just next permu.
    // => get the min. of the last part of the sequence
    //  => sort !!BUT that is already in decreasing order!!
    //  => reverse it ;)
    reverse(nums.begin() + i, nums.end());
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
    vector<int> nums{3,4,6,9,8,7,1};
    print(nums);
    nextPermutation(nums);
    print(nums);

    return 0;
}