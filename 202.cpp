#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hs;

        int currN = n;
        while(1){
            int currSum = 0;
            while(currN>0){
                int dig = currN % 10;
                currN = currN / 10; // 501 -> 50
                currSum += dig * dig;
            }
            if (currSum == 1) return true;
            if (hs.count(currSum)) break;
            hs.insert(currSum);
            currN = currSum;
        }
        return false;
    }
};

int main(int argc, char** argv){

  return 0;
}