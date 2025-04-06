#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int recursiveXor(vector<int>& nums, int sum, int index) {
        if (index == nums.size()) return sum;

        int total = 0;
        // sum if include
        total += recursiveXor(nums, sum^nums[index], index+1);
        // sum if exclude
        total += recursiveXor(nums, sum, index+1);
        return total;
    }

    int subsetXORSum(vector<int>& nums) {
        return recursiveXor(nums, 0, 0);
    }
};
int main(int argc, char** argv) {
  return 0;
}
