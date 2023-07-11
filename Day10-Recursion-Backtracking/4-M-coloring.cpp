#include<bits/stdc++.h>
using namespace std;

bool canColor(vector<vector<int>>& mat, int i, int c)
{
    for(int itr=0; itr<mat.size(); itr++)
    {
        if(mat[i][itr])
        {
            if(mat[itr][itr] == c) return false;
        }
    }
    return true;
}

bool dfs(vector<vector<int>>& mat, int i, vector<bool>& vis, int m)
{
    vis[i] = true;

    for(int c=1; c<=m; c++)
    {
        if(canColor(mat, i, c))
        {
            mat[i][i] = c;
            for(int itr = 0; itr<mat.size(); itr++)
            {
                if(mat[i][itr])
                {
                    if(!vis[itr]) {
                        if(!dfs(mat, itr, vis, m)) return false;
                    }
                }
            }
            return true;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    vector<bool> vis(mat.size());

    for(int i=0; i<mat.size(); i++) {
        if(!vis[i]) 
        {
            if(!dfs(mat, i, vis, m)) return "No";
        } 
    }
    return "Yes";
}

bool solve(vector<vector<int>>& mat, int m, int i)
{
    for(int color=1; color<=m; color++)
    {
        if(canColor(mat, i, color))
        {
            mat[i][i] = color;
            if(i == mat.size()-1) return true;
            if(solve(mat, m, i+1)) return true;
            mat[i][i] = 0;
        }
    }
    return false;
}

string mColoring(vector<vector<int>> &mat, int m)
{
    if(solve(mat, m, 0)) return "Yes";
    return "No";   
}

int main()
{
    // vector<vector<int>> mat = {
    //     {0, 1, 1, 1},
    //     {1, 0, 1, 0},
    //     {1, 1, 0, 1},
    //     {1, 0, 1, 0}
    // };

    vector<vector<int>> mat = {
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0}
    };

    // cout<<graphColoring(mat, 3)<<endl;

    cout << mColoring(mat, 3) << endl;

    return 0;
}