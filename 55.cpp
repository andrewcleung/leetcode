#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> memo(n, false);

        memo[0] = true;
        dp(nums, memo, 0);
        return memo[n-1];
    }
    void dp(vector<int> &nums, vector<bool>& memo, int last){

        for (int i = 1; i <= nums[last] ; i++){
            if (last+i >= nums.size()) break;
            if (memo[last+i]) continue;

            memo[last + i] = memo[last];
            dp(nums, memo, last + i);
        }
    }
};

class Solution2
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int maxReach = 0;
        for (int i = 0; i < n-1; i++){
            if (i > maxReach) return false;
            maxReach = max(maxReach, nums[i] + i);
        }
        return maxReach >= n-1;
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    vector<int> input = {3,0,8,2,0,0,1};
    bool ret = sol.canJump(input);
    cout << ret << endl;
    return 0;
}