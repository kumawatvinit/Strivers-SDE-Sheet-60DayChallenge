#include <bits/stdc++.h>
using namespace std;

// Longest Consecutive Sequence
// TC: O(N) | SC: O(N)
int longestConsecutive(vector<int> &nums)
{
    if (nums.size() < 1)
        return 0;
    set<int> hash;

    for (int i : nums)
        hash.insert(i);

    int maxi = 1;
    for (int i : nums)
    {
        if (!hash.count(i - 1))
        {
            int cnt = 1;
            int itr = i;

            while (hash.count(itr + 1))
            {
                itr++;
                cnt++;
            }

            maxi = max(maxi, cnt);
        }
    }
    return maxi;
}

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums) << endl;

    return 0;
}