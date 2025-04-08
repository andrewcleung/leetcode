#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};

int main(int argc, char** argv) {
    Solution solution;
    vector<int> input = {1 ,2, 3, 4, 5, 6};
    solution.rotate(input, 1);
    for (auto i : input){
        cout << i << endl;
    }
    return 0;
}