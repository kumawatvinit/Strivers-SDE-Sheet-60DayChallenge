#include<bits/stdc++.h>
using namespace std;


bool isValid(int board[][9], int i, int j, int c)
{
    for(int k=0; k<9; k++)
    {
        if(board[i][k] == c) return false;
        if(board[k][j] == c) return false;
        if(board[3*(i/3)+k/3][3*(j/3)+k%3] == c) return false;
    }

    return true;
}

bool rec(int board[][9], int i, int j)
{
    if(i >= 9 || j >= 9) return true;

    if (board[i][j] != 0) {
        return rec(board, (j == 8) ? i + 1 : i, (j == 8) ? 0 : j + 1);
    }

    
    for(int k=1; k<=9; k++)
    {
        if(isValid(board, i, j, k)) {
            board[i][j] = k;
            int row = (j==8)? i+1: i;
            int col = (j==8)? 0: j+1;
            if(rec(board, row, col)) {
                return true;
            }
        }
        board[i][j] = 0;
    }
    return false;
}

bool sudokuSolver(int board[][9]) {
    return rec(board, 0, 0);
}

class Solution {
    bool isValid(vector<vector<char>>& board, int row, int col, char c)
    {
        for(int i=0; i<9; i++)
        {
            if(board[i][col] == c) return false;
            if(board[row][i] == c) return false;
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;
        }

        return true;
    }
public:
    bool solveSudoku(vector<vector<char>>& board) {
        
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j] == '.')
                {
                    for(char c='1'; c<='9'; c++)
                    {
                        if(isValid(board, i, j, c))
                        {
                            board[i][j] = c;

                            if(solveSudoku(board)) {
                                return true;
                            }
                            else {
                                board[i][j] = '.';
                            }
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'}, 
        {'.','9','8','.','.','.','.','6','.'}, 
        {'8','.','.','.','6','.','.','.','3'}, 
        {'4','.','.','8','.','3','.','.','1'}, 
        {'7','.','.','.','2','.','.','.','6'}, 
        {'.','6','.','.','.','.','2','8','.'}, 
        {'.','.','.','4','1','9','.','.','5'}, 
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution s;
    s.solveSudoku(board);

    for(auto row: board)
    {
        for(auto col: row)
        {
            cout<<col<<" ";
        }
        cout<<endl;
    }

    return 0;
}