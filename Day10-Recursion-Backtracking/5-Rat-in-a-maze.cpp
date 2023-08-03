#include <bits/stdc++.h>
#define valid(i, j, n) (i >= 0 && j >= 0 && i < n && j < n)

using namespace std;

void solve(vector<vector<int>> &mat, set<pair<int, int>> &taken, int i, int j, string temp, vector<string> &ans)
{
    int n = mat.size();
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(temp);
        return;
    }

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    vector<char> path = {'R', 'L', 'D', 'U'};

    for (int k = 0; k < 4; k++)
    {
        int newX = i + dx[k];
        int newY = j + dy[k];

        if (valid(newX, newY, n) && mat[newX][newY] && !taken.count({newX, newY}))
        {
            taken.insert({newX, newY});
            solve(mat, taken, newX, newY, temp + path[k], ans);
            taken.erase({newX, newY});
        }
    }
}

vector<string> ratMaze(vector<vector<int>> &mat)
{
    // D, U, R, L

    set<pair<int, int>> taken;
    vector<string> ans;
    string temp = "";
    int n = mat.size();

    if (mat[0][0] && mat[n - 1][n - 1])
    {
        taken.insert({0, 0});
        solve(mat, taken, 0, 0, temp, ans);
    }
    return ans;
}

int main()
{
    vector<vector<int>> mat = {{1, 0, 0, 0},
                               {1, 1, 0, 1},
                               {1, 1, 0, 0},
                               {0, 1, 1, 1}};

    vector<string> ans = ratMaze(mat);

    for (auto path : ans)
    {
        cout << path << endl;
    }

    return 0;
}