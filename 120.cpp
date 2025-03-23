#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int height = triangle.size();
        vector<vector<int>> memo(height, vector(height, INT_MIN));
        dp(triangle, memo, 0, 0);
        return memo[0][0];
    }

    void dp(vector<vector<int>> &triangle, vector<vector<int>> &memo, int h, int idx)
    {
        if (h == triangle.size() - 1)
            memo[h][idx] = triangle[h][idx];
        else
        {
            if (memo[h + 1][idx] == INT_MIN)
                dp(triangle, memo, h + 1, idx);
            if (memo[h + 1][idx + 1] == INT_MIN)
                dp(triangle, memo, h + 1, idx + 1);
            memo[h][idx] = triangle[h][idx] + min(memo[h + 1][idx], memo[h + 1][idx + 1]);
        }
    }
};
int main(int argc, char **argv)
{
    return 0;
}