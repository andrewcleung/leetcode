#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool doesValidArrayExist(vector<int> &derived)
    {
        int n = derived.size();
        int last = derived[n-1];
        int acc = 0;
        for (int i = 0; i < n - 1; i++){
            acc ^= derived[i];
        }
        return acc == last;
    }
};

int main(int argc, char **argv)
{

    return 0;
}