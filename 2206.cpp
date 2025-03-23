#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool divideArray(vector<int> &nums)
    {
        vector<bool> ht(500, true);

        for (auto& i: nums){
            ht[i-1] = !ht[i-1];
        }
        for (auto& i: nums){
            if (!ht[i-1]) return false;
        }
        return true;
    }
};

int main(int argc, char** argv) {
  return 0;
 }