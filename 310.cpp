#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> deg(n, 0);
        vector<unordered_set<int>> adjList(n);
        if (n == 2) return {0, 1};
        if (n == 1) return {0};

        for (auto& edge : edges) {
            adjList[edge[0]].insert(edge[1]);
            adjList[edge[1]].insert(edge[0]);
        }

        vector<int> leaves;
        vector<int> ret;
        int remainingNodes = n;

        for (int i = 0; i < n; i++){
            if (adjList[i].size() == 1) leaves.push_back(i);
        }

        while (remainingNodes > 2){
            remainingNodes -= leaves.size();
            vector<int> newLeaves;
            for (auto& leaf : leaves){
                int ne = *(adjList[leaf].begin());
                adjList[ne].erase(leaf);
                if (adjList[ne].size() == 1) newLeaves.push_back(ne);
            }
            leaves = newLeaves;
        }

    }
};

int main(int argc, char** argv) {
  return 0;
}