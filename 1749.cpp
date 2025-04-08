#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        int ret = 0, mostn = 0, mostp = 0, ps = 0;
        for (auto& n : nums){
            ps += n;
            int sum = 0;
            if (ps == 0) sum = max(-mostn, mostp);
            else sum = ps > 0? ps - mostn : -(ps - mostp);
            ret = max(sum, ret);
            mostn = min(ps, mostn);
            mostp = max(ps, mostp);
        }
        return ret;
    }
};
int main(int argc, char **argv)
{

    return 0;
}