// https://leetcode.cn/problems/validate-binary-search-tree/

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
    bool isValidBST(TreeNode* root) {
        res = true;
        check(root, LONG_MIN, LONG_MAX);
        return res;
    }

    bool check(TreeNode *node, long min_, long max_) {
        if (!res) return false;
        if (node == nullptr) return true;

        int x = node->val;
        if (x <= min_ || x >= max_) {
            res = false;
            return false;
        }

        return check(node->left, min_, x) && check(node->right, x, max_);
    }

    bool res;
};