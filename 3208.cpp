#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        int ret = 0, n = colors.size();

        for (int start = 0;start < n; start++){
            bool val = true;
            int curr = colors[start];
            for (int i = 1; i < k; i++){
                curr = !curr;
                int index = (start + i)%n;
                if (curr != colors[index]) {
                    if (index > start) start = index-1;
                    else start = n;
                    val = false;
                    break;
                }
            }
            ret = val ? ret + 1 :  ret;
        }
        return ret;
    }
};

int main(int argc, char **argv)
{
    return 0;
}