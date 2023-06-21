#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int>& a, vector<int>& b)
{
    return a[1] >= b[1];
}

int greedy(vector<vector<int>> &jobs)
{
    // O(nlogn) + O(n*m)
    // m = max(deadline)

    sort(jobs.begin(), jobs.end(), compare);
    int maxDead = jobs[0][0];
    for(auto i: jobs) {
        if(i[0] > maxDead) maxDead = i[0];
    }

    vector<bool> isFree(maxDead+1, true);

    int profit = jobs[0][1];
    isFree[jobs[0][0]] = false;

    for(int i=1; i<jobs.size(); ++i)
    {
        for(int idx = jobs[i][0]; idx>0; --idx)
        {
            if(isFree[idx]) {
                isFree[idx] = false;
                profit+= jobs[i][1];
                break;
            }
        }
    }

    return profit;
}
int jobScheduling(vector<vector<int>> &jobs)
{
    // return greedy(jobs);


    // O(n*log(max(n, maxDeadline)))
    sort(jobs.begin(), jobs.end(), compare);
    int maxDead = jobs[0][0];
    for(auto i: jobs) {
        if(i[0] > maxDead) maxDead = i[0];
    }

    set<int, greater<int>> slots;
    for(int i=maxDead; i>0; --i) {
        slots.insert(i);
    }

    int profit = 0;

    for(int i=0; i<jobs.size(); i+=1)
    {   
        if(slots.size() == 0) return profit;
        else if(jobs[i][0] < *slots.rbegin()) continue;
        else 
        {
            profit+= jobs[i][1];
            slots.erase(slots.lower_bound(jobs[i][0]));
        }
    }

    return profit;
}


int main()
{
    vector<vector<int>> jobs = {{2,100},{1,19},{2,27},{1,25},{3,15}};
    cout<<jobScheduling(jobs);

    return 0;
}