#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int currMax = nums[0];
        int ret = nums[0];
        for (int i = 1; i < n; i++){
            currMax = max(currMax+nums[i], nums[i]);
            ret = max(currMax, ret);
        }
        return ret;
    }
};

int main(int argc, char **argv)
{
    return 0;
}