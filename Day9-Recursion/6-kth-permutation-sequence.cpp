#include<bits/stdc++.h>
using namespace std;

string inBuilt(int n, int k)
{
    vector<int> ans(n);
    for(int i=1; i<=n; i++) ans[i-1] = i;
    k-= 1;

    while(k--) {
        next_permutation(ans.begin(), ans.end());
    }

    string str = "";
    for(int i: ans) str+= to_string(i);
    return str;
}

string permutation(int n, int k)
{
    string ans = "";
    vector<int> numbers(n);
    int fact = 1;
    for(int i=1; i<n; i++) {
        fact*= i;
        numbers[i-1] = i;
    }
    numbers[n-1] = n;
    k-= 1;

    while(true)
    {
        ans+= to_string(numbers[k/fact]);
        numbers.erase(numbers.begin() + k/fact);
        
        if(numbers.size() == 0) break;
        k%= fact;
        fact/= numbers.size();
    }
    return ans;
}


string getPermutation(int n, int k) {
    // return inBuilt(n, k);
    return permutation(n, k);
}

int main()
{
    cout << permutation(3, 1) << endl;
    cout << getPermutation(3, 2) << endl;
    cout << getPermutation(3, 3) << endl;
    cout << getPermutation(3, 6) << endl;
    
    cout << getPermutation(4, 9) << endl;

    return 0;
}