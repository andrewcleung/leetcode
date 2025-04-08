#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
        // create a deep copy of the vector
        bool visited[101] = {false};
        Node *nodePtr[101] = {nullptr};


        queue<pair<Node *, Node *>> bfs;
        Node *newRoot = new Node(node->val);
        visited[node->val] = true;
        nodePtr[node->val] = newRoot;
        bfs.push({node, newRoot});

        while (!bfs.empty())
        {
            auto [orgNode, newNode] = bfs.front();
            bfs.pop();
            // copy the neigbors
            for (auto &n : orgNode->neighbors)
            {
                Node *newNeighbor;
                if (!nodePtr[n->val])
                {
                    newNeighbor = new Node(n->val);
                    nodePtr[n->val] = newNeighbor;
                }
                else
                    newNeighbor = nodePtr[n->val];
                newNode->neighbors.push_back(newNeighbor);
                if (!visited[n->val]){
                    visited[orgNode->val] = true;
                    bfs.push({n, newNeighbor});
                }
            }
        }
        return newRoot;
    }
};

int main(int argc, char **argv)
{

    return 0;
}