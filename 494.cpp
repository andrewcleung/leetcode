#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<pair<int,int>, int> memo;
        
        // state - curent index, current sum
        return dp(nums, target, memo, 0, 0);

        
    }
    int dp(vector<int>& nums, int target, unordered_map<pair<int,int>, int> &memo, int index ,int currSum){
        if (memo.find({index,currSum}) != memo.end()) return memo[{index, currSum}];
        if (index >= nums.size() && currSum == target) return 1;
        if (index >= nums.size()) return 0;
        int ans = dp(nums, target, memo, index+1, currSum + nums[0]) + dp(nums, target, memo, index+1, currSum - nums[0]);
        memo[{index, currSum}] = ans;
        return ans;
    }
};

int main(int argc, char** argv) {
  return 0;
}