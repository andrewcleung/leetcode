#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int n = blocks.length();
        int ps = 0;
        int ret = INT_MAX;

        for (int i = 0; i < n; i++) {
            ps += blocks[i] == 'B' ? 1 : 0;
            if (i>k) ps -= (blocks[i-k] == 'B' ? 1 : 0);
            ret = min(ret, k-ps);
        }
        return ret;
    }
};

int main(int argc, char **argv)
{

    return 0;
}