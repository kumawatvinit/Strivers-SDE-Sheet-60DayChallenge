#include<bits/stdc++.h>
using namespace std;

// there can be max. 2 majority elements which occur more than n/3 times
vector<int> majorityElementII(vector<int> &arr)
{
    // we need max two elements
    int cnt1 = 0, cnt2 = 0, num1=0, num2 = 0;

    for(int i: arr)
    {
        if(num1 == i) ++cnt1;
        else if(num2 == i) ++cnt2;
        else if(cnt1 == 0) {
            cnt1 = 1;
            num1 = i;
        }
        else if(cnt2 == 0) {
            cnt2 = 1;
            num2 = i;
        }
        else {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0, cnt2 = 0;
    for(int i: arr)
    {
        if(i == num1) cnt1++;
        else if(i == num2) cnt2++;
    }

    vector<int> ans;
    if(cnt1 > arr.size()/3) ans.push_back(num1);
    if(cnt2 > arr.size()/3) ans.push_back(num2);
    return ans;
}



int main()
{
    vector<int> arr = {1, 1, 1, 3, 3, 2, 2, 2};
    // vector<int> arr = {3,2,2,1,5,2,3};

    vector<int> ans = majorityElementII(arr);
    for(int i: ans) cout << i << " ";
    cout << endl;

    return 0;
}