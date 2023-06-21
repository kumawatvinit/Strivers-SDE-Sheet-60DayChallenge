#include<bits/stdc++.h>
using namespace std;

int greedy(int at[], int dt[], int n)
{
    sort(at, at+n);
    sort(dt, dt+n);

    int cnt = 1, maxi = 1;
    int i = 1, j = 0;

    while(i<n && j<n)
    {
        if(at[i] <= dt[j]) {
            cnt++;
            i+= 1;
        } else {
            // cnt--;
            j+= 1;
            i+= 1;
        }

        maxi = max(maxi, cnt);
    }
    return maxi;
}

int calculateMinPatforms(int at[], int dt[], int n) {
    // return greedy(at, dt, n);

    int plat[2361] = {0};

    for (int i = 0; i < n; ++i) {
        plat[at[i]]+= 1;
        plat[dt[i]+1]-= 1;
    }

    int ans = 1;
    for(int i=1; i<2361; ++i)
    {
        plat[i]+= plat[i-1];


        ans = max(ans, plat[i]);
        // cout << "ans: " << ans << endl;
    }

    return ans;
}

int main()
{
    int at[] = {900, 940, 950, 1100, 1500, 1800};
    int dt[] = {910, 1200, 1120, 1130, 1900, 2000};

    int n = sizeof(at)/sizeof(at[0]);

    cout << calculateMinPatforms(at, dt, n) << endl;

    return 0;
}