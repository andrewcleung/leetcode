#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ret = 0;
        for (int i = 0; i < words.size(); i++){
            for (int j = i+1; j < words.size(); j++){
                if (isPrefixAndSuffix(words[i], words[j])) {
                    ret++;
                }
            }
        }
        return ret;
    }
    bool isPrefixAndSuffix(string str1, string str2){
        if (str1.length() > str2.length()) return false;
        if (str2.substr(0, str1.length()) == str1 && str2.substr(str2.length() - str1.length(), str2.length()) == str1) {
            return true;
        }
        return false;
    }
};

int main(int argc, char** argv){
    Solution solution;
    vector<string> input = {"a","aba","ababa","aa"};
    int ret = solution.countPrefixSuffixPairs(input);
    cout << ret << endl;
    return 0;
}