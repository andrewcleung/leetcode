#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (auto &c: s){
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            else {
                if (st.empty()) return false;
                char p = st.top();
                
                if (c == ')' && p != '(') return false; 
                if (c == '}' && p != '{') return false; 
                if (c == ']' && p != '[') return false; 
                st.pop();
            }
        }
        return st.empty();

    }
};
int main(int argc, char **argv)
{
    return 0;
}