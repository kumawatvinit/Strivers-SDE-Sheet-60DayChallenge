#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &arr, int target)
{
    int m = arr.size(), n = arr[0].size();

    int start = 0, end = m * n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int row = mid / n, col = mid % n;

        if (arr[row][col] == target)
        {
            return true;
        }
        else if (arr[row][col] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> arr = {{1, 3, 5, 7},
                               {10, 11, 16, 20},
                               {23, 30, 34, 60}};
    
    cout << searchMatrix(arr, 3) << endl;
    cout << searchMatrix(arr, 10) << endl;
    cout << searchMatrix(arr, 60) << endl;
    cout << searchMatrix(arr, 1) << endl;
    cout << searchMatrix(arr, 21) << endl;
    cout << searchMatrix(arr, -1) << endl;

    return 0;
}