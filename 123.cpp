#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = 0;
        right[n-1] = 0;

        int buy1 = prices[0];
        int sell2 = prices[n-1];

        for (int i = 1, j = n - 2; i < n, j >= 0; i++, j--){
            buy1 = min(prices[i], buy1);
            left[i] = max(left[i-1], prices[i]- buy1);
            sell2 = max(prices[i], sell2);
            right[i] = min(right[i+1], sell2 - prices[i]);
        }

        int ret;
        for (int i = 0; i < n; i++){
            ret = max(ret, left[i] + right[i]);
        }
        return ret;
    }
};

int main(int argc, char **argv)
{
    return 0;
}