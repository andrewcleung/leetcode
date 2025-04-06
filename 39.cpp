#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    // recursive approach using back tracking
    // choices : include the number in the curr sol set, or exclude it
    // keep track of the curr sol set sum
    // return if it equals to the target
    // prune if it is larger than the target
    void bt(vector<int>& candidates, int target, int index, vector<int> &currSet, vector<vector<int>> &ret){
        if (target == 0) {
            ret.push_back(currSet);
            return;
        } else if (index == candidates.size() || target < 0){
            return;
        }

        for (int i = index; i < candidates.size(); i++){
            int newTarget = target - candidates[i];
            // if adding the number will exceed the target, then the number that comes after it must also exceed the sum
            if (newTarget < 0) break;
            currSet.push_back(candidates[i]);
            bt(candidates, newTarget, i, currSet, ret);
            currSet.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // reserve currSet to avoid overhead of constantly pushing and popping
        sort(candidates.begin(), candidates.end());
        vector<int> currSet;
        vector<vector<int>> ret;
        bt(candidates, target, 0, currSet, ret);
        return ret;
    }
};
int main(int argc, char** argv) {
    Solution sol;
    vector<int> input = {2,3,6,7};
    vector<vector<int>> ret = sol.combinationSum(input, 7);
    cout << "hi" << endl;
    for (auto i : ret){
        for (auto ii : i){
            cout << ii << " ";
        }
        cout  << endl;
    }
    return 0;
}