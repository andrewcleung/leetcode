#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int dRow[4] = {0, 0, -1, 1};
        int dCol[4] = {-1, 1, 0, 0};

        int numRows = heightMap.size();
        int numCols = heightMap[0].size();

        vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));

        priority_queue<Cell> pq;

        for (int i = 0; i < numRows; i++)
        {
            pq.push(Cell(i, 0, heightMap[i][0]));
            pq.push(Cell(i, numCols - 1, heightMap[i][numCols - 1]));
            visited[i][0] = visited[i][numCols - 1] = true;
        }

        for (int i = 0; i < numCols; i++)
        {
            pq.push(Cell(0, i, heightMap[0][i]));
            pq.push(Cell(numRows - 1, i, heightMap[numRows - 1][i]));
            visited[0][i] = visited[numRows - 1][i] = true;
        }

        int ret = 0;

        while (!pq.empty())
        {
            Cell curr = pq.top();
            pq.pop();
            int currRow = curr.x;
            int currCol = curr.y;
            int minBoundaryHeight = curr.height;

            for (int direction = 0; direction < 4; direction++)
            {
                int nRow = currRow + dRow[direction];
                int nCol = currCol + dCol[direction];

                if (isValidCell(nRow, nCol, numRows, numCols) && !visited[nRow][nCol])
                {
                    int nHeight = heightMap[nRow][nCol];
                    if (nHeight < minBoundaryHeight)
                    {
                        ret += minBoundaryHeight - nHeight;
                    }
                    pq.push(Cell(nRow, nCol, max(nHeight, minBoundaryHeight)));
                    visited[nRow][nCol] = true;
                }
            }
        }
        return ret;
    }

private:
    struct Cell
    {
        int x;
        int y;
        int height;

        Cell(int x, int y, int height)
            : x(x), y(y), height(height) {}

        bool operator<(const Cell &other) const
        {
            return height >= other.height;
        }
    };

    bool isValidCell(int row, int col, int numOfRows, int numOfCols)
    {
        return row >= 0 && col >= 0 && row < numOfRows && col < numOfCols;
    }
};

int main(int argc, char **argv)
{

    return 0;
}