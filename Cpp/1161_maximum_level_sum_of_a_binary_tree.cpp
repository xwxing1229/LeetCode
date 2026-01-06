// https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree/

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

#include <deque>

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
    int maxLevelSum(TreeNode* root) {
        int res = 1, depth = 1;
        long s_max = root->val;
        deque<TreeNode*> q;
        q.push_back(root);
        while (!q.empty()) {
            int n = q.size();
            long s_curr = 0;
            for (int i = 0; i < n; ++i) {
                auto node = q.front();
                q.pop_front();
                s_curr += node->val;
                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
            }
            if (s_curr > s_max) {
                res = depth;
                s_max = s_curr;
            }
            depth += 1;
        }
        return res;
    }
};