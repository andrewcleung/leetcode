#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        if (nums.size() == 1) return nums;
        // idea is that to add a num to a set, it should be able to divide the largest number of that set
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // this represents the maximum subarray length at the index, initially it should be at 1
        vector<int> dp(n, 1);
        // this points to the previous index where it has the subarray
        vector<int> prev(n,0);

        int maxIndex = 0;
        for (int i = 1; i < n; i++){
            for (int j = 0; j < i; j++){
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            maxIndex = dp[i] > dp[maxIndex] ? i : maxIndex;
        }

        int len = dp[maxIndex];
        vector<int> ret;
        for (int i = 0; i < len; i++){
            ret.push_back(nums[maxIndex]);
            maxIndex = prev[maxIndex];
        }
        return ret;
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    vector<int> input = {5,9,18,54,108,540,90,180,360,720};
    vector<int> output = sol.largestDivisibleSubset(input);
    for (auto ii : output){
        cout << ii << ", " ;
    }
    cout << endl;
    return 0;
}