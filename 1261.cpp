#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements
{
private:
    void recover(TreeNode *node, int val)
    {
        node->val = val;
        if (node->left)
            recover(node->left, 2 * val + 1);
        if (node->right)
            recover(node->right, 2 * val + 2);
    }

    TreeNode* recursiveFind(int target){
        if (target == 0) return root;
        bool isOdd = target % 2;
        TreeNode* ret;
        if (isOdd){
            ret = recursiveFind((target-1)/2);
            if (ret) ret = ret->left;
        }
        else {
            ret = recursiveFind((target-2)/2);
            if (ret) ret = ret->right;
        }
        return ret;
    }

public:
    TreeNode *root;
    FindElements(TreeNode *root) : root(root)
    {
        recover(root, 0);
    }

    bool find(int target)
    {
        return recursiveFind(target) != nullptr;
    }
};
int main(int argc, char **argv)
{
    return 0;
}