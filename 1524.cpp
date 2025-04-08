#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr)
    {
        // use long long to store the integer
        int n = arr.size();
        long long ps = 0;
        int even = 0, odd = 0;
        long long ret = 0;
        const long long MOD = 1000000007;

        for (int i = 0; i < n; i++){
            ps += arr[i];
            if (ps % 2 == 0){
                ret = (ret + odd) % MOD;
                odd++;
            }
            else {
                ret = (ret + even) % MOD;
                even++;
            }
        }
        return ret;
    }
};

int main(int argc, char **argv)
{

    return 0;
}