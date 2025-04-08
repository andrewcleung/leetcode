#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ret;

        vector<int> maxFreq(26, 0);
        for (auto& w2: words2){
            vector<int> freq(26, 0);
            for (auto& w2c: w2){
                freq[w2c - 'a']++;
            }
            for (int i = 0; i < 26; i++){
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }
        
        for (auto& w1 : words1){
            vector<int> mp(26, 0);
            bool isValid = true;
            for (auto& w1c: w1){
                mp[w1c - 'a'] += 1;
            }
            for (int i = 0; i< 26; i++){
                if (mp[i] < maxFreq[i]) {
                    isValid = false;
                    break;
                }
            }
            if (isValid){
                ret.push_back(w1);
            }
        }
        return ret;
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    vector<string> ret;
    vector<string> words1 = {"amazon","apple","facebook","google","leetcode"};
    vector<string> words2 = {"e","o"};
    
    ret = sol.wordSubsets(words1, words2);

    for (auto w: ret){
        cout << w << endl;
    }

    return 0;
}