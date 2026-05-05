// https://leetcode.cn/problems/sum-of-root-to-leaf-binary-numbers/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;

        auto dfs = [&res](auto &&self, TreeNode *node, int val) -> void {
            if ((!node->left) && (!node->right)) {
                res += val;
            }
            if (node->left) {
                self(self, node->left, (val<<1)+node->left->val);
            }
            if (node->right) {
                self(self, node->right, (val<<1)+node->right->val);
            }
        };

        dfs(dfs, root, root->val);
        return res;
    }
};