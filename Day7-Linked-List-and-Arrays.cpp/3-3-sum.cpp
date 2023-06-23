#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	vector<vector<int>> ans;
	sort(arr.begin(), arr.end());
	
	for(int i=0; i<arr.size(); i++)
	{
		if(i>0 && arr[i] == arr[i-1]) continue;

		int start = i+1, end = arr.size()-1;
		int tar = K-arr[i];

		// 2 pointers
		while(start < end)
		{
			if(arr[start]+arr[end] == tar) {
				ans.push_back({arr[i], arr[start], arr[end]});

				start+= 1;
				end-= 1;


				while(start<end && arr[start] == arr[start-1]) start+= 1;
				while(start<end && arr[end] == arr[end+1]) end-= 1;
			} 
			else if(arr[start]+arr[end] > tar) {
				end-= 1;
			} else {
				start+= 1;
			}
		}
	}
	
	return ans;
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9,15};

    vector<vector<int>> ans = findTriplets(arr, arr.size(), 18);

    for(auto i: ans)
    {
        for(auto j: i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }   

    return 0;
}