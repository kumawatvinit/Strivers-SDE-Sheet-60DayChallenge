#include<bits/stdc++.h>
using namespace std;

long getTrappedWater(long *arr, int n){
    long ans = 0;
    int l=0, r=n-1;
    long hl = 0, hr = 0;

    while(l<r)
    {
        hl = max(hl, arr[l]);
        hr = max(hr, arr[r]);

        if(hl <= hr) {
            ans+= min(hl, hr) - arr[l];
            l+= 1;
        } else {
            ans+= min(hl, hr) - arr[r];
            r-= 1;
        }
    }

    return ans;
}

int main()
{
    long arr[] = {3,0,0,2,0,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<getTrappedWater(arr, n);
    

    return 0;
}