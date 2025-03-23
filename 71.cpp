#include <iostream>
#include <stack>
#include <string>

using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int parCnt = 0;
        string s = "";
        for (auto& c : path) {
            if (c == '/') {
                if (s != "") {
                    st.push(s);
                    s = "";
                }
                continue;
            }
            s += c;
        }
        if (!s.empty()) st.push(s);
        string ret = "";
        while (!st.empty()) {
            string cur = st.top();
            st.pop();
            if (cur == ".")
                continue;
            if (cur == "..") {
                parCnt++;
                continue;
            }
            if (parCnt > 0) {
                parCnt--; 
                continue;
            }
            ret = ret == "" ? cur : cur + "/" + ret;
        }
        return "/" + ret;
    }
};


int main(int argc, char **argv)
{
    return 0;
}