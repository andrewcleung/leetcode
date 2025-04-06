#include <iostream>

using namespace std;
class Solution
{
public:
    string map[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void bt(string &digits, int index, string cur, vector<string> &ret){
        if (index == digits.length()) {
            ret.push_back(cur);
            return;
        }

        int digit = digits[index] - '0';
        int lim = digit == 7 || digit == 9 ? 4 : 3;

        for (int i = 0; i < lim; i++){
            bt(digits, index + 1, cur + map[digit-2][i], ret);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty()) return {};
        vector<string> ret;
        bt(digits,0, "", ret);
        return ret;
    }
};
int main(int argc, char **argv)
{
    return 0;
}