#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int n = citations.size();
        vector<int> ps(1001, 0);

        for (auto& i : citations){
            ps[i]++;
        }
        for (int i = 1; i < 1001; i++){
            ps[1000-i] + ps[1000-i+1];
        }

        for (int i = 0; i < 1001; i++){
            if (ps[1000-i]>= 1000-i) return 1000-i;
        }
        return 0;
    }
};

int main(int argc, char** argv) {
  return 0;
}