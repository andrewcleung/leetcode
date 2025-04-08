#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <deque>

using namespace std;

class Solution
{
public:
    int minCost(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int weight[n][m];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                weight[i][j]=INT_MAX;
            }
        }
        
        deque<pair<int, int>> bfs;
        bfs.push_back({0, 0});
        weight[0][0] = 0;

        while (!bfs.empty()){
            pair<int,int> curr = bfs.front();
            auto [x, y] = bfs.front();
            bfs.pop_front();
            for (int i = 0; i < dir.size(); i++)
            {
                auto& [di, dj] = dir[i];
                int ni = x + di;
                int nj = y + dj;
                int edgeweight = grid[x][y] == i + 1 ? 0 : 1;

                if (ni >= 0 && ni< n && nj>= 0 && nj< m && weight[x][y] + edgeweight < weight[ni][nj])
                {
                    weight[ni][nj] = weight[x][y] + edgeweight;
                    if (edgeweight){
                        bfs.push_back({ni, nj});
                    }
                    else {
                        bfs.push_front({ni, nj});
                    }
                }
            }
        }
        return weight[n-1][m-1];
    }
};

int main(int argc, char **argv)
{

    return 0;
}