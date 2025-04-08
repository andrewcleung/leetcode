#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
    #define ll long long
public:
    int waysToSplitArray(vector<int>& nums) {
        ll leftsum = INT_MIN;
        ll rightsum = INT_MIN;
        int ret = 0;

        for (auto &n : nums){
            rightsum += n;
        }
        
        for (int i = 0; i < nums.size() - 1; i++){
            leftsum += nums[i];
            rightsum -= nums[i];
            ret = leftsum >= rightsum ? ret + 1 : ret;
        }
        return ret;
    }
};

int main(int argc, char** argv){
    Solution solution;
    vector<int> input = {2,3,1,0};
    int ret = solution.waysToSplitArray(input);
    cout << ret << endl;
    return 0;
}