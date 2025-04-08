#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    long long gridGame(vector<vector<int>> &grid)
    {

        int numRow = 2;
        int numCol = grid[0].size();

        vector<vector<long long>> ps(numRow, vector<long long>(numCol, 0));
        ps[0][0] = grid[0][0];
        ps[1][0] = grid[1][0];

        for (int i = 0; i < 2; i++)
        {
            for (int j = 1; j < numCol; j++)
            {
                ps[i][j] = ps[i][j - 1] + grid[i][j];
            }
        }

        long long minSecondRobotScore = LLONG_MAX;

        // Iterate through all possible down columns
        for (int down = 0; down < numCol; down++)
        {
            // Calculate remaining sums
            long long topRemaining = ps[0][numCol - 1] - ps[0][down];
            long long bottomRemaining = down > 0 ? ps[1][down - 1] : 0;

            // Second robot's score is the max of the two
            long long secondRobotScore = max(topRemaining, bottomRemaining);

            // Update the minimum score the second robot can achieve
            minSecondRobotScore = min(minSecondRobotScore, secondRobotScore);
        }

        return minSecondRobotScore;
    }
};

int main(int argc, char **argv)
{

    return 0;
}