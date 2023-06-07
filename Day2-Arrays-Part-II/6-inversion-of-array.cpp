#include<bits/stdc++.h>
using namespace std;

long long merge(long long* arr, int start, int mid, int end)
{
    int size = end-start+1;
    vector<long long> v(size);
    int itr = 0;
    int i=start, j=mid+1;
    long long count = 0;

    while(i<=mid && j<=end)
    {
        if(arr[i] <= arr[j])
        {
            v[itr] = arr[i];
            ++i;
        }
        else
        {
            v[itr] = arr[j];
            ++j;
            count+= mid-i+1;
        }
        ++itr;
    }

    while(i<=mid) {
        v[itr] = arr[i];
        ++itr; ++i;
    }
    
    while(j<=end) {
        v[itr] = arr[j];
        ++itr; ++j;
    }

    itr = 0;
    for( ; itr<size; ++itr)
    {
        arr[start+itr] = v[itr];
    }

    return count;
}

long long helper(long long* arr, int start, int end)
{
    if(start >= end) return 0;

    int mid = (start+end)/2;

    long long count = helper(arr, start, mid);
    count+= helper(arr, mid+1, end);

    count+= merge(arr, start, mid, end);
    return count;
}

long long getInversions(long long *arr, int n){
    return helper(arr,0,n-1);
}

int main()
{

    vector<long long> v{2,5,1,3,4};
    int n = v.size();

    long long *arr = new long long[n];
    for(int i=0; i<n; ++i) arr[i] = v[i];

    cout << getInversions(arr, n) << endl;

    return 0;
}