#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<int>& pos, int n, int i, int j)
{
    for(int itr = 0; itr<i; itr++)
    {
        if(pos[itr*n + j] == 1) return false;
    }

    for(int itr = 1; i-itr>=0; itr++)
    {
        if(j-itr >= 0 && pos[(i-itr)*n + j-itr] == 1) return false;
        if(j+itr < n && pos[(i-itr)*n + j+itr] == 1) return false;
    }

    return true;
}

vector<vector<int>> ans;

void rec(int row, int n, vector<int>& pos)
{
    if(row == n) {
        ans.push_back(pos);
        return;
    }

    for(int j=0; j<n; j++)
    {
        if(isSafe(pos, n, row, j)) {
            pos[row*n + j] = 1;
            rec(row+1, n, pos);
            pos[row*n + j] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<int> pos(n*n);

    rec(0, n, pos);

    return ans;
}

void print(vector<vector<int>> &ans, int n)
{
    cout << "Start: \n";
    
    for(auto &i: ans)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                if(i[j*n + k] == 1) cout << "Q ";
                else cout << ". ";
            }
            cout << endl;
        }


        cout << endl;
    }
    cout << "End!\n";
}

int main()
{
    vector<vector<int>> ans = solveNQueens(4);
    print(ans, 4);

    return 0;
}