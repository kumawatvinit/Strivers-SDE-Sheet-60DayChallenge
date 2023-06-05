#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &arr)
{
    int one = 0, two = arr.size() - 1;

    for (int itr = 0; itr <= two; ++itr)
    {
        if (arr[itr] == 0)
        {
            swap(arr[itr], arr[one++]);
        }
        else if (arr[itr] == 2)
        {
            swap(arr[itr--], arr[two--]);
        }
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
    vector<int> arr{2,0,2,1,1,0};
    print(arr);
    sortColors(arr);
    print(arr);

    return 0;
}