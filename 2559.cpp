#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ps;
        vector<int> ret;
        for (auto & w: words){
            auto s1 = vowels.find(w[0]);
            auto s2 = vowels.find(w[w.length()-1]);
            int last = ps.empty() ? 0 :  ps.back();
            if (s1 != vowels.end() && s2 != vowels.end()){
                ps.push_back(last + 1);
            }
            else {
                ps.push_back(last);
            }
        }
        for (auto& q : queries){
            int r = ps[q[1]];
            int l = q[0] == 0 ? 0 : ps[q[0] - 1]; 
            ret.push_back(r - l);
        }
        return ret;
    }
private:
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
};

int main(int argc, char** argv){
    Solution solution;
    vector<string> words = {"aba","bcb","ece","aa","e"};
    vector<vector<int>> queries = {{0,2},{1,4},{1,1}};
    vector<int> ret = solution.vowelStrings(words, queries);
    for (auto & i : ret){
        cout << i << ',';
    }
    cout << endl;
    return 0;
}
