#include <bits/stdc++.h>
using namespace std;

pair<int,int> missingAndRepeating_const(const vector<int> &arr, int n)
{
	int xorr = 0;

	for(int i: arr) xorr^= i;
	for(int i=1; i<=n; ++i) xorr^= i;

	int set_bit_idx = xorr&~(xorr-1);

	int x=0,y=0;
	for(int i=1; i<=n; ++i) 
	{
		if(i&set_bit_idx) x^= i;
		else y^= i;
	}

	for(int i: arr) 
	{
		if(i&set_bit_idx) x^= i;
		else y^= i;
	}

	for(int i: arr) 
	{
		if(i==x) return {y,x};
		else if(i==y) return {x,y};
	}
}

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int repeat;
	for(int i=0; i<n; ++i)
	{
		int idx = abs(arr[i]);

		if(arr[idx-1] < 0) {
			repeat = idx;
			break;
		}

		arr[idx-1]*= -1;
	}

	for(int i=0; i<n; ++i) arr[i] = abs(arr[i]);

	long long sum = 0;
	for(int i: arr) sum+= i;

	// sum-repeat+missing = n*(n+1)/2;

	sum-= (1ll*n*(n+1)/2);
	int missing = repeat-sum;

	return {missing,repeat};	
}

int main()
{
    vector<int> arr = { 7, 3, 4, 5, 5, 6, 2 };
    int n = arr.size();

    pair<int,int> ans = missingAndRepeating(arr, n);
    cout << "Missing: " << ans.first << ", Repeating: " << ans.second << endl;
    pair<int,int> ans2 = missingAndRepeating_const(arr, n);
    cout << "Missing: " << ans2.first << ", Repeating: " << ans2.second << endl;
    

    return 0;
}