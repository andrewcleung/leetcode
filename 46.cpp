#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool solve(vector<vector<int>> &sol, vector<int> &curr, vector<bool> &visited, vector<int> &nums){
        if (curr.size() == nums.size()){
            return true;
        }

        for (auto i: nums){
            if (!visited[i]){
                visited[i] = true;
                curr.push_back(i);
                if (solve(sol, curr, visited, nums)){
                    sol.push_back(curr);
                }
                curr.pop_back();
                visited[i] = false;
            }
        }
        return false;
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> visited (21,false);
        vector<int> curr = {};
        vector<vector<int>> ret;
        solve(ret, curr, visited, nums);
        return ret;
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    vector<int> input = {1,2,3};
    vector<vector<int>> ret = sol.permute(input);
    for (int i = 0; i < ret.size(); i++){
        cout << "vector: ";
        for (auto j : ret[i]){
            cout << j;
        }
        cout << endl;
    }
    return 0;
}