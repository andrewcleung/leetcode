#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = __builtin_popcount(num2);
        bitset<32> n1(num1);
        bitset<32> ret;
        for (int i = 31; i >=0; i--){
            if (cnt == 0) break;
            if (n1[i] == 0b1) {
                ret[i] = 0b1;
                cnt--;
            }
        }
        int j = 0;
        while (cnt > 0){
            if (ret[j] == 0b1) {
                j++;
                continue;
            }
            ret[j++] = 0b1;
            cnt--;
        }
        int intret = ret.to_ulong();
        return intret;
    }
};

int main(int argc, char** argv){
    Solution sol;
    int ret = sol.minimizeXor(25,72);
    cout << ret  << endl;
    return 0;
}