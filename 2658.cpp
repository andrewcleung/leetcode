#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <array>

using namespace std;

class Solution
{
public:
    int findMaxFish(vector<vector<int>> &grid)
    {
        int numRow = grid.size();
        int numCol = grid[0].size();
        vector<vector<bool>> visited(numRow, vector<bool>(numCol, false));
        int dRow[4] = {1, -1, 0, 0};
        int dCol[4] = {0, 0, 1, -1};
        int ret = 0;

        queue<array<int, 2>> q;
        for (int i = 0; i < numRow; i++)
        {
            for (int j = 0; j < numCol; j++)
            {
                visited[i][j] = true;
                if (grid[i][j] != 0){
                    q.push({i, j});
                }
                int currSum = 0;
                while (!q.empty())
                {
                    auto [currRow, currCol] = q.front();
                    currSum += grid[currRow][currCol];
                    q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nRow = currRow + dRow[dir];
                        int nCol = currCol + dCol[dir];
                        if (isValid(nRow, nCol, numRow, numCol) && !visited[nRow][nCol] && grid[nRow][nCol] != 0)
                        {
                            visited[nRow][nCol] = true;
                            q.push({nRow, nCol});
                        }
                    }
                }
                ret = max(ret, currSum);
            }
        }
        return ret;
    }

private:
    bool isValid(int row, int col, int numRow, int numCol)
    {
        return row >= 0 && col >= 0 && row < numRow && col < numCol;
    }
};

int main(int argc, char **argv)
{
    return 0;
}