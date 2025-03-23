#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class UnionFind
{
public:
    vector<int> parent;
    vector<int> size;
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
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        UnionFind uf(n);
        vector<int> numEdge(n,0);
        for (auto &edge : edges)
        {
            int a = uf.find(edge[0]);
            int b = uf.find(edge[1]);
            if (a != b) {
                uf.union_set(edge[0], edge[1]);
                numEdge[uf.find(edge[0])] = numEdge[a] + numEdge[b] + 1;
            }
            else {
                numEdge[a]++;
            }
        }

        int ret = 0;
        for (int i = 0; i < n; i++){
            if (i == uf.find(i) && numEdge[i] == (uf.size[i] * (uf.size[i]-1) / 2)) ret++;
        }
        return ret;
    }
};
int main(int argc, char **argv)
{
    return 0;
}