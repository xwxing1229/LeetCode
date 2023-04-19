// https://leetcode.cn/problems/maximum-difference-between-node-and-ancestor/

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
    int maxAncestorDiff(TreeNode* root) {
        res = 0;
        dfs(root, root->val, root->val);
        return res;
    }

    void dfs(TreeNode *node, int low, int high) {
        low = min(low, node->val);
        high = max(high, node->val);
        res = max(res, high - low);

        if (node->left) {
            dfs(node->left, low, high);
        }
        if (node->right) {
            dfs(node->right, low, high);
        }
    }

    int res;
};