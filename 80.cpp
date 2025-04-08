#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int a = 2;
       int n = nums.size();
       if (n < 3) return n;
       for (int i = 2; i < n; i++)
       {
           if (nums[a - 2] != nums[i])
           {
               nums[a++] = nums[i];
           }
       }
       return a;
    }
};

int main(int argc, char** argv){
    Solution solution;
    vector<int> input = {1,1,2,2,3};
    int k = solution.removeDuplicates(input);
    cout << k << endl;

    for (int i = 0; i < k; i++){
        cout << input[i] << ',';
    }
    cout << endl;

    return 0;
}