// https://leetcode.cn/problems/kth-largest-sum-in-a-binary-tree/

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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        vector<long long> levelsum;
        while (!q.empty()) {
            long long s = 0;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode *node = q.front();
                q.pop();
                s += node->val;
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            levelsum.push_back(s);
        }
        sort(levelsum.begin(), levelsum.end(), greater<long long>());
        if (levelsum.size() >= k) return levelsum[k-1];
        else return -1;
    }
};