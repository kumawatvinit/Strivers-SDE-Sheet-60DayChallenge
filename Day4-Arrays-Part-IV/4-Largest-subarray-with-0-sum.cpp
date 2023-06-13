#include <bits/stdc++.h>
using namespace std;

int LongestSubsetWithZeroSum(vector<int> arr)
{

    int maxi = 0, n = arr.size();
    unordered_map<int, int> mp;
    int sum = 0;
    mp[0] = -1;

    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];

        if (mp.find(sum) != mp.end())
        {
            maxi = max(maxi, i - mp[sum]);
        }
        else
        {
            mp[sum] = i;
        }
    }

    return maxi;
}

int main()
{
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    cout << LongestSubsetWithZeroSum(arr) << endl;

    return 0;
}