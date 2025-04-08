#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        sort(meetings.begin(), meetings.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0] < b[0];
        });
        int ret = days;
        vector<vector<int>> merged;
        merged.push_back(meetings[0]);
        for (int i = 1; i < meetings.size(); i++){
            if (merged.back()[1] >= meetings[i][0]){
                merged.back()[1] = max(meetings[i][1], merged.back()[1]);
            }
            else {
                merged.push_back(meetings[i]);
            }
        }
        for (auto& interval: merged){
            ret -= interval[1] - interval[0] + 1;
        }
        return ret;
    }
};
int main(int argc, char **argv)
{

    return 0;
}