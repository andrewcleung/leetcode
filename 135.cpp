#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        vector<int> left(n, 1), right(n, 1);
        
        // Left-to-right: ensure right child gets more if rating is higher than left
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1])
                left[i] = left[i - 1] + 1;
        }
        
        // Right-to-left: ensure left child gets more if rating is higher than right
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1])
                right[i] = right[i + 1] + 1;
        }
        
        int totalCandies = 0;
        for (int i = 0; i < n; i++) {
            totalCandies += max(left[i], right[i]);
        }
        
        return totalCandies;
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    vector<int> input = {1,3,2,2,1};
    sol.candy(input);
    return 0;
}