#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);

        for (auto& c: magazine){
            freq[c - 'a'] += 1;
        }

        for (auto& c: ransomNote){
            if (freq[c-'a'] == 0) return false;
            freq[c - 'a'] -= 1;
        }
        return true;
    }
};

int main(int argc, char** argv){
    return 0;
}