#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.size();

        // dp[i] = true means s[0..i-1] can be segmented into dict words
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                // If s[0..j-1] is segmented and s[j..i-1] is in the dict
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end())
                {
                    dp[i] = true;
                    break; // No need to check further splits for i
                }
            }
        }
        return dp[n];
    }
};
int main(int argc, char **argv)
{
    return 0;
}