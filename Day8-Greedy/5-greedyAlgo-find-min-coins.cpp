#include <bits/stdc++.h>
using namespace std;

int findMinimumCoins(int amount)
{
    vector<int> coins{1, 2, 5, 10, 20, 50, 100, 500, 1000};

    int minCoins = 0;
    int idx = 8;
    while (coins[idx] > amount)
        idx -= 1;

    for (; amount > 0; idx -= 1)
    {
        minCoins += amount / coins[idx];
        amount -= coins[idx] * (amount / coins[idx]);
    }

    return minCoins;
}

// if not possible to make the amount with given coins, return -1
vector<vector<int>> dp;

int rec(int coins[], int V, int idx)
{
    if (V == 0)
        return 0;
    if (idx == 0)
    {
        if (V % coins[idx] == 0)
            return V / coins[idx];
        return 1e9;
    }

    if (dp[V][idx] != -1)
        return dp[V][idx];

    int left = rec(coins, V, idx - 1);
    int right = 1e9;

    if (coins[idx] <= V)
    {
        right = 1 + rec(coins, V - coins[idx], idx);
    }

    return dp[V][idx] = min(left, right);
}

int tabulation(int coins[], int M, int V)
{
    vector<vector<int>> dp(V + 1, vector<int>(M + 1));

    // init
    for (int i = 0; i <= V; i += 1)
    {
        if (i % coins[0] == 0)
            dp[i][0] = i / coins[0];
        else
            dp[i][0] = 1e9;
    }

    for (int i = 1; i <= V; i += 1)
    {
        for (int idx = 1; idx <= M; idx += 1)
        {
            int right = 1e9;

            if (coins[idx - 1] <= i)
                right = 1 + dp[i - coins[idx - 1]][idx];

            dp[i][idx] = min(dp[i][idx - 1], right);
        }
    }

    return dp[V][M];
}

int minCoins(int coins[], int M, int V)
{
    sort(coins, coins + M);
    int ans = tabulation(coins, M, V);

    if (ans == 1e9)
        return -1;
    return ans;

    /*
    dp.resize(V+1, vector<int>(M, -1));

    int ans = rec(coins, V, M-1);
    */
}

int main()
{
    int amount = 93;

    cout << findMinimumCoins(amount) << endl;

    // int coins[] = {9, 6, 5, 1};
    // int M = 4;
    int coins[] = {7, 15};
    int M = 2;
    
    int V = 11;

    cout << minCoins(coins, M, V) << endl;

    return 0;
}