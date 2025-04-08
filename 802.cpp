#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int numNodes = graph.size();

        vector<bool> isSafe(numNodes, true);
        vector<int> ret;

        for (int i = 0; i < numNodes; i++){
            vector<bool> visited(numNodes, false);
            if(dfs(i, graph, visited, isSafe)) ret.push_back(i);
        }

        return ret;
    }

    bool dfs(int node, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &cache){
        if (!cache[node]){
            cout << "I am here" <<endl;
        }
        if (visited[node]){
            cout << node << endl;
            cout << "I am hersse" <<endl;
        }
        if (!cache[node] || visited[node]) return false;
        bool ret = true;
        visited[node] = true;
        for (auto& nextNode : graph[node]){
            ret &= dfs(nextNode, graph, visited, cache);
        }
        if (!ret) {
            for (int i = 0; i < visited.size(); i++){
                cache[i] = cache[i] | !visited[i];
            }
        }
        return ret;
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    vector<vector<int>> input = {{},{0,2,3,4},{3},{4},{}};
    sol.eventualSafeNodes(input);

    return 0;
}