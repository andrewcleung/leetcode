#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int hash[100] = {0};
        int start = 0, end = 0;
        int ret = 0;

        for (;end<nums.size(); end++){
            hash[nums[end]-1]++;

            while (hash[nums[end]-1] > 1){
                for (int i = 0; i < 3; i++){
                    if (start+i == nums.size()) break;
                    if (start+i > end) break;
                    hash[nums[start+i]-1]--;
                }
                ret++;
                start = start + 3;
                if (start > end) end = start;
            }
        }
        return ret;
    }
};
int main(int argc, char** argv){

  return 0;
}