#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    bool isValid(TreeNode* left, TreeNode* right) {
        if (left && !right) return false;
        if (right && !left) return false;
        if (!left && !right) return true;
        if (left->val != right->val) return false;
        if (!left->left && !left->right && !right->left && !right->right) return true;

        return isValid(left->left, right->right) & isValid(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isValid(root->left, root->right);
    }
};

int main(int argc, char** argv){

  return 0;
}