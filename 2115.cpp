#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>



using namespace std;

class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
    {
        unordered_set<string> supplySet(supplies.begin(), supplies.end());
        unordered_map<string, vector<int>> adjList;
        vector<int> inDeg(recipes.size(), 0);

        for (int i = 0; i < recipes.size(); i++){
            for (auto& ing: ingredients[i]){
                if (!supplySet.count(ing)){
                    inDeg[i]++;
                    adjList[ing].push_back(i);
                }
            }
        }

        queue<int> q;
        vector<string> ret;

        for (int i = 0; i < inDeg.size(); i++){
            if (inDeg[i] == 0) q.push(i);
        }

        while (!q.empty()){
            int cur = q.front();
            q.pop();
            ret.push_back(recipes[cur]);

            for (auto& r : adjList[recipes[cur]]){
                if (--inDeg[r] == 0) q.push(r);
            }
        }
        return ret;
    }
};
int main(int argc, char **argv)
{
    return 0;
}