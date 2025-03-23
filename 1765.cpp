#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int numRow = isWater.size();
        int numCol = isWater[0].size();
        int dRow[4] = {1, -1, 0, 0};
        int dCol[4] = {0, 0, 1, -1};

        vector<vector<int>> height(numRow, vector<int>(numCol, INT_MIN));
        queue<pair<int, int>> bfs;

        for (int row = 0; row < numRow; row++)
        {
            for (int col = 0; col < numCol; col++)
            {
                if (isWater[row][col])
                {
                    height[row][col] = 0;
                    bfs.push({row, col});
                }
            }
        }

        while (!bfs.empty())
        {
            auto [row, col] = bfs.front();
            bfs.pop();
            for (int i = 0; i < 4; i++){
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];
                if (isValid(nRow, nCol, numRow, numCol) && height[nRow][nCol] == INT_MIN){
                    height[nRow][nCol] = height[row][col] + 1;
                    bfs.push({nRow, nCol});
                }
            }
        }
        return height;
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