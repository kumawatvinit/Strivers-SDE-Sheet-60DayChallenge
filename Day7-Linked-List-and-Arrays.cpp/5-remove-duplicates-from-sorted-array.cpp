#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int i=0, j=1;

    for(; j<nums.size(); j+= 1)
    {
        if(nums[j] != nums[i]) {
            nums[i+1] = nums[j];
            i+= 1;
        }
    }
    
    return i+1;
}
int main()
{
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    cout << "Before: ";
    for(int i=0; i<nums.size(); i+= 1)
        cout<<nums[i]<<" ";
    cout<<endl;


    cout << "After removing duplicates: ";
    int len = removeDuplicates(nums);

    for(int i=0; i<len; i+= 1)
        cout<<nums[i]<<" ";
    cout<<endl;

    return 0;
}