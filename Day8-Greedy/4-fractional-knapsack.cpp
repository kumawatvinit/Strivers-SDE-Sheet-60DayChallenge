#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int>& a, pair<int, int>& b)
{
    return (a.second*1.0/a.first) >= (b.second*1.0/b.first);
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(), items.end(), compare);
    
    double ans = 0;

    for(auto i: items)
    {
        if(i.first >= w) {
            ans+= (i.second*w*1.0)/i.first;
            break;
        } else {
            ans+= i.second;
            w-= i.first;
        }
    }

    return ans;
}

int main()
{
    vector<pair<int, int>> items = {{10, 60}, {40, 40}, {20, 100}, {30, 120}};
    int n = items.size();
    int w = 50;

    cout<<maximumValue(items, n, w);

    return 0;
}