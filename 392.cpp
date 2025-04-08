#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p1 = 0;
        int p2 = 0;
        while (p1 < s.size() && p2 < t.size()){
            if (s[p1] == t[p2]){
                p1++;
            }
            p2++;
        }
        return p1 == s.size();
    }
};


int main(int argc, char **argv)
{
    Solution sol;
    bool ret = sol.isSubsequence("ahbc", "ahbgdc");
    cout << ret << endl;
    return 0;
}