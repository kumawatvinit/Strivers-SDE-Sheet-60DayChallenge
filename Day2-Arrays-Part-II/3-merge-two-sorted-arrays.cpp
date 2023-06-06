#include <bits/stdc++.h>
using namespace std;

vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    int i = 0, j = 0, k = 0;
    vector<int> ans;

    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            ans.push_back(arr1[i]);
            ++i;
        }
        else
        {
            ans.push_back(arr2[j]);
            ++j;
        }
    }

    while (i < m)
    {
        ans.push_back(arr1[i]);
        ++i;
    }
    while (j < n)
    {
        ans.push_back(arr2[j]);
        ++j;
    }

    return ans;
}

// no extra space
// in place in nums1
// nums1 has enough space to hold elements of nums2 as well

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1, j = n - 1;
    int idx = m + n - 1;

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[idx] = nums1[i];
            --i;
        }
        else
        {
            nums1[idx] = nums2[j];
            --j;
        }
        --idx;
    }

    while (j >= 0)
    {
        nums1[idx] = nums2[j];
        --idx;
        --j;
    }
}

void print(vector<int> &ans)
{
    cout << "Start: \n";
    
    for(auto &i: ans)
    {
        cout << i << " ";
    }
    cout << "End!\n";
}

int main()
{

    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {0, 2, 6, 8, 9};

    vector<int> ans = ninjaAndSortedArrays(arr1, arr2, arr1.size(), arr2.size());

    print(arr1); 
    print(arr2);
    cout << "----------------\n";
    print(ans);

    return 0;
}