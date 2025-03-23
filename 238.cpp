#include <iostream>

using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> output(n);
        int prefix = 1;
        for (int i = 0; i < n; i ++){
            output[i] = prefix;
            prefix *= nums[i];
        }
        prefix = 1;
        for (int i = n-1; i >= 0; i--){

            output[i] *= prefix;
            prefix *= nums[i];
        }
        return output;
    }
};
int main(int argc, char **argv)
{
    return 0;
}