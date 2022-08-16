// https://leetcode.cn/problems/house-robber-iii/

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
    int rob(TreeNode* root) {
        dfs(root);
        return max(dp_c[root], dp_n[root]);
    }

private:
    void dfs(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        dfs(node->left);
        dfs(node->right);

        dp_c[node] = node->val + dp_n[node->left] + dp_n[node->right];
        dp_n[node] = max(dp_c[node->left], dp_n[node->left]) +
            max(dp_c[node->right], dp_n[node->right]);
    }

    // dp_c: this node is chosen
    // dp_n: this node is not chosen
    unordered_map<TreeNode*, int> dp_c, dp_n;
};