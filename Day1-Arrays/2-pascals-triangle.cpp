#include <bits/stdc++.h>
using namespace std;

vector<vector<long long int>> printPascal(int n)
{
    vector<vector<long long int>> ans(n);
    ans[0].push_back(1);

    for (int i = 1; i < n; ++i)
    {
        ans[i].push_back(1);

        for (int j = 1; j < i; ++j)
        {
            ans[i].push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
        }
        ans[i].push_back(1);
    }

    return ans;
}

vector<vector<long long int>> generatePascal(int n)
{
    vector<vector<long long int>> ans(n);

    for(int i=0; i<n; ++i)
    {
        ans[i].resize(i+1);

        ans[i][0] = ans[i][i] = 1;

        for(int j=1; j<i; ++j)
        {
            ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
        }
    }
    return ans;
}

void print(vector<vector<long long int>> &ans)
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

    vector<vector<long long int>> ans = generatePascal(10);
    print(ans);

    return 0;
}