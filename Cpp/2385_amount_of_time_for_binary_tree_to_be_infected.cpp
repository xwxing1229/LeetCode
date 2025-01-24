// https://leetcode.cn/problems/amount-of-time-for-binary-tree-to-be-infected/

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
    int amountOfTime(TreeNode* root, int start) {
        dfs(root);

        int res = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(start, 0));
        unordered_set<int> visited;
        visited.insert(start);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int cur_val = cur.first;
            res = cur.second;
            for (int val: graph_[cur_val]) {
                if (visited.find(val) == visited.end()) {
                    q.push(make_pair(val, res+1));
                    visited.insert(val);
                }
            }
        }
        return res;
    }

    void dfs(TreeNode *node) {
        if (node->left != nullptr) {
            graph_[node->val].push_back(node->left->val);
            graph_[node->left->val].push_back(node->val);
            dfs(node->left);
        }
        if (node->right != nullptr) {
            graph_[node->val].push_back(node->right->val);
            graph_[node->right->val].push_back(node->val);
            dfs(node->right);
        }
    }

    unordered_map<int, vector<int>> graph_;
};