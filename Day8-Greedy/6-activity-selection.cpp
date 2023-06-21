#include<bits/stdc++.h>
using namespace std;


int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int, int>> v(start.size());

    for(int i=0; i<start.size(); i+= 1)
    {
        v[i] = {start[i], finish[i]};
    }

    sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b) {
        return a.second <= b.second;
    });

    int last = v[0].second;
    int ans = 1;

    for(int i=1; i<start.size(); i+= 1)
    {
        if(v[i].first >= last) {
            last = v[i].second;
            ans+= 1;
        }
    }
    
    return ans;
}

int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};

    cout << maximumActivities(start, finish) << endl;

    return 0;
}