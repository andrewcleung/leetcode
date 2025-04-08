#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        int buyIndex = 0;
        int maxPrice = 0;

        for (int sellIndex = 0; sellIndex < n; sellIndex++){
            maxPrice = max(prices[sellIndex] - prices[buyIndex], maxPrice);
            if (prices[sellIndex] < prices[buyIndex] ) buyIndex = sellIndex;
        }
        return maxPrice;
    }
};

int main(int argc, char **argv)
{

    return 0;
}