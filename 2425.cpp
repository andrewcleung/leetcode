#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        int ret = 0;
        if (nums1.size() % 2 != 0)
        {
            for (auto &nn : nums2)
            {
                ret ^= nn;
            }
        }

        if (nums2.size() % 2 != 0)
        {
            for (auto &nn : nums1)
            {
                ret ^= nn;
            }
        }
        return ret;
    }
};

int main(int argc, char **argv)
{

    return 0;
}