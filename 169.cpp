#include <iostream>
#include <unordered_map>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int>mp;
        int max = INT_MIN;
        int maxf = 0;
        for (auto& n : nums){
            mp[n]++;
            if (mp[n] > maxf){
                maxf = mp[n];
                max = n;
            }
        }
        return max;
    }
};

int main(int argc, char **argv)
{
    vector<int> input = {2,2,1,1,1,2,2};
    vector<int> input2 = {3,4,4};
    Solution solution;
    int ret = solution.majorityElement(input2);
    cout << ret << endl;
    return 0;
}