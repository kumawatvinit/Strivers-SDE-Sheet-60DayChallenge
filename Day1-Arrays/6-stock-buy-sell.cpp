#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int maxi = prices[n - 1];
    int ans = 0;

    for (int i = n - 1; i >= 0; --i)
    {
        if (prices[i] > maxi)
        {
            maxi = prices[i];
        }

        if (maxi - prices[i] > ans)
        {
            ans = maxi - prices[i];
        }
    }

    return ans;
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
    vector<int> prices{7, 1, 5, 3, 6, 4};
    print(prices);
    cout << maxProfit(prices);

    return 0;
}