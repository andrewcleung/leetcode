#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ret = 0;
        for (auto &w : words)
        {
            ret = w.find(pref) == 0 ? ret + 1 : ret;
        }
        return ret;
    }
};

int main(int argc, char** argv){
    vector<string> input = {"pay","attention","practice","attend"};
    Solution solution;
    int ret = solution.prefixCount(input, "at");
    cout << ret << endl;
    return 0;
}