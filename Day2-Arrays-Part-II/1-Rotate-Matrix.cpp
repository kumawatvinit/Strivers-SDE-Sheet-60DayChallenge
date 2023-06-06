#include<bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int rowStart = 0, rowEnd = n-1, colStart = 0, colEnd = m-1;

    while(rowStart < rowEnd && colStart < colEnd)
    {
        int temp = mat[rowStart][colStart];

        for(int row = rowStart; row<rowEnd; ++row) {
            mat[row][colStart] = mat[row+1][colStart];
        }
        for(int col=colStart; col<colEnd; ++col) {
            mat[rowEnd][col] = mat[rowEnd][col+1];
        }
        for(int row=rowEnd; row>rowStart; --row) {
            mat[row][colEnd] = mat[row-1][colEnd];
        }
        for(int col = colEnd; col>colStart+1; --col) {
            mat[rowStart][col] = mat[rowStart][col-1];
        }

        mat[rowStart][colStart+1] = temp;
        ++rowStart, ++colStart, --rowEnd, --colEnd;
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
    vector<vector<int>> mat{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};

    print(mat);
    rotateMatrix(mat, mat.size(), mat[0].size());
    print(mat);

    return 0;
}