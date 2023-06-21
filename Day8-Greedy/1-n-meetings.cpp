#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b)
{
    if(a.second.second == b.second.second) return a.first <= b.first;
    return a.second.second <= b.second.second;
}

void print(vector<pair<int, pair<int, int>>>& v)
{
    for(auto i: v) {
        cout << i.first << ": " << i.second.first << " - " << i.second.second << endl;
    }
    cout << "Finished printing" << endl;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    vector<pair<int, pair<int, int>>> meet;

    for(int i=0; i<start.size(); ++i) {
        meet.push_back({i+1, {start[i], end[i]}});
    }
    
    sort(meet.begin(), meet.end(), compare);

    // print(meet);

    vector<int> ans;
    ans.push_back(meet[0].first);
    int prevEnd = meet[0].second.second;

    for(int i=1; i<meet.size(); ++i)
    {
        if(meet[i].second.first > prevEnd) {
            prevEnd = meet[i].second.second;
            ans.push_back(meet[i].first);
        }
    }
    return ans;
}

/*
1 3 0 5 8 5
2 4 6 7 9 9
*/
int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    vector<int> ans = maximumMeetings(start, end);

    for(auto i: ans) cout << i << " ";
    cout << endl;

    return 0;
}