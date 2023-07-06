#include<bits/stdc++.h>
using namespace std;


void rec(vector<int>& arr, int idx, int target, vector<int>& temp, vector<vector<int>>& ans)
{
    if(idx == arr.size())
    {
        if(target == 0) {
            if(temp.size() > 0) ans.push_back(temp);
        }
        return;
    }

    
    temp.push_back(arr[idx]);
    rec(arr, idx+1, target-arr[idx], temp, ans);
    temp.pop_back();

    rec(arr, idx+1, target, temp, ans);
}

void itr(vector<int>& arr, int target, vector<vector<int>>& ans)
{
    for(int i=0; i<(1<<arr.size()); i++)
    {
        vector<int> temp;
        int sum = 0;

        for(int j=0; j<arr.size(); j++)
        {
            if(i&(1<<j)) temp.push_back(arr[j]), sum+= arr[j];
        }

        if(sum == target) ans.push_back(temp);
    }
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    
    vector<vector<int>> ans;
    // vector<int> temp;

    // rec(arr, 0, k, temp, ans);

    itr(arr, k, ans);

    return ans;
}

int main()
{
    vector<int> arr = {10, 5, 2, 3, 6, 8};

    vector<vector<int>> ans = findSubsetsThatSumToK(arr, arr.size(), 8);

    for(auto i: ans)
    {
        for(auto j: i) cout<<j<<" ";
        cout<<endl;
    }

    return 0;
}