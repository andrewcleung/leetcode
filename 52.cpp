#include <iostream>

using namespace std;

class Solution
{
public:
    bool isValid(vector<vector<bool>> &board, pair<int, int> loc)
    {
        auto [x, y] = loc;
        int n = board.size();

        // up
        for (int i = x-1; i >= 0; i--)
        {
            if (board[i][y])
                return false;
        }

        // upper left
        for (int i = x-1, j = y-1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j])
                return false;
        }

        // upper right
        for (int i = x-1, j = y+1; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j])
                return false;
        }
        return true;
    }
    void findQueen(vector<vector<bool>> &board, int row, int numQueen, int &ret)
    {
        int n = board.size();
        if (numQueen == n)
        {
            ret++;
            return;
        }
        if (row == n) return;
        for (int j = 0; j < n; j++)
        {
            if (isValid(board, {row, j}))
            {
                board[row][j] = true;
                findQueen(board, row+1, numQueen + 1, ret);
                board[row][j] = false;
            }
        }
    }
    int totalNQueens(int n)
    {
        vector<vector<bool>> board(n, vector<bool>(n, false));
        int ret = 0;
        findQueen(board, 0, 0, ret);
        return ret;
    }
};
int main(int argc, char **argv)
{
    Solution sol;
    int ret = sol.totalNQueens(4);
    cout << ret << endl;
    return 0;
}