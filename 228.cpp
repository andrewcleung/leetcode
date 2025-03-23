#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        int n = nums.size();
        vector<string> ret;
        if (!n)
            return ret;

        int start = nums[0];
        if (n == 1){
            ret.push_back(to_string(start));
            return ret;
        }

        for (int i = 1; i < n; i++)
        {
            if (nums[i] - 1 != nums[i - 1])
            {
                if (start == nums[i - 1])
                    ret.push_back(to_string(start));
                else
                    ret.push_back(to_string(start) + "->" + to_string(nums[i - 1]));

                start = nums[i];
            }
            if (i == n - 1)
            {
                if (start == nums[i])
                    ret.push_back(to_string(start));
                else
                    ret.push_back(to_string(start) + "->" + to_string(nums[i]));
            }
        }
        return ret;
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    vector<int> input = {-1};
    vector<string> ret = sol.summaryRanges(input);
    for (auto s : ret)
    {
        cout << s << endl;
    }
    return 0;
}