#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> ps(s.length(), 0);
        vector<bool> ch(26, false);
        int ret = 0;

        ps[0] = 1;
        ch[s[0] - 'a'] = true;

        for (int i = 1; i < s.length(); i++){
            if (!ch[s[i] - 'a']){
                ch[s[i] - 'a'] = true;
                ps[i] += 1;
            }
            ps[i] += ps[i-1];
        }

        for (int i = 0; i < 26; i++)
        {
            int start = s.find('a' + i);
            int end = s.find_last_of('a' + i);
            if (start == string::npos || end == string::npos || start == end) continue;
            ret += ps[end] - (!start ? 1 : ps[start-1]);
            
            if (s.find('a' + i, start + 1) != end) {
                ret++;
            }
        }
        return ret;
    }
};

int main(int argc, char** argv){
    Solution solution;
    int ret = solution.countPalindromicSubsequence("bbcbaba");
    cout << ret << endl;
    return 0;
}