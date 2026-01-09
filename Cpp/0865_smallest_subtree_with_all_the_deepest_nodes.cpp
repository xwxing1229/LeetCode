// https://leetcode.cn/problems/smallest-subtree-with-all-the-deepest-nodes/

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

#include <algorithm>
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
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode *res = nullptr;
        int depth_max = -1;

        auto dfs = [&](auto &&self, TreeNode *node, int depth) -> int {
            if (node == nullptr) {
                depth_max = max(depth_max, depth);
                return depth;
            }

            int left_depth_max = self(self, node->left, depth+1);
            int right_depth_max = self(self, node->right, depth+1);
            if (left_depth_max == right_depth_max && left_depth_max == depth_max) {
                res = node;
            }
            return max(left_depth_max, right_depth_max);
        };

        dfs(dfs, root, 0);
        return res;
    }
};