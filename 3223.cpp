#include <iostream>
#include <array>

using namespace std;

class Solution
{
public:
    int minimumLength(string s)
    {
        array<int, 26> ht = {0};
        for (char& c: s){
            ht[c-'a']++;
        }
        int ret = 0;
        for (int i = 0; i < 26; i++){
            ret += (ht[i] % 2 ? 1 : (ht[i] ? 2 : 0));
        }
        return ret;
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    int ret = sol.minimumLength("aa");
    cout << ret << endl;
    return 0;
}