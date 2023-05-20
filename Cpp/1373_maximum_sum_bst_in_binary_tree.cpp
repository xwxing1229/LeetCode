// https://leetcode.cn/problems/maximum-sum-bst-in-binary-tree/

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
    int maxSumBST(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }

private:
    tuple<int, int, int> dfs(TreeNode *node) {
        if (node == nullptr) {
            return {INT_MAX, INT_MIN, 0};
        }

        auto [left_min, left_max, left_sum] = dfs(node->left);
        auto [right_min, right_max, right_sum] = dfs(node->right);
        int x = node->val;
        if (x <= left_max || x >= right_min) {
            return {INT_MIN, INT_MAX, 0};
        }

        int s = left_sum + right_sum + x;
        res = max(res, s);

        return {min(left_min, x), max(right_max, x), s};
    }

    int res;
};