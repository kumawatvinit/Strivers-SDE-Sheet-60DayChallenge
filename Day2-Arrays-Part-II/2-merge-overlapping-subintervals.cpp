#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    ans.push_back(arr[0]);
    int j=0;

    for(int i=1; i<arr.size(); ++i)
    {
        if(arr[i][0] <= ans[j][1])
        {
            ans[j][1] = max(ans[j][1], arr[i][1]);
        }
        else
        {
            ans.push_back(arr[i]);
            ++j;
        }
    }
    return ans;
}

void print(vector<vector<int>> &ans)
{
    cout << "Start: \n";
    
    for(auto &i: ans)
    {
        for(auto &j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << "End!\n";
}

int main()
{
    vector<vector<int>> arr{{1,3},{2,6},{8,10},{15,18},{5,8}};
    print(arr);
    cout << "----------------\n";
    vector<vector<int>> ans = mergeIntervals(arr);
    print(ans);


    return 0;
}