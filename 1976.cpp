#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<long long> travelTime(n, INT64_MAX);
        vector<vector<pair<int, int>>> adjList(n);

        for (auto &rr : roads)
        {
            int w = rr[2];
            adjList[rr[0]].push_back({rr[1], w});
            adjList[rr[1]].push_back({rr[0], w});
        }

        priority_queue <pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        travelTime[0] = 0;
        vector<int> ways(n);
        ways[0] = 1;
        while (!pq.empty())
        {
            auto [dist, curr] = pq.top();
            pq.pop();

            if (dist > travelTime[curr]) continue;

            for (auto neis : adjList[curr])
            {
                auto [nei, weight] = neis;
                long long newDist = travelTime[curr] + weight;
                if (newDist < travelTime[nei]){
                    travelTime[nei] = newDist;
                    ways[nei] = ways[curr];
                    pq.push({newDist, nei});
                }
                else if (newDist == travelTime[nei]){
                    ways[nei] = (ways[nei] + ways[curr]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};

int main(int argc, char **argv)
{
    return 0;
}