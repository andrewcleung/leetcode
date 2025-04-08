#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        int numRow = grid.size();
        int numCol = grid[0].size();

        int dRow[4] = {1, -1, 0, 0};
        int dCol[4] = {0, 0, 1, -1};

        vector<vector<bool>> visited(numRow, vector<bool>(numCol, false));
        queue<pair<int,int>> bfs;

        int ret = 0;

        for (int i = 0; i < numRow; i++){
            for (int j = 0; j < numCol; j++){
                if (visited[i][j]) continue;
                visited[i][j] = true;
                if (grid[i][j] == 0) continue;

                bfs.push({i, j});
                int cnt = 0;

                while(!bfs.empty()){
                    auto [currRow, currCol] = bfs.front();
                    bfs.pop();
                    for(int nRow = 0; nRow < numRow; nRow++){
                        if (nRow == currRow) continue;
                        if (isValid(nRow, currCol, numRow, numCol) && !visited[nRow][currCol]){
                            visited[nRow][currCol] = true;
                            if (!grid[nRow][currCol]) continue;
                            cnt++;
                            bfs.push({nRow, currCol});
                        }
                    }
                    for (int nCol = 0; nCol < numCol; nCol++)
                    {
                        if (nCol == currCol) continue;
                        if (isValid(currRow, nCol, numRow, numCol) && !visited[currRow][nCol]){
                            visited[currRow][nCol] = true;
                            if (!grid[currRow][nCol]) continue;
                            cnt++;
                            bfs.push({currRow, nCol});
                        }
                    }
                }
                ret += cnt == 0? 0 : cnt + 1; 
            }
        }
        return ret;
    }

private:
    bool isValid(int row, int col, int numOfRows, int numOfCols)
    {
        return row >= 0 && col >= 0 && row < numOfRows && col < numOfCols;
    }
};

int main(int argc, char **argv)
{

    return 0;
}