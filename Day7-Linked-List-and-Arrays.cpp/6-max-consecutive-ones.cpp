#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    // count ones, maintain maxi
    // when encounter zero, reset count to zero
    int maxi = 0, count=0;

    for(auto &i: nums)
    {
        if(i == 0) {
            maxi=max(maxi,count);
            count = 0;
        }
        else {
            count++;
        }
    }

    maxi=max(maxi,count);

    return maxi;
}

int cnt(vector<int>& nums, int s, int k)
{
    int maxi = 0, count=0;

    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i] == 1) {
            count++;
        }
        else if(nums[i] == 0 && i>=s && k>0) {
            count++;
            k--;
        }
        else {
            maxi=max(maxi,count);
            count = 0;
        }
    }

    maxi=max(maxi,count);
    return maxi;
}


int bruteForce(vector<int> &arr , int n, int k)
{
    int maxi = 0;

    for(int i=0; i<n; i++)
    {
        maxi = max(maxi, cnt(arr, i, k));
    }

    return maxi;
}

int optimized(vector<int> &arr , int n, int k)
{
    int i=0, maxi = 0;

    for(int j=0; j<n; j++)
    {
        if(arr[j] == 0) k--;

        if(k<0) {
            while(arr[i] != 0) i++;

            k++;
            i++;
        }

        maxi = max(maxi, j-i+1);
    }

    return maxi;
}

// longest sequence of continuous 1's after flipping max k 0's
int longestSubSeg(vector<int> &arr , int n, int k){
    // return bruteForce(arr, n, k);
    return optimized(arr, n, k);
}

int main()
{
    vector<int> arr = {1,1,0,1,1,1};

    cout << findMaxConsecutiveOnes(arr) << endl;

    vector<int> arr2 = {1,1,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,0,1,0};
    
    cout << longestSubSeg(arr2, arr2.size(), 2);

    return 0;
}