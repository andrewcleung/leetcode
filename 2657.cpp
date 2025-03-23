#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<bool> hta(n, 0);
        vector<bool> htb(n, 0);
        vector<int> ret(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++){
            hta[A[i]] = 1;
            htb[B[i]] = 1;
            if (A[i] == B[i]) cnt++;
            else {
                if (hta[B[i]]) cnt++;
                if (htb[A[i]]) cnt++;
            }
            ret[i] = cnt;
        }
        return ret;
    }
};

int main(int argc, char **argv)
{
    vector<int> A = {5,6,7};
    vector<int> B = {3,1,2};
    Solution sol;
    vector<int> ret = sol.findThePrefixCommonArray(A, B);
    for (auto ii : ret){
        cout << ii << endl;
    }
    return 0;
}