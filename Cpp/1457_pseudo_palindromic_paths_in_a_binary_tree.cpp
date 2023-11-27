// https://leetcode.cn/problems/pseudo-palindromic-paths-in-a-binary-tree/

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
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> cnts(10, 0);
        return dfs(root, cnts);
    }

    int dfs(TreeNode *node, vector<int> &cnts) {
        if (node == nullptr) {
            return 0;
        }
        cnts[node->val] = 1 - cnts[node->val];
        int res = 0;
        if (node->left == nullptr && node->right == nullptr) {
            int s = 0;
            for (auto cnt: cnts) {
                s += cnt;
            }
            if (s <= 1) {
                res = 1;
            }
        }
        else {
            res = dfs(node->left, cnts) + dfs(node->right, cnts);
        }
        cnts[node->val] = 1 - cnts[node->val];

        return res;
    }
};