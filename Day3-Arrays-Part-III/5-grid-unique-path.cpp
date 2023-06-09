#include <bits/stdc++.h>
using namespace std;

int mem(int idx, int jdx, vector<vector<int>> &dp)
{
    if (idx == 0 && jdx == 0)
        return 1;
    if (idx < 0 || jdx < 0)
        return 0;
    if (dp[idx][jdx] != -1)
        return dp[idx][jdx];

    return dp[idx][jdx] = mem(idx - 1, jdx, dp) + mem(idx, jdx - 1, dp);
}

int tabulation(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n));
    dp[0][0] = 1;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == 0 && j == 0)
                continue;

            int left = i - 1 >= 0 ? dp[i - 1][j] : 0;
            int right = j - 1 >= 0 ? dp[i][j - 1] : 0;

            dp[i][j] = left + right;
        }
    }
    return dp[m - 1][n - 1];
}

int spaceOpt(int m, int n)
{
    vector<int> dp(n, 1);

    for (int i = 1; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int left = dp[j];
            int right = j - 1 >= 0 ? dp[j - 1] : 0;

            dp[j] = left + right;
        }
    }
    return dp[n - 1];
}

int uniquePaths(int m, int n)
{
    // vector<vector<int>> dp(m, vector<int>(n, -1));
    // return mem(m-1,n-1, dp);

    // return tabulation(m,n);
    return spaceOpt(m, n);
}

int main()
{

    cout << uniquePaths(3, 7) << endl;

    return 0;
}