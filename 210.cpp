
#include <iostream>

using namespace std;
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> inDeg(numCourses, 0);
        vector<vector<int>> adjList(numCourses);

        for (auto& p: prerequisites){
            inDeg[p[0]]++;
            adjList[p[1]].push_back(p[0]);
        }
        vector<int> ret;
        queue<int> q;

        for (int i = 0; i < numCourses; i++){
            if (inDeg[i] == 0) q.push(i);
        }

        while (!q.empty()){
            int cur = q.front();
            q.pop();
            ret.push_back(cur);
            for (auto& i : adjList[cur]){
                if (--inDeg[i] == 0) q.push(i);
            }
        }
        if (ret.size() != numCourses) return {};
        return ret;
    }
};
int main(int argc, char** argv) {
  return 0;
}