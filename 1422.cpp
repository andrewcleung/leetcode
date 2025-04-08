#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    int maxScore(string s){
        int left = s[0] == '0' ? 1 : 0;
        int right = 0;
        int maxScore = left;
        int cnt = 0;

        for (int i = 1; i < s.length() - 1; i++)
        {
            right = s[i] == '1' ? right + 1 : right;
            cnt++;
            maxScore = left + right;
            if (left + cnt - right > maxScore)
            {
                left += cnt - right; 
                maxScore = left;
                right = 0;
                cnt = 0;
            }
        }
        maxScore = s[s.length()-1] == '1' ? maxScore + 1 : maxScore;
        return maxScore;
    }
};

int main(int argc, char** argv){
    Solution solution;
    int ret = solution.maxScore("00111");
    cout << ret << endl;
    return 0;
}