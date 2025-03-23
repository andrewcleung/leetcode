#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char> word_to_char;
        vector<string> char_to_word(26, "");
        stringstream ss(s);
        string substring;

        int i = 0;

        while(getline(ss, substring, ' ')){
            if (i >= pattern.length()) return false;
            if (char_to_word[pattern[i]-'a'] != ""){
                if (char_to_word[pattern[i]-'a'] != substring) return false;
            }
            else if (word_to_char.find(substring) != word_to_char.end()){
                if (word_to_char[substring] != pattern[i]) return false;
            }
            else {
                char_to_word[pattern[i]-'a'] = substring;
                word_to_char[substring] = pattern[i];
            }
            i++;
        }
        return i == pattern.length();
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    bool ret = sol.wordPattern("aaa", "aa aa aa aa");
    cout << ret << endl;
    return 0;
}