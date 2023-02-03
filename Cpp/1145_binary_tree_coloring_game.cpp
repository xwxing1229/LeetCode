// https://leetcode.cn/problems/binary-tree-coloring-game/

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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode  *x_node = findNode(root, x);
        int left_size = getSubtreeSize(x_node->left);
        if (left_size >= (n+1)/2) return true;
        int right_size = getSubtreeSize(x_node->right);
        if (right_size >= (n+1)/2) return true;
        if (n - 1 - left_size - right_size >= (n+1)/2) return true;
        return false;
    }

    TreeNode* findNode(TreeNode* node, int x) {
        if (node == NULL) return NULL;
        if (node->val == x) return node;

        TreeNode *res = findNode(node->left, x);
        if (res != NULL) return res;
        else return findNode(node->right, x);
    }

    int getSubtreeSize(TreeNode* node) {
        if (node == NULL) return 0;
        return 1 + getSubtreeSize(node->left) + getSubtreeSize(node->right);
    }
};