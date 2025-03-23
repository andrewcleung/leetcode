
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> inDeg(numCourses, 0);
        vector<vector<int>> adjList(numCourses);

        for (auto& p: prerequisites){
            inDeg[p[0]]++;
            adjList[p[1]].push_back(p[0]);
        }
        int count = 0;
        queue<int> q;

        for (int i = 0; i < numCourses; i++){
            if (inDeg[i] == 0) q.push(i);
        }

        while (!q.empty()){
            count++;
            int cur = q.front();
            q.pop();
            for (auto& i : adjList[cur]){
                if (--inDeg[i] == 0) q.push(i);
            }
        }
        return count == numCourses;
    }
};

int main(int argc, char **argv)
{
    return 0;
}