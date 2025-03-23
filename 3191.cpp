#include <iostream>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        int ret = 0;
        for (int i = 0; i < n - 2; i++)
        {
            if (nums[i] != 0)
                continue;
            nums[i + 1] = nums[i + 1] == 1 ? 0 : 1;
            nums[i + 2] = nums[i + 2] == 1 ? 0 : 1;
            ret++;
        }
        if (!nums[n-1] || !nums[n-2]) return -1;
        return ret;
    }
};
int main(int argc, char **argv)
{
    return 0;
}