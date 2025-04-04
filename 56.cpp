#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end());
        ret.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++){
            if (intervals[i][0] <= ret.back()[1]){
                ret.back()[1] = max(ret.back()[1], intervals[i][1]);
            }
            else {
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
};
int main(int argc, char **argv)
{
    Solution sol;

    vector<vector<int>> input = {{2,3}, {4,6}, {2,8}, {1,10}, {2,9}, {10,20}};
    vector<vector<int>> out = sol.merge(input);
    for(auto ii: out){
        for(auto i: ii){

            cout<< i << " ";
        }
        cout << endl;
    }
    return 0;
}