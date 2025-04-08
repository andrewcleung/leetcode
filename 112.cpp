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

class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return root ? isSum(root, targetSum, 0) : false;
    }

    bool isSum(TreeNode* curr, int targetSum, int acc){
        if (!curr->left && !curr->right) return (acc + curr->val) == targetSum;

        bool ret = false;
        ret = curr->left ? isSum(curr->left, targetSum, acc + curr->val): ret;
        // stop early
        if (ret) return ret;
        ret |= curr->right ? isSum(curr->right, targetSum, acc+curr->val) : ret;
        return ret;
    }
};

int main(int argc, char **argv)
{

    return 0;
}