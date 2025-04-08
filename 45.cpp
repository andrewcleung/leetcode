#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n);
        dp[n-1] = 0;
        for (int i = n-2; i >= 0; i--){
            int cm = INT_MAX;
            int val = nums[i];
            for (int j = 1; j <= val && i+j < n; j++){
                cm = min(cm, dp[i+j]);
            }
            dp[i] = cm != INT_MAX ? cm + 1 : INT_MAX;
        }
        return dp[0];
    }
};

int main(int argc, char **argv)
{

    return 0;
}