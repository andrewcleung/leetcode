#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int start = 0, end = 1;
        int n = nums.size();
        int ret = 1;
        int count = 1;
        int curr = nums[0];

        while (end < n){
            if ((curr & nums[end]) != 0){
                curr -= nums[start];
                start++;
                count--;
            }
            else {
                curr += nums[end];
                end++;
                count++;
            }
            ret = max(count, ret);
        }
        return ret;
    }
};

int main(int argc, char **argv)
{
    return 0;
}