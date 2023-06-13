#include<bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int> &arr, int k)
{
    int n = arr.size();
    int count = 0;
    unordered_map<int, int> mp;
    int xorSum = 0;
    for (int i = 0; i < n; i++)
    {
        xorSum = xorSum ^ arr[i];

        // if whole subarray from starting is equal to k
        if (xorSum == k)
            count++;
        if (mp.find(xorSum ^ k) != mp.end())
            count += mp[xorSum ^ k];
        mp[xorSum]++;
    }
    return count;
}

int subarraysXor(vector<int> &arr, int x)
{
    // TC: O(n) | SC: O(n)
    unordered_map<int,int> hash;

    int xorr = 0, ans = 0, n = arr.size();

    // if xor of whole array is equal to x
    hash[0] = 1;
    for(int i=0; i<n; ++i)
    {
        xorr^= arr[i];

        if(hash.find(xorr^x) != hash.end()) {
            ans+= hash[xorr^x];
        }
        hash[xorr]++;
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    cout << countSubarrays(arr, k) << endl;
    cout << subarraysXor(arr, k) << endl;

    return 0;
}