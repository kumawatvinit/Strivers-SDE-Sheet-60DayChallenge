#include<bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    long long maxi = 0;
    long long sum = 0;

    for(int i=0; i<n; ++i)
    {
        if(sum < 0) sum = 0;

        sum+= arr[i];
        if(sum > maxi) maxi = sum;
    }
    return maxi;
}

int main()
{
    int arr[] = {1,2,3,-2,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << maxSubarraySum(arr, n) << "\n";

    return 0;
}