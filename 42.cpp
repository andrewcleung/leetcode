#include <iostream>

using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {

        int n = height.size();
        if (n == 1)
            return 0;
        vector<int> left(n);
        vector<int> right(n);
        left[0] = 0;
        right[n-1] = 0;

        for (int i = 1; i< n-1; i++){
            int diff = height[i-1] + left[i-1] - left[i];
            left[i] = diff > 0 ? diff : 0;
        }

        for (int i = n-2; i>0; i--){
            int diff = height[i+1] + right[i+1] - right[i];
            right[i] = diff > 0 ? diff : 0;
        }
        int ret = 0;
        for (int i = 1; i < n-1; i++){
            ret += min(left[i], right[i]);
        }
        return ret;
    }
};

int main(int argc, char **argv)
{
    return 0;
}