#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UnionFind
{
private:
    vector<int> parent;
    vector<int> size;
public:
    UnionFind(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int i){
        if (i == parent[i]) return i;
        parent[i] = find(parent[i]);
        return parent[i];
    }


    void union_set(int a, int b){
        a = find(a);
        b = find(b);

        if (a != b){
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

class Solution
{
public:
    vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &query)
    {
        UnionFind uf(n);
        int qn = query.size();
        vector<int> ret(qn);
        vector<unsigned int> cost(n, -1);

        for (auto& e: edges){
            uf.union_set(e[0], e[1]);
        }
        for (auto& e: edges){
            int root = uf.find(e[0]);
            cost[root] &= e[2];
        }

        for (int i = 0; i < qn; i++){
            auto& q = query[i];
            int a = uf.find(q[0]);
            int b = uf.find(q[1]);
            if (a != b) ret[i] = -1;
            else {
                ret[i] =  cost[a];
            }
        }
        return ret;
    }
};


int
main(int argc, char **argv)
{
    return 0;
}