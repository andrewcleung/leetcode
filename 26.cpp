#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int curr = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[curr-1]) {
                nums[curr++] = nums[i];
            }
        }
        return curr;
    }
};


int main(int argc, char* argv[]) {

    Solution solution;
    vector<int> input = {5,5,3,2,1};
    int ret = solution.removeDuplicates(input);
    cout << ret << endl;
    return 0;
}