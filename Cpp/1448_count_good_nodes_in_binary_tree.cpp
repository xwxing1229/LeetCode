// https://leetcode.cn/problems/count-good-nodes-in-binary-tree/

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
    int goodNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return check(root, root->val);
    }

    int check(TreeNode *node, int cur_max) {
        if (node == nullptr) {
            return 0;
        }
        int val = node->val;
        if (val >= cur_max) {
            return 1 + check(node->left, val) + check(node->right, val);
        }
        else {
            return check(node->left, cur_max) + check(node->right, cur_max);
        }
    }
};