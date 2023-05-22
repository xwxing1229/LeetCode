// https://leetcode.cn/problems/insufficient-nodes-in-root-to-leaf-paths/

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
class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        bool root_delete = dfs(root, 0, limit);
        if (root_delete) {
            return nullptr;
        }
        return root;
    }

    bool dfs(TreeNode *node, int s, int limit) {
        if (node->left == nullptr && node->right == nullptr) {
            return s + node->val < limit;
        }
        bool left_delete = true, right_delete = true;
        if (node->left != nullptr) {
            left_delete = dfs(node->left, s+node->val, limit);
        }
        if (node->right != nullptr) {
            right_delete = dfs(node->right, s+node->val, limit);
        }
        if (left_delete) {
            node->left = nullptr;
        }
        if (right_delete) {
            node->right = nullptr;
        }
        return left_delete && right_delete;
    }
};
