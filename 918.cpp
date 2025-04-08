#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int maxSum = INT_MIN, curMax = 0;
        int minSum = INT_MAX, curMin = 0;

        for (int num : nums) {
            totalSum += num;

            // Kadane's Algorithm for max subarray sum
            curMax = max(curMax + num, num);
            maxSum = max(maxSum, curMax);

            // Kadane's Algorithm for min subarray sum
            curMin = min(curMin + num, num);
            minSum = min(minSum, curMin);
        }

        // If all elements are negative, return maxSum (since totalSum - minSum = 0 in this case)
        if (maxSum < 0) return maxSum;

        // Maximum of:
        // 1. The normal max subarray sum (Kadane's result)
        // 2. The circular max subarray sum (totalSum - minSum)
        return max(maxSum, totalSum - minSum);
    }
};

int main(int argc, char **argv)
{

    return 0;
}