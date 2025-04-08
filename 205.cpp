#include <iostream>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> hts;
        unordered_map<char, char> htt;

        for (int i = 0; i < s.length(); i++)
        {
            if (hts.find(s[i]) == hts.end())
                hts[s[i]] = t[i];
            if (hts[s[i]] != t[i])
                return false;
            if (htt.find(t[i]) == htt.end())
                htt[t[i]] = s[i];
            if (htt[t[i]] != s[i])
                return false;
        }
        return true;
    }
};

int main(int argc, char **argv)
{

    return 0;
}