#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int p1 = 0;
        int p2 = 1;
        int maxProfit = 0;
        int profit = 0;

        while (p2 < n){
            if (prices[p2] < prices[p2-1]){
                maxProfit += profit;
                profit = INT_MIN;
                p1 = p2;
            }
            profit=max(prices[p2]-prices[p1], profit);
            p2++;
        }
        maxProfit += profit;
        return maxProfit;
    }
};

int main(int argc, char **argv)
{
    Solution solution;
    vector<vector<int>> inputs = { {7,1,5,3,6,4},
                            {1,2,3,4,5},
                            {5,4,3,2,1} };
    vector<int> expected = {7, 4, 0};

    for (int i = 0; i < inputs.size(); i++) {
        int ret = solution.maxProfit(inputs[i]);
        cout << "ret = " << ret << endl;

        if (ret != expected[i]){
            cout << "Test " << i << "failed" << endl;
        } else {
            cout << "Test " << i << "passed" << endl;
        }
    }
    return 0;
}