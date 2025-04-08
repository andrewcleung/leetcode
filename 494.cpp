#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2*n + 1, 0));

        dp[0][n-1] = 1;
        dp[0][n+1] = 1;
        for (int i = 1; i < n; i++){
            for (int j = 0; j <  2*n + 1; j++){
                if (i+1 >= abs(j-n)){
                    dp[i][j] += dp[i-1][j-1];
                    dp[i][j] += dp[i-1][j+1];
                }
            }
        }
        return dp[n-1][target + n];
    }
};

int main(int argc, char **argv)
{

    return 0;
}