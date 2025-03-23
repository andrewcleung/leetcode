#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n);

        dp[0] = nums[0];
        if (n > 1)
            dp[1] = max(nums[0], nums[1]);

        if (n > 2)
        {
            for (int i = 2; i < n; i++)
            {
                dp[i] = max(nums[i] + dp[i-2], dp[i]);
            }
        }
        return dp[n-1];
    }
};

int main(int argc, char **argv)
{

    return 0;
}