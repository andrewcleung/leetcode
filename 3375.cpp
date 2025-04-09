#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int> ms;
        int smallest = INT_MAX;
        for (auto& nn : nums) {
            smallest = min(nn, smallest);
            ms[nn] = 1;
        }
        if (k > smallest) return -1;
        int ret = ms.size();
        if (ms[k]) ret--;
        return ret;
    }
};
int main(int argc, char** argv){

  return 0;
}