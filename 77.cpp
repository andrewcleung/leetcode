#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ret;
        vector<int> curr;
        backtrack(ret, curr, 1, n, k);
        return ret;
    }
    void backtrack(vector<vector<int>> &ret, vector<int> &curr, int start, int n, int k){
        if (curr.size() == k) {
            ret.push_back(curr);
            return;
        }
        if (start>n) return;

        for (int i = start; i <= n; i++){
            curr.push_back(i);
            backtrack(ret, curr, i+1, n, k);
            curr.pop_back();
        }
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    
    vector<vector<int>> ret = sol.combine(4, 2);
    for (int i = 0; i < ret.size(); i++){
        cout << "vector: ";
        for (auto j: ret[i]){
            cout << j << ' ';
        }
        cout << endl;
    }
    return 0;
}