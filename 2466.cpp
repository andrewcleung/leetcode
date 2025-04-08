#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int MOD = (int) pow(10, 9) + 7;

    int countGoodStrings(int low, int high, int numZero, int numOne) {
        vector<int> memo(high+1, -1);
        return dp(low, high, numZero, numOne, 0, memo);
    }
private:
    int dp(int low, int high, int numZero, int numOne, int len, vector<int> &memo){
        if (len > high)
            return 0;
        if (memo[len] != -1) return memo[len];

        int count = 0;
        if (len >= low) {
            count = 1;
        }
        count = (count + dp(low, high, numZero, numOne, len + numOne, memo)) % MOD;
        count = (count + dp(low, high, numZero, numOne, len + numZero, memo)) % MOD;
        memo[len] = count;
        return count;
    }
};

int main(int argc, char* argv[]){
    
    Solution solution;
    int ret = solution.countGoodStrings(3, 3, 1, 1);
    cout << ret << endl;
    return 0;
}