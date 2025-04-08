#include <iostream>
#include <array>
#include <cstring>
#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        array<int, 26> mp;
        memset(mp.data(), 0, mp.size() * sizeof(int));
        int odd = 0;
        int pair = 0;

        for (auto& c: s){
            mp[c-'a']++;
        }
        for (int i = 0; i < 26; i++){
            odd = mp[i] % 2 == 1 ? odd + 1 : odd;
        }
        return odd <= k && s.size() >= k;
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    bool ret = sol.canConstruct("qlkzenwmmnpkopu", 15);
    cout << ret << endl;
    ret = sol.canConstruct("leetcode", 3);
    cout << ret << endl;
    ret = sol.canConstruct("bruh", 4);
    cout << ret << endl;
    return 0;
}