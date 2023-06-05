#include<bits/stdc++.h>
using namespace std;

void setZeros(vector<vector<int>> &matrix)
{
	int n = matrix.size(), m = matrix[0].size();
	bool row = false, col = false;

		
	// mark in 0th row and col, which all rows/columns will be zero
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<m; ++j)
		{
			if(matrix[i][j] == 0)
			{
                if(i == 0) row = true;
                if(j == 0) col = true;

				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	// make it all zero
	for(int i=1; i<n; ++i)
	{
		for(int j=1; j<m; ++j)
		{
			if(matrix[i][0] == 0 || matrix[0][j] == 0)
			{
				matrix[i][j] = 0;
			}
		}
	}

	// setup 0th row and column
	if(row)
	{
		for(int j=0; j<m; ++j) matrix[0][j] = 0;
	}
	if(col)
	{
		for(int i=0; i<n; ++i) matrix[i][0] = 0;
	}
}

void print(vector<vector<int>> &ans)
{
    cout << "Start: \n";
    
    for(auto &i: ans)
    {
        for(auto &j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << "End!\n";
}

int main()
{
    vector<vector<int>> matrix{{0,1,2,0},{3,4,5,2},{1,3,1,5}};

    print(matrix);
    setZeros(matrix);
    print(matrix);

    return 0;
}